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
    
    adicionarLocal(&repo);
    listarLocais(&repo);
    editarLocal(&repo);
    removerLocal(&repo);
    listarLocais(&repo);

    salvarDB(repo);
}
    



