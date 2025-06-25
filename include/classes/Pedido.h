#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include "Local.h"

class Pedido {
    private:
        int id;
        class Local origem;
        class Local destino;
        float peso;
    public:
        Pedido() = default;
        Pedido(int id, const Local& origem, const Local& destino, float peso)
            : id(id), origem(origem), destino(destino), peso(peso) {}
        int getId() const { return id; }
        const Local& getOrigem() const { return origem; }
        const Local& getDestino() const { return destino; }
        float getPeso() const { return peso; }
};

#endif // PEDIDO_H