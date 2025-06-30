#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <stdbool.h>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include "database/repositorio.h"
#include "funcs/localService.h"
#include "funcs/veiculoService.h"
#include "funcs/pedidoService.h"
#include "funcs/systemService.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Inicializa o repositório
    Repositorio repo;
    carregarDB(repo);

    int op = -1;
    int entregaOp = -1;
    int veiculoOp = -1;
    int pedidoOp = -1;
    int localOp =-1;
    do {
    std::cout << "Bem-vindo ao SLEM!" << std::endl;
    std::cout << "Selecione uma opção:" << std::endl;
    std::cout << "1. Locais" << std::endl;
    std::cout << "2. Veículos" << std::endl;
    std::cout << "3. Pedidos" << std::endl;
    std::cout << "4. Gerenciar Entregas" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cin >> op;
    std::cin.ignore(); // Limpa o buffer do cin para evitar problemas com getline
    if (op < 0 || op > 4) 
        std::cout << "Opção inválida. Tente novamente." << std::endl;
    switch (op) {
        case 1:
            do {
                std::cout << "Opções Locais." << std::endl;
                std::cout << "1. Adicionar Local" << std::endl;
                std::cout << "2. Listar Locais" << std::endl;
                std::cout << "3. Editar Local" << std::endl;
                std::cout << "4. Remover Local" << std::endl;
                std::cout << "0. Voltar" << std::endl;
                std::cin >> localOp;
                switch (localOp) {
                    case 1:
                        adicionarLocal(&repo);
                        localOp = -1;
                        break;
                    case 2:
                        listarLocais(&repo);
                        localOp = -1;
                        break;
                    case 3:
                        editarLocal(&repo);
                        localOp = -1;
                        break;
                    case 4:
                        removerLocal(&repo);
                        localOp = -1;
                        break;
                    case 0:
                        std::cout << "Voltando ao menu principal." << std::endl;
                        break;
                    default:
                        std::cout << "Opção inválida." << std::endl;
                }
        } while (localOp != 0);
            break;
        case 2:
            do {
                std::cout << "Opções Veículos." << std::endl;
                std::cout << "1. Adicionar Veículo" << std::endl;
                std::cout << "2. Listar Veículos" << std::endl;
                std::cout << "3. Editar Veículo" << std::endl;
                std::cout << "4. Remover Veículo" << std::endl;
                std::cout << "0. Voltar" << std::endl;
                std::cin >> veiculoOp;
                switch (veiculoOp) {
                    case 1:
                        adicionarVeiculo(&repo);
                        veiculoOp = -1;
                        break;
                    case 2:
                        listarVeiculos(&repo);
                        veiculoOp = -1;
                        break;
                    case 3:
                        editarVeiculo(&repo);
                        veiculoOp = -1;
                        break;
                    case 4:
                        removerVeiculo(&repo);
                        veiculoOp = -1;
                        break;
                    case 0:
                        std::cout << "Voltando ao menu principal." << std::endl;
                        break;
                    default:
                        std::cout << "Opção inválida." << std::endl;
                }
            } while (veiculoOp != 0);
            break;
        case 3:
            do {
                std::cout << "Opções Pedidos." << std::endl;
                std::cout << "1. Adicionar Pedido" << std::endl;
                std::cout << "2. Listar Pedidos" << std::endl;
                std::cout << "3. Editar Pedido" << std::endl;
                std::cout << "4. Remover Pedido" << std::endl;
                std::cout << "0. Voltar" << std::endl;
                
                std::cin >> pedidoOp;
                switch (pedidoOp) {
                    case 1:
                        adicionarPedido(&repo);
                        pedidoOp = -1;
                        break;
                    case 2:
                        listarPedidos(&repo);
                        pedidoOp = -1;
                        break;
                    case 3:
                        editarPedido(&repo);
                        pedidoOp = -1;
                        break;
                    case 4:
                        removerPedido(&repo);
                        pedidoOp = -1;
                        break;
                    case 0:
                        std::cout << "Voltando ao menu principal." << std::endl;
                        break;
                    default:
                        std::cout << "Opção inválida." << std::endl;
                }
            } while (pedidoOp != 0);
            break;
        case 4:
            do {
                std::cout << "Opções Gerenciar Entregas." << std::endl;
                std::cout << "1. Listar Pedidos Pendentes" << std::endl;
                std::cout << "2. Listar Pedidos Entregues" << std::endl;
                std::cout << "3. Realizar Nova Entrega" << std::endl;
                std::cout << "0. Voltar" << std::endl;
                std::cin >> entregaOp;
                switch (entregaOp) {
                    case 1:
                        listarPedidosPendentes(&repo);
                        entregaOp = -1;
                        break;
                    case 2:
                        listarPedidosEntregues(&repo);
                        entregaOp = -1;
                        break;
                    case 3: {
                        std::cout << "Digite o ID do pedido a ser entregue: ";
                        int pedidoId;
                        std::cin >> pedidoId;
                        std::cin.ignore(); // Limpa o buffer do cin para evitar problemas com getline
                        Pedido* pedido = repo.getPedido(pedidoId);
                        if (!pedido) {
                            std::cerr << "Pedido não encontrado." << std::endl;
                            break;
                        }
                        realizarEntrega(repo, *pedido);
                        entregaOp = -1;
                        break;
                    }
                    case 0:
                        std::cout << "Voltando ao menu principal." << std::endl;
                        break;
                    default:
                        std::cout << "Opção inválida." << std::endl;
                }
            } while (entregaOp != 0);
            break;
        case 0:
            std::cout << "Saindo do programa." << std::endl;
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
    }

    } while (op != 0);
    // Salva o estado do repositório antes de sair
    salvarDB(repo);
}
    



