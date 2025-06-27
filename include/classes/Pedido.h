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
        bool status; // false = pendente, true = concluído
    public:
        Pedido() = default;
        Pedido(int id, const Local& origem, const Local& destino, float peso, bool status)
            : id(id), origem(origem), destino(destino), peso(peso), status(status) {}
        int getId() const { return id; }
        const Local& getOrigem() const { return origem; }
        const Local& getDestino() const { return destino; }
        float getPeso() const { return peso; }
        bool getStatus() const { return status; }

        void setId(int novoId) {
            id = novoId;
        }

        void setOrigem(const Local& novaOrigem) {
            origem = novaOrigem;
        }

        void setDestino(const Local& novoDestino) {
            destino = novoDestino;
        }

        void setPeso(float novoPeso) {
            if (novoPeso <= 0) {
                std::cerr << "Peso deve ser maior que 0 Kg." << std::endl;
                return;
            }
            peso = novoPeso;
        }

        void setStatus(bool novoStatus) {
            status = novoStatus;
        }

};

#endif // PEDIDO_H