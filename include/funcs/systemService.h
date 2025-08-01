#ifndef SYSTEMSERVICE_H
#define SYSTEMSERVICE_H

#pragma once // Garante que o arquivo é incluído apenas uma vez
#include "classes/Local.h" // Inclui a classe Local
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include "database/repositorio.h"
#include <vector>
#include <string>
#include <fstream>

/**
 * @brief Salva o estado atual do repositório em um arquivo binário.
 * 
 * @param repo Referência para o repositório de dados.
 * @details Esta função salva todos os dados do repositório, incluindo locais, veículos e pedidos,
 */
void salvarDB(Repositorio& repo) {
    repo.salvarBinario("include/database/database.bin");
}

/**
 * @brief Carrega o estado do repositório a partir de um arquivo binário.
 * 
 * @param repo Referência para o repositório de dados.
 * @details Esta função carrega os dados do repositório a partir de um arquivo binário previamente salvo.
 *          Ela deve ser chamada no início do programa para garantir que os dados persistam entre as execuções.
 */
void carregarDB(Repositorio& repo) {
    repo.carregarBinario("include/database/database.bin");
}

/**
 * @brief Calcula a distância entre dois locais.
 * 
 * @param l1 Primeiro local.
 * @param l2 Segundo local.
 * @return double Distância entre os dois locais.
 */
double calcularDistancia(const Local& l1, const Local& l2) {
    // Implementa a lógica de cálculo de distância entre dois locais
    // Exemplo: usando a fórmula da distância euclidiana
    double distancia = sqrt(pow(l2.getCoordenadaX() - l1.getCoordenadaX(), 2) +
                            pow(l2.getCoordenadaY() - l1.getCoordenadaY(), 2));
    return distancia;
}

/**
 * @brief Seleciona o veículo disponível mais próximo da origem do pedido.
 * 
 * @param repo Referência para o repositório de dados.
 * @param origem Local de origem do pedido.
 * @return Veiculo* Ponteiro para o veículo selecionado ou nullptr se nenhum disponível.
 */
Veiculo * selecionarVeiculo(Repositorio& repo, const Local& origem) {
    VeiculoService veiculoService(&repo);
    Veiculo* veiculoSelecionado = nullptr;
    double menorDistancia = std::numeric_limits<double>::max();

    for (auto veiculo : veiculoService.listarVeiculos()) {
        if (veiculo.getStatus()) { // Verifica se o veículo está disponível
            double distancia = calcularDistancia(origem, veiculo.getLocal());
            if (distancia == 0) {
                veiculoSelecionado = &veiculo; // Veículo já está na origem
                break; // Não precisa procurar mais, já encontrou o veículo mais próximo
            }
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                veiculoSelecionado = &veiculo;
            }
        }
    }

    if (veiculoSelecionado) {
        veiculoSelecionado->setStatus(false); // Marca o veículo como ocupado
        repo.updateVeiculo(*veiculoSelecionado);
    } else {
        std::cout << "Nenhum veículo disponível encontrado." << std::endl;
    }
    return veiculoSelecionado;
}

/**
 * @brief Calcula a distância total da rota de entrega de um pedido.
 * 
 * @param veiculoSelecionado Veículo que fará a entrega.
 * @param pedido Pedido a ser entregue.
 * @return double Distância total (origem do veículo até origem do pedido + origem até destino).
 */
double calcularRota(const Veiculo& veiculoSelecionado, const Pedido& pedido) {
    double distanciaOrigem = calcularDistancia(veiculoSelecionado.getLocal(), pedido.getOrigem());
    double distanciaDestino = calcularDistancia(pedido.getOrigem(), pedido.getDestino());
    double distanciaTotal = distanciaOrigem + distanciaDestino;
    return distanciaTotal;
}

/**
 * @brief Finaliza um pedido, atualizando o status do pedido e do veículo, e local atual do veiculo.
 * 
 * @param repo Referência para o repositório de dados.
 * @param pedido Referência para o pedido a ser finalizado.
 * @param veiculo Referência para o veículo que realizou a entrega.
 */
void finalizarPedido(Repositorio& repo, Pedido& pedido, Veiculo& veiculo) {
    PedidoService pedidoService(&repo);
    veiculo.setStatus(true);// Marca o veículo como disponível
    veiculo.setLocal(pedido.getDestino()); // Atualiza a localização do veículo para o destino do pedido
    pedido.setStatus(true); // Marca o pedido como concluído
    pedidoService.atualizarPedido(pedido.getId(), pedido.getOrigem(), pedido.getDestino(), pedido.getPeso());
    repo.updateVeiculo(veiculo);
}

/**
 * @brief Realiza o processo de entrega de um pedido, selecionando o veículo, calculando a rota e finalizando o pedido.
 * 
 * @param repo Referência para o repositório de dados.
 * @param pedido Referência para o pedido a ser entregue.
 */
void realizarEntrega(Repositorio& repo, Pedido& pedido) {
    Veiculo veiculoSelecionado = *selecionarVeiculo(repo, pedido.getOrigem());
    double distanciaTotal = calcularRota(veiculoSelecionado, pedido);
    std::cout << "Veículo selecionado: " << veiculoSelecionado.getModelo() 
              << " (Placa: " << veiculoSelecionado.getPlaca() << ")" << std::endl;
    std::cout << "ID do pedido: " << pedido.getId() << std::endl;
    std::cout << "Detalhes do pedido:" << std::endl;
    std::cout << "Origem: " << pedido.getOrigem().getEndereco().getRua() 
              << ", Destino: " << pedido.getDestino().getEndereco().getRua() << std::endl;
    std::cout << "Peso do pedido: " << pedido.getPeso() << " Kg" << std::endl;
    std::cout << "Distância do veículo até a origem: " 
              << calcularDistancia(veiculoSelecionado.getLocal(), pedido.getOrigem()) << " Km" << std::endl;
    std::cout << "Distância da origem até o destino: " 
              << calcularDistancia(pedido.getOrigem(), pedido.getDestino()) << " Km" << std::endl;
    std::cout << "Distância total da rota: " << distanciaTotal << " Km" << std::endl;

    // Simula a entrega
    std::cout << "Entregando o pedido..." << std::endl;
    finalizarPedido(repo, pedido, const_cast<Veiculo&>(veiculoSelecionado));
    std::cout << "Pedido entregue com sucesso!" << std::endl;
}

#endif // SYSTEMSERVICE_H