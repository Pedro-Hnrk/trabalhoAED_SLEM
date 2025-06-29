#ifndef SYSTEMSERVICE_H
#define SYSTEMSERVICE_H

#pragma once
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include "database/repositorio.h"
#include <vector>
#include <string>
#include <fstream>

void salvarDB(Repositorio& repo) {
    repo.salvarBinario("include/database/database.bin");
}

void carregarDB(Repositorio& repo) {
    repo.carregarBinario("include/database/database.bin");
}

#endif // SYSTEMSERVICE_H