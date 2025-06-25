#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <stdbool.h>
#include <cstring>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include "funcs/systemCRUD.h"

int main() {
    // Inicializando o sistema CRUD
    SistemaCRUD sistema;

    // Criando alguns endereços
    Endereco endereco1("Rua A", "Cidade A", "SP");
    Endereco endereco2("Rua B", "Cidade B", "RJ");

    // Criando locais
    int idLocal1 = sistema.criarLocal(endereco1, 10.0, 20.0);
    int idLocal2 = sistema.criarLocal(endereco2, 30.0, 40.0);

    // Lendo locais
    Local* local1 = sistema.lerLocal(idLocal1);
    Local* local2 = sistema.lerLocal(idLocal2);

    if (local1) {
        std::cout << "Local 1: " << local1->getEndereco().getRua() << ", "
                  << local1->getEndereco().getCidade() << ", "
                  << local1->getEndereco().getEstado() << std::endl;
    }

    if (local2) {
        std::cout << "Local 2: " << local2->getEndereco().getRua() << ", "
                  << local2->getEndereco().getCidade() << ", "
                  << local2->getEndereco().getEstado() << std::endl;
    }

    // Atualizando um local
    Endereco novoEndereco("Rua C", "Cidade C", "MG");
    sistema.atualizarLocal(idLocal1, novoEndereco, 50.0, 60.0);

    // Deletando um local
    sistema.deletarLocal(idLocal2);

    // Criando veículos
    Veiculo veiculo1("ABC1234", "Modelo A", *local1, true);
    Veiculo veiculo2("XYZ5678", "Modelo B", *local1, false);
    
    int idVeiculo1 = sistema.criarVeiculo(
        veiculo1.getPlaca(),
        veiculo1.getModelo(),
        veiculo1.getLocal(),
        veiculo1.getStatus()
    );

    int idVeiculo2 = sistema.criarVeiculo(
        veiculo2.getPlaca(),
        veiculo2.getModelo(),
        veiculo2.getLocal(),
        veiculo2.getStatus()
    );

    // Listando veículos
    auto veiculos = sistema.listarVeiculos();
    for (const auto& veiculo : veiculos) {
        std::cout << "Veículo: " << veiculo.getPlaca() << ", "
                  << veiculo.getModelo() << ", "
                  << (veiculo.getStatus() ? "Disponível" : "Indisponível") << std::endl;
    }

    // Criando pedidos
    Pedido pedido1(1, *local1, *local1, 10.0);
    Pedido pedido2(2, *local1, *local1, 20.0);
    int idPedido1 = sistema.criarPedido(
        pedido1.getOrigem(),
        pedido1.getDestino(),
        pedido1.getPeso()
    );
    int idPedido2 = sistema.criarPedido(
        pedido2.getOrigem(),
        pedido2.getDestino(),
        pedido2.getPeso()
    );

    // Listando pedidos
    auto pedidos = sistema.listarPedidos(); 
    for (const auto& pedido : pedidos) {
        std::cout << "Pedido ID: " << pedido.getId() << ", "
                  << "Peso: " << pedido.getPeso() << ", "
                  << "Origem: " << pedido.getOrigem().getEndereco().getRua() << ", "
                  << "Destino: " << pedido.getDestino().getEndereco().getRua() << std::endl;
    }
    // Atualizando um pedido
    Local novaOrigem(endereco1, 70.0, 80.0);
    Local novoDestino(endereco2, 90.0, 100.0);
    sistema.atualizarPedido(idPedido1, novaOrigem, novoDestino, 15.0);
    // Deletando um pedido
    sistema.deletarPedido(idPedido2);
    system("pause"); // Pausa para visualizar a saída no console
    return 0;
    }
    



