#pragma once
#include "Local.h"
#include "Veiculo.h"
#include "Pedido.h"
#include <vector>
#include <string>

class Repositorio {
    std::vector<Local> locais;
    std::vector<Veiculo> veiculos;
    std::vector<Pedido> pedidos;

public:
    // Locais
    void addLocal(const Local& l) { locais.push_back(l); }
    Local* getLocal(int id) { /*...*/ }

    // Veículos
    void addVeiculo(const Veiculo& v) { veiculos.push_back(v); }
    Veiculo* getVeiculo(const std::string& placa) { /*...*/ }

    // Pedidos
    void addPedido(const Pedido& p) { pedidos.push_back(p); }
    Pedido* getPedido(int id) { /*...*/ }

    // Persistência binária (salva todas as entidades juntas)
    void salvarBinario(const std::string& arquivo) {
        std::ofstream file(arquivo, std::ios::binary);
        // Serializa vetores locais, veiculos, pedidos...
    }
};