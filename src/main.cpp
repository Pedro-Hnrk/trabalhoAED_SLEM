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
#include "include/database/repositorio.h"
#include "include/funcs/localService.h"

int main() {
    // Inicializa o repositório
    Repositorio repo;
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
    



