#ifndef VERIFICADOR_LOCAL_H
#define VERIFICADOR_LOCAL_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"

bool verificaEndereco(const Endereco& endereco) {
    // Verifica se os campos do endereço não estão vazios
    if (strlen(endereco.getRua()) == 0 || strlen(endereco.getCidade()) == 0 || strlen(endereco.getEstado()) != 2) {
        std::cerr << "Endereço inválido." << std::endl;
        return false;
    }
    return true;
}

bool verificaLocal(const Local& local) {
    // Verifica se o endereço do local é válido
    if (!verificaEndereco(local.getEndereco())) {
        return false;
    }

    // Verifica se as coordenadas são válidas (exemplo: não podem ser NaN)
    if (std::isnan(local.getCoordenadaX()) || std::isnan(local.getCoordenadaY())) {
        std::cerr << "Coordenadas inválidas." << std::endl;
        return false;
    }

    return true;
}
#endif // VERIFICADOR_LOCAL_H