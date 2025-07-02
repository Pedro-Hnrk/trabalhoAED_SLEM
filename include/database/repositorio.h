#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#pragma once
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include <vector>
#include <string>
#include <fstream>


/**
 * @class Repositorio
 * @brief Classe responsável por gerenciar os dados do sistema, incluindo locais, veículos e pedidos.
 * 
 * Esta classe fornece métodos para adicionar, atualizar, remover e consultar locais, veículos e pedidos.
 * Os dados são armazenados em vetores e podem ser salvos em um arquivo binário.
 */
class Repositorio {
    std::vector<Local> locais;
    std::vector<Veiculo> veiculos;
    std::vector<Pedido> pedidos;
private:
    int nextLocalId = 0; // Para IDs únicos de locais
    int nextVeiculoId = 0; // Para IDs únicos de veículos
    int nextPedidoId = 0; // Para IDs únicos de pedidos

public:
    // Locais
    /**
     * @brief Gera o próximo ID único para um local.
     * 
     * @return int Próximo ID único para um local.
     */
    int gerarProximoIdLocal() {
        return nextLocalId++;
    }

    /**
     * @brief Adiciona um novo local ao repositório.
     * 
     * @param l Objeto Local a ser adicionado.
     * @return int ID do local adicionado.
     */
    int addLocal(Local l) { 
        l.setId(gerarProximoIdLocal()); 
        locais.push_back(l); 
        return l.getId();
    }
    
    /**
     * @brief Obtém um local pelo ID.
     * 
     * @param id ID do local a ser obtido.
     * @return Local* Ponteiro para o objeto Local, ou nullptr se não encontrado.
     */
    Local* getLocal(int id) {
        for (auto& local : locais) {
            if (local.getId() == id) {
                return &local;
            }
        }
        return nullptr;
    }

    /**
     * @brief Atualiza um local existente no repositório.
     * 
     * @param elemento Objeto Local com os dados atualizados.
     * @throws std::runtime_error Se o local não for encontrado.
     */
    void updateLocal(Local elemento) {
        for (auto& local : locais) {
            if (local.getId() == elemento.getId()) {
                local = elemento;
                return;
            }
        }
        throw std::runtime_error("Local não encontrado");
    }

    /**
     * @brief Remove um local do repositório pelo ID.
     * 
     * @param id ID do local a ser removido.
     * @throws std::runtime_error Se o local não for encontrado.
     */
    void removeLocal(int id)  {
        for (auto it = locais.begin(); it != locais.end(); ++it) {
            if (it->getId() == id) {
                locais.erase(it);
                return;
            }
        }
        throw std::runtime_error("Local não encontrado");
    }

    std::vector<Local> getAllLocal() {
        return locais;
    }

    // Veículos
    /**
     * @brief Gera o próximo ID único para um veículo.
     * 
     * @return int Próximo ID único para um veículo.
     */
    int gerarProximoIdVeiculo() {
        return nextVeiculoId++;
    }

    /**
     * @brief Adiciona um novo veículo ao repositório.
     * 
     * @param v Objeto Veiculo a ser adicionado.
     * @return int ID do veículo adicionado.
     * @throws std::runtime_error Se a placa do veículo for inválida.
     */
    int addVeiculo(Veiculo v) { 
        v.setId(gerarProximoIdVeiculo()); 
        v.setPlaca(v.getPlaca()); // Valida a placa
        veiculos.push_back(v); 
        return v.getId();
        }
    
     /**
      * @brief Obtém um veículo pela placa.
      * 
      * @param placa Placa do veículo a ser obtido.
      * @return Veiculo* Ponteiro para o objeto Veiculo, ou nullptr se não encontrado.
      */
    Veiculo* getVeiculo(const char* placa) { 
        for (auto& veiculo : veiculos) {
            if (veiculo.getPlaca() == placa) {
                return &veiculo;
            }
        }
        return nullptr;
     }

    /**     
     * @brief Atualiza um veículo existente no repositório.
     * 
     * @param elemento Objeto Veiculo com os dados atualizados.
     * @throws std::runtime_error Se o veículo não for encontrado.
     */
    void updateVeiculo(Veiculo elemento) {
        for (auto& veiculo : veiculos) {
            if (strcmp(veiculo.getPlaca(), elemento.getPlaca()) == 0) {
                veiculo = elemento;
                return;
            }
        
        }
        throw std::runtime_error("Veículo não encontrado");

    }

