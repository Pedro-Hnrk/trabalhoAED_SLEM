#ifndef FUNC_SYSTEMCRUD_H
#define FUNC_SYSTEMCRUD_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include "funcs/verificadores/verificadorVeiculo.h"
#include "funcs/verificadores/verificadorLocal.h"
#include "funcs/verificadores/verificadorPedido.h"



class SistemaCRUD {
private:
    // Vetor para armazenar locais
    class Local locais[100];
    // Vetor para armazenar veículos 
    class Veiculo veiculos[100];
    // Vetor para armazenar pedidos
    class Pedido pedidos[100];

    
    // Contadores para IDs
    int proximoIdLocal = 0;
    int proximoIdPedido = 0;
    int proximoIdVeiculo = 0;

public:
    SistemaCRUD() = default;
    // ================== CRUD PARA LOCAIS ==================
    int criarLocal(const Endereco& endereco, double x, double y) {
        if (!verificaLocal(Local(endereco, x, y))) {
            return -1;
        }
        Local novo(endereco, x, y);
        locais[proximoIdLocal] = novo;
        return proximoIdLocal++;
    }

    Local* lerLocal(int id) {
        if (id < 0 || id >= proximoIdLocal) return nullptr;
        return &locais[id];
    }

    bool atualizarLocal(int id, const Endereco& novoEndereco, double novoX, double novoY) {
        if (id < 0 || id >= proximoIdLocal) return false;
        Local atualizado(novoEndereco, novoX, novoY);
        if (!verificaLocal(atualizado)) {
            return false;
        }
        locais[id] = atualizado;
        return true;
    }

    bool deletarLocal(int id) {
        if (id < 0 || id >= proximoIdLocal) return false;
        // Para deletar, movemos o último local para a posição do deletado
        locais[id] = locais[--proximoIdLocal];
        return true;
    }

    std::vector<Local> listarLocais() {
        std::vector<Local> resultado;
        for (int i = 0; i < proximoIdLocal; ++i) {
            resultado.push_back(locais[i]);
        }
        return resultado;
    }

    // ================== CRUD PARA VEÍCULOS ==================
    bool criarVeiculo(const char* placa, const char* modelo, const Local& local, bool status) {
        if (!verificaVeiculo(Veiculo(placa, modelo, local, status))) {
            return false;
        }
        if (Veiculo* existente = lerVeiculo(placa)) {
            std::cerr << "Veículo com placa " << placa << " já existe." << std::endl;
            return false;
        }
        Veiculo novo(placa, modelo, local, status);
        veiculos[proximoIdVeiculo] = novo; 
        ++proximoIdVeiculo;
        return true;
    }

    Veiculo* lerVeiculo(const char* placa) {
        for (int i = 0; i < proximoIdVeiculo; ++i) {
            if (strcmp(veiculos[i].getPlaca(), placa) == 0) {
                return &veiculos[i];
            }
        }
        return nullptr;
    }

    bool atualizarVeiculo(const char* placa, const char* novoModelo, const Local& novoLocal, bool novoStatus) {
        Veiculo* veiculo = lerVeiculo(placa);
        if (!veiculo) {
            std::cerr << "Veículo com placa " << placa << " não encontrado." << std::endl;
            return false;
        }
        if (!verificaVeiculo(Veiculo(placa, novoModelo, novoLocal, novoStatus))) {
            return false;
        }
        *veiculo = Veiculo(placa, novoModelo, novoLocal, novoStatus);
        return true;
    }

    bool deletarVeiculo(const char* placa) {
        for (int i = 0; i < proximoIdVeiculo; ++i) {
            if (strcmp(veiculos[i].getPlaca(), placa) == 0) {
                // Para deletar, movemos o último veículo para a posição do deletado
                veiculos[i] = veiculos[--proximoIdVeiculo];
                return true;
            }
        }
        std::cerr << "Veículo com placa " << placa << " não encontrado." << std::endl;
        return false;
        
    }

    std::vector<Veiculo> listarVeiculos() {
        std::vector<Veiculo> resultado;
        for (int i = 0; i < proximoIdVeiculo; ++i) {
            resultado.push_back(veiculos[i]);
        
        }
        return resultado;
    }

    // ================== CRUD PARA PEDIDOS ==================
    int criarPedido(const Local& origem, const Local& destino, float peso) {
        if (verificaPedido(Pedido(proximoIdPedido, origem, destino, peso))) {
            return -1;
        }
        Pedido novo(proximoIdPedido, origem, destino, peso);
        pedidos[proximoIdPedido] = novo;
        return proximoIdPedido++;
    }

    Pedido* lerPedido(int id) {
        if (id < 0 || id >= proximoIdPedido) return nullptr;
        return &pedidos[id];
    }

    bool atualizarPedido(int id, const Local& novaOrigem, const Local& novoDestino, float novoPeso) {
        if (id < 0 || id >= proximoIdPedido) return false;
        if (!verificaPedido(Pedido(id, novaOrigem, novoDestino, novoPeso))) {
            return false;
        }
        Pedido atualizado(id, novaOrigem, novoDestino, novoPeso);
        pedidos[id] = atualizado;
        return true;
    }

    bool deletarPedido(int id) {
        if (id < 0 || id >= proximoIdPedido) return false;
        // Para deletar, movemos o último pedido para a posição do deletado
        pedidos[id] = pedidos[--proximoIdPedido];
        return true;
    }

    std::vector<Pedido> listarPedidos() {
        std::vector<Pedido> resultado;
        for (int i = 0; i < proximoIdPedido; ++i)
        {
            resultado.push_back(pedidos[i]);
        }
        return resultado;
    }
};

#endif // FUNC_SYSTEMCRUD_H