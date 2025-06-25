#ifndef VERIFICADOR_PEDIDOS_H
#define VERIFICADOR_PEDIDOS_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "classes/Veiculo.h"
#include "classes/Pedido.h"
#include "funcs/verificadores/verificadorVeiculo.h"
#include "funcs/verificadores/verificadorLocal.h"

bool verificaPedido(const Pedido& pedido) {
    // Verifica se o ID do pedido é válido (não negativo)
    if (pedido.getId() < 0) {
        std::cerr << "ID do pedido inválido: " << pedido.getId() << std::endl;
        return false;
    }

    // Verifica se o peso do pedido é positivo
    if (pedido.getPeso() <= 0) {
        std::cerr << "Peso do pedido deve ser positivo." << std::endl;
        return false;
    }

    // Verifica se as origens e destinos são válidos
    if (!verificaLocal(pedido.getOrigem()) || !verificaLocal(pedido.getDestino())) {
        return false;
    }

    return true;
}

#endif // VERIFICADOR_PEDIDOS_H