    /**
     * @brief Remove um veículo do repositório pela placa.
     * 
     * @param placa Placa do veículo a ser removido.
     * @throws std::runtime_error Se o veículo não for encontrado.
     */
    void removeVeiculo(const char* placa) {
        for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {
            if (strcmp(it->getPlaca(), placa) == 0) {
                veiculos.erase(it);
                return;
            }
        }
        throw std::runtime_error("Veículo não encontrado");
    }

    std::vector<Veiculo> getAllVeiculo() {
        return veiculos;
    }

    // Pedidos
    /**
     * @brief Gera o próximo ID único para um pedido.
     * @return int Próximo ID único para um pedido.
     */
        int gerarProximoIdPedido() {
        return nextPedidoId++;
    }

    /**
     * @brief Adiciona um novo pedido ao repositório.
     * 
     * @param p Objeto Pedido a ser adicionado.
     * @return int ID do pedido adicionado.
     */
    int addPedido(Pedido p) { 
        p.setId(gerarProximoIdPedido()); 
        pedidos.push_back(p);
        return p.getId();
    }
    
    /**
     * @brief Obtém um pedido pelo ID.
     * 
     * @param id ID do pedido a ser obtido.
     * @return Pedido* Ponteiro para o objeto Pedido, ou nullptr se não encontrado.
     */
    Pedido* getPedido(int id) { 
        for (auto& pedido : pedidos) {
            if (pedido.getId() == id) {
                return &pedido;
            }
        }
        return nullptr;
    }

    /**
     * @brief Atualiza um pedido existente no repositório.
     * 
     * @param elemento Objeto Pedido com os dados atualizados.
     * @throws std::runtime_error Se o pedido não for encontrado.
     */
    void updatePedido(Pedido elemento) {
        for (auto& pedido : pedidos) {
            if (pedido.getId() == elemento.getId()) {
                pedido = elemento;
                return;
            }
        }
        throw std::runtime_error("Pedido não encontrado");
    }

    /**
     * @brief Remove um pedido do repositório pelo ID.
     * 
     * @param id ID do pedido a ser removido.
     * @throws std::runtime_error Se o pedido não for encontrado.
     */
    void removePedido(int id) {
        for (auto it = pedidos.begin(); it != pedidos.end(); ++it) {
            if (it->getId() == id) {
                pedidos.erase(it);
                return;
            }
        }
        throw std::runtime_error("Pedido não encontrado");
    }

    std::vector<Pedido> getAllPedido() {
        return pedidos;
    }
    
    /**
     * @brief Salva os dados do repositório em um arquivo binário.
     * 
     * @param DB_PATH Caminho do arquivo onde os dados serão salvos.
     * @details Esta função salva todos os dados do repositório, incluindo locais, veículos e pedidos,
     *          em um arquivo binário especificado pelo caminho DB_PATH. O formato do arquivo
     *          é estruturado para facilitar a leitura e escrita dos dados, garantindo que os IDs
     *          sejam mantidos corretamente entre as execuções do programa.
     * @throws std::runtime_error Se houver um erro ao abrir o arquivo para escrita.
     */
    void salvarBinario(const char* DB_PATH) {
        std::ofstream outFile(DB_PATH, std::ios::binary); // Abre o arquivo em modo binário
        if (!outFile) {
            throw std::runtime_error("Erro ao abrir o arquivo para escrita");
        }

        // Salva locais
        // Obtém o número de locais
        size_t localCount = locais.size(); 
        
        // Escreve o número de locais
        outFile.write(reinterpret_cast<const char*>(&localCount), sizeof(localCount)); 
        
        // Itera sobre cada local e escreve seus dados no arquivo
        for (const auto& local : locais) {
            outFile.write(reinterpret_cast<const char*>(&local), sizeof(Local)); // Escreve o local no arquivo
        }

        // Salva veículos
        // Obtém o número de veículos
        size_t veiculoCount = veiculos.size(); 
        // Escreve o número de veículos no arquivo
        outFile.write(reinterpret_cast<const char*>(&veiculoCount), sizeof(veiculoCount));

        // Itera sobre cada veículo e escreve seus dados no arquivo
        for (const auto& veiculo : veiculos) {
            outFile.write(reinterpret_cast<const char*>(&veiculo), sizeof(Veiculo)); // Escreve o veículo no arquivo
        }

        // Salva pedidos
        // Obtém o número de pedidos
        size_t pedidoCount = pedidos.size();

        // Escreve o número de pedidos no arquivo
        outFile.write(reinterpret_cast<const char*>(&pedidoCount), sizeof(pedidoCount));

        // Itera sobre cada pedido e escreve seus dados no arquivo
        for (const auto& pedido : pedidos) {
            outFile.write(reinterpret_cast<const char*>(&pedido), sizeof(Pedido)); // Escreve o pedido no arquivo
        }

        outFile.close(); // Fecha o arquivo após a escrita
    }

