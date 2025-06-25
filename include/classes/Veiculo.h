#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include "Local.h"

class Veiculo {
    private:
        char placa[8];
        char modelo[50];
        class Local local;
        bool status;
    public:
        Veiculo() = default; // Construtor padrão
        Veiculo(const char* placa, const char* modelo, const Local& local, bool status)
            : local(local), status(status) {
            strncpy(this->placa, placa, sizeof(this->placa) - 1);
            this->placa[sizeof(this->placa) - 1] = '\0';
            strncpy(this->modelo, modelo, sizeof(this->modelo) - 1);
            this->modelo[sizeof(this->modelo) - 1] = '\0';
        }
        const char* getPlaca() const { return placa; }
        const char* getModelo() const { return modelo; }
        const Local& getLocal() const { return local; }
        bool getStatus() const { return status; }
};  

#endif // VEICULO_H