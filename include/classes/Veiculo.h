#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include "Local.h"

class Veiculo {
    private:
        int id; // ID único do veículo
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
        int getId() const { return id; }

        bool setId(int novoId) {
            if (novoId < 0) {
                std::cerr << "ID inválido." << std::endl;
                return false;
            }
            id = novoId;
            return true;
        }
        
        bool setPlaca(const char* placa) {
            if (placa == nullptr) {
                return false;
            }
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
            
            strncpy(this->placa, placa, sizeof(this->placa) - 1);
            this->placa[sizeof(this->placa) - 1] = '\0';
            return true;
        }

        bool setModelo(const char* modelo) {
            if (modelo == nullptr) {
                return false;
            }
            strncpy(this->modelo, modelo, sizeof(this->modelo) - 1);
            this->modelo[sizeof(this->modelo) - 1] = '\0';
            return true;
        }

        bool setLocal(const Local& novoLocal) {
            local = novoLocal;
            return true;
        }

        bool setStatus(bool novoStatus) {
            status = novoStatus;
            return true;
        }
};  

#endif // VEICULO_H