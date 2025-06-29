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

int main() {
    // Inicializa o repositório
    Repositorio repo;
    carregarDB(repo);
    
    adicionarLocal(&repo);
    listarLocais(&repo);
    editarLocal(&repo);
    adicionarVeiculo(&repo);
    listarVeiculos(&repo);
    editarVeiculo(&repo);
    removerVeiculo(&repo);
    listarVeiculos(&repo);
    removerLocal(&repo);
    listarLocais(&repo);

    salvarDB(repo);
}
    



