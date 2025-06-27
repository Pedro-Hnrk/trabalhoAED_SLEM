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
        
        void setPlaca(const char* placa) {
            if (placa == nullptr) {
                return;
            }
            if (strlen(placa) != 7) {
                return;
            }
        
            // Verifica se os primeiros 3 caracteres são letras
            for (int i = 0; i < 3; ++i) {
                if (!isalpha(placa[i])) {
                    return;
                }
            }
        
            // Verifica se os últimos 4 caracteres são dígitos
            for (int i = 3; i < 7; ++i) {
                if (!isdigit(placa[i])) {
                    return;
                }
            }
            
            strncpy(this->placa, placa, sizeof(this->placa) - 1);
            this->placa[sizeof(this->placa) - 1] = '\0';
        }

        void setModelo(const char* modelo) {
            if (modelo == nullptr) {
                return;
            }
            strncpy(this->modelo, modelo, sizeof(this->modelo) - 1);
            this->modelo[sizeof(this->modelo) - 1] = '\0';
        }

        void setLocal(const Local& novoLocal) {
            local = novoLocal;
        }

        void setStatus(bool novoStatus) {
            status = novoStatus;
        }
};  

#endif // VEICULO_H