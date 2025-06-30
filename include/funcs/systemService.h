#ifndef SYSTEMSERVICE_H
#define SYSTEMSERVICE_H

#pragma once
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include "database/repositorio.h"
#include <vector>
#include <string>
#include <fstream>

void salvarDB(Repositorio& repo) {
    repo.salvarBinario("include/database/database.bin");
}

void carregarDB(Repositorio& repo) {
    repo.carregarBinario("include/database/database.bin");
}

double calcularDistancia(const Local& l1, const Local& l2) {
    // Implementa a lógica de cálculo de distância entre dois locais
    // Exemplo: usando a fórmula da distância euclidiana
    double distancia = sqrt(pow(l2.getCoordenadaX() - l1.getCoordenadaX(), 2) +
                            pow(l2.getCoordenadaY() - l1.getCoordenadaY(), 2));
    return distancia;
}

Veiculo * selecionarVeiculo(Repositorio& repo, const Local& origem) {
    VeiculoService veiculoService(&repo);
    Veiculo* veiculoSelecionado = nullptr;
    double menorDistancia = std::numeric_limits<double>::max();

    for (auto veiculo : veiculoService.listarVeiculos()) {
        if (veiculo.getStatus()) { // Verifica se o veículo está disponível
            double distancia = calcularDistancia(origem, veiculo.getLocal());
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

double calcularRota(const Veiculo& veiculoSelecionado, const Pedido& pedido) {
    double distanciaOrigem = calcularDistancia(veiculoSelecionado.getLocal(), pedido.getOrigem());
    double distanciaDestino = calcularDistancia(pedido.getOrigem(), pedido.getDestino());
    double distanciaTotal = distanciaOrigem + distanciaDestino;
    return distanciaTotal;
}

void finalizarPedido(Repositorio& repo, Pedido& pedido, Veiculo& veiculo) {
    PedidoService pedidoService(&repo);
    veiculo.setStatus(true); // Marca o veículo como disponível
    pedido.setStatus(true); // Marca o pedido como concluído
    pedidoService.atualizarPedido(pedido.getId(), pedido.getOrigem(), pedido.getDestino(), pedido.getPeso());
    repo.updateVeiculo(veiculo);
}

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