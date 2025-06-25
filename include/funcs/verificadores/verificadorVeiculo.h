#ifndef VERIFICADOR_VEICULO_H
#define VERIFICADOR_VEICULO_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"

bool verificaPlaca(const char* placa) {
    // Verifica se a placa tem exatamente 7 caracteres
    if (strlen(placa) != 7) {
        return false;
    }
    
    // Verifica se os primeiros 3 caracteres são letras
    for (int i = 0; i < 3; ++i) {
        if (!isalpha(placa[i])) {
            return false;
        }
    }
    
    // Verifica se os últimos 4 caracteres são dígitos
    for (int i = 3; i < 7; ++i) {
        if (!isdigit(placa[i])) {
            return false;
        }
    }
    
    return true;
}

bool verificaVeiculo(const Veiculo& veiculo) {
    // Verifica se a placa é válida
    if (!verificaPlaca(veiculo.getPlaca())) {
        std::cerr << "Placa inválida: " << veiculo.getPlaca() << std::endl;
        return false;
    }

    // Verifica se o modelo não está vazio
    if (strlen(veiculo.getModelo()) == 0) {
        std::cerr << "Modelo não pode ser vazio." << std::endl;
        return false;
    }

    return true;
}
#endif // VERIFICADOR_VEICULO_H