    /**
     * @brief Carrega os dados do repositório a partir de um arquivo binário.
     * 
     * @param DB_PATH Caminho do arquivo de onde os dados serão carregados.
     * @details Esta função lê os dados do repositório a partir de um arquivo binário especificado pelo caminho DB_PATH.
     *          Ela restaura os locais, veículos e pedidos, garantindo que os IDs sejam mantidos corretamente entre as execuções do programa.
     * @throws std::runtime_error Se houver um erro ao abrir o arquivo para leitura.
     */
    void carregarBinario(const char* DB_PATH) {
        std::ifstream inFile(DB_PATH, std::ios::binary); // Abre o arquivo em modo binário
        if (!inFile) {
            throw std::runtime_error("Erro ao abrir o arquivo para leitura");
        }

        // Carrega locais
        size_t localCount; // Lê o número de locais
        inFile.read(reinterpret_cast<char*>(&localCount), sizeof(localCount)); // Lê o número de locais do arquivo
        locais.resize(localCount); // Redimensiona o vetor de locais para o número lido

        // Itera sobre cada local e lê seus dados do arquivo
        for (auto& local : locais) {
            inFile.read(reinterpret_cast<char*>(&local), sizeof(Local)); // Lê o local do arquivo
        }

        // Atualiza o próximo ID de local
        // Se houver locais, o próximo ID será o ID do último local + 1
        if (!locais.empty()) {
        nextLocalId = locais.back().getId() + 1; 
        } else {
        nextLocalId = 0; // Se não houver locais, inicia o próximo ID como 0
        }

        // Carrega veículos
        size_t veiculoCount; // Lê o número de veículos
        inFile.read(reinterpret_cast<char*>(&veiculoCount), sizeof(veiculoCount)); // Lê o número de veículos do arquivo
        veiculos.resize(veiculoCount); // Redimensiona o vetor de veículos para o número lido

        // Itera sobre cada veículo e lê seus dados do arquivo
        for (auto& veiculo : veiculos) {
            inFile.read(reinterpret_cast<char*>(&veiculo), sizeof(Veiculo)); // Lê o veículo do arquivo
        }

        // Atualiza o próximo ID de veículo
        // Se houver veículos, o próximo ID será o ID do último veículo + 1
        if (!veiculos.empty()) {
            nextVeiculoId = veiculos.back().getId() + 1;
        } else {
        nextVeiculoId = 0; // Se não houver veículos, inicia o próximo ID como 0
        }

        // Carrega pedidos
        size_t pedidoCount;// Lê o número de pedidos
        inFile.read(reinterpret_cast<char*>(&pedidoCount), sizeof(pedidoCount)); // Lê o número de pedidos do arquivo
        pedidos.resize(pedidoCount);// Redimensiona o vetor de pedidos para o número lido

        // Itera sobre cada pedido e lê seus dados do arquivo
        for (auto& pedido : pedidos) {
            inFile.read(reinterpret_cast<char*>(&pedido), sizeof(Pedido));// Lê o pedido do arquivo
        }

        // Atualiza o próximo ID de pedido
        // Se houver pedidos, o próximo ID será o ID do último pedido + 1
        if (!pedidos.empty()) {
            nextPedidoId = pedidos.back().getId() + 1;
        } else {
        nextPedidoId = 0; // Se não houver pedidos, inicia o próximo ID como 0
        }

        inFile.close(); // Fecha o arquivo após a leitura
    }
};

#endif // REPOSITORIO_H