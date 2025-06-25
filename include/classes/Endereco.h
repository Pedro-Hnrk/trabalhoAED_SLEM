#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include <vector>
#include <cstring>

class Endereco {
    private:
        char rua[50];
        char cidade[50];
        char estado[3];
    public:
        Endereco() = default; // Construtor padrão
        Endereco(const char* rua, const char* cidade, const char* estado) {
            strncpy(this->rua, rua, sizeof(this->rua) - 1);
            this->rua[sizeof(this->rua) - 1] = '\0';
            strncpy(this->cidade, cidade, sizeof(this->cidade) - 1);
            this->cidade[sizeof(this->cidade) - 1] = '\0';
            strncpy(this->estado, estado, sizeof(this->estado) - 1);
            this->estado[sizeof(this->estado) - 1] = '\0';
        }
        const char* getRua() const { return rua; }
        const char* getCidade() const { return cidade; }
        const char* getEstado() const { return estado; }
};

#endif // ENDERECO_H