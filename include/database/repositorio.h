#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#pragma once
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include <vector>
#include <string>
#include <fstream>

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
    int gerarProximoIdLocal() {
        return nextLocalId++;
    }

    int addLocal(Local l) { 
        l.setId(gerarProximoIdLocal()); 
        locais.push_back(l); 
        return l.getId();
    }
    
    Local* getLocal(int id) {
        for (auto& local : locais) {
            if (local.getId() == id) {
                return &local;
            }
        }
        return nullptr;
    }

    void updateLocal(Local elemento) {
        for (auto& local : locais) {
            if (local.getId() == elemento.getId()) {
                local = elemento;
                return;
            }
        }
        throw std::runtime_error("Local não encontrado");
    }


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
    int gerarProximoIdVeiculo() {
        return nextVeiculoId++;
    }

    int addVeiculo(Veiculo v) { 
        v.setId(gerarProximoIdVeiculo()); 
        v.setPlaca(v.getPlaca()); // Valida a placa
        veiculos.push_back(v); 
        return v.getId();
        }
    
    Veiculo* getVeiculo(const char* placa) { 
        for (auto& veiculo : veiculos) {
            if (veiculo.getPlaca() == placa) {
                return &veiculo;
            }
        }
        return nullptr;
     }

    void updateVeiculo(Veiculo elemento) {
        for (auto& veiculo : veiculos) {
            if (strcmp(veiculo.getPlaca(), elemento.getPlaca()) == 0) {
                veiculo = elemento;
                return;
            }
        
        }
        throw std::runtime_error("Veículo não encontrado");

    }

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
        int gerarProximoIdPedido() {
        return nextPedidoId++;
    }

    int addPedido(Pedido p) { 
        p.setId(gerarProximoIdPedido()); 
        pedidos.push_back(p);
        return p.getId();
    }
    
    Pedido* getPedido(int id) { 
        for (auto& pedido : pedidos) {
            if (pedido.getId() == id) {
                return &pedido;
            }
        }
        return nullptr;
    }

    void updatePedido(Pedido elemento) {
        for (auto& pedido : pedidos) {
            if (pedido.getId() == elemento.getId()) {
                pedido = elemento;
                return;
            }
        }
        throw std::runtime_error("Pedido não encontrado");
    }

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

    // Persistência binária (salva todas as entidades juntas)
    void salvarBinario(const char* DB_PATH) {
        std::ofstream outFile(DB_PATH, std::ios::binary);
        if (!outFile) {
            throw std::runtime_error("Erro ao abrir o arquivo para escrita");
        }

        // Salva locais
        size_t localCount = locais.size();
        outFile.write(reinterpret_cast<const char*>(&localCount), sizeof(localCount));
        for (const auto& local : locais) {
            outFile.write(reinterpret_cast<const char*>(&local), sizeof(Local));
        }

        // Salva veículos
        size_t veiculoCount = veiculos.size();
        outFile.write(reinterpret_cast<const char*>(&veiculoCount), sizeof(veiculoCount));
        for (const auto& veiculo : veiculos) {
            outFile.write(reinterpret_cast<const char*>(&veiculo), sizeof(Veiculo));
        }

        // Salva pedidos
        size_t pedidoCount = pedidos.size();
        outFile.write(reinterpret_cast<const char*>(&pedidoCount), sizeof(pedidoCount));
        for (const auto& pedido : pedidos) {
            outFile.write(reinterpret_cast<const char*>(&pedido), sizeof(Pedido));
        }

        outFile.close();
    }

    void carregarBinario(const char* DB_PATH) {
        std::ifstream inFile(DB_PATH, std::ios::binary);
        if (!inFile) {
            throw std::runtime_error("Erro ao abrir o arquivo para leitura");
        }

        // Carrega locais
        size_t localCount;
        inFile.read(reinterpret_cast<char*>(&localCount), sizeof(localCount));
        locais.resize(localCount);
        for (auto& local : locais) {
            inFile.read(reinterpret_cast<char*>(&local), sizeof(Local));
        }
        if (!locais.empty()) {
        nextLocalId = locais.back().getId() + 1;
        } else {
        nextLocalId = 0;
        }

        // Carrega veículos
        size_t veiculoCount;
        inFile.read(reinterpret_cast<char*>(&veiculoCount), sizeof(veiculoCount));
        veiculos.resize(veiculoCount);
        for (auto& veiculo : veiculos) {
            inFile.read(reinterpret_cast<char*>(&veiculo), sizeof(Veiculo));
        }
        if (!veiculos.empty()) {
            nextVeiculoId = veiculos.back().getId() + 1;
        } else {
        nextVeiculoId = 0;
        }

        // Carrega pedidos
        size_t pedidoCount;
        inFile.read(reinterpret_cast<char*>(&pedidoCount), sizeof(pedidoCount));
        pedidos.resize(pedidoCount);
        for (auto& pedido : pedidos) {
            inFile.read(reinterpret_cast<char*>(&pedido), sizeof(Pedido));
        }
        if (!pedidos.empty()) {
            nextPedidoId = pedidos.back().getId() + 1;
        } else {
        nextPedidoId = 0;
        }

        inFile.close();
    }
};

#endif // REPOSITORIO_H