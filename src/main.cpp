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
#include "database/repositorio.h"
#include "funcs/localService.h"
#include "funcs/systemService.h"

int main() {
    // Inicializa o repositório
    Repositorio repo;
    carregarDB(repo);
    LocalService localService(&repo);
    Endereco endereco("Rua Exemplo", "Cidade Exemplo", "Estado Exemplo");
    double x = 10.0;
    double y = 20.0;
    // Cria um novo local
    int localId = localService.criarLocal(endereco, x, y);
    if (localId != -1) {
        std::cout << "Local criado com ID: " << localId << std::endl;
    } else {
        std::cerr << "Erro ao criar local." << std::endl;
    }

    // Lista todos os locais

    std::cout << "Lista de Locais:" << std::endl;
    for (const auto& local : localService.listarLocais()) {
        std::cout << "ID: " << local.getId() 
                  << ", Endereço: " << local.getEndereco().getRua() 
                  << ", Coordenadas: (" << local.getCoordenadaX() 
                  << ", " << local.getCoordenadaY() << ")" << std::endl;
    }

    //remove um local
    if (localService.deletarLocal(localId)) {
        std::cout << "Local com ID " << localId << " removido com sucesso." << std::endl;
    } else {
        std::cerr << "Erro ao remover local com ID " << localId << "." << std::endl;
    }

    std::cout << "Lista de Locais:" << std::endl;
    for (const auto& local : localService.listarLocais()) {
        std::cout << "ID: " << local.getId() 
                  << ", Endereço: " << local.getEndereco().getRua() 
                  << ", Coordenadas: (" << local.getCoordenadaX() 
                  << ", " << local.getCoordenadaY() << ")" << std::endl;
    }

    salvarDB(repo);
}
    



