#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include <vector>
#include <cstring>

/**
 * @class Endereco
 * @brief Representa um endereço com informações como rua, cidade e estado.
 */
class Endereco {
    private:
        char rua[50];       // Rua do endereço  
        char cidade[50];    // Cidade do endereço
        char estado[3];     // Estado do endereço (2 letras + terminador nulo)
    public:
        /**
         * @brief Construtor padrão.
         * Inicializa os atributos com strings vazias.
         */
        Endereco() = default; // Construtor padrão

        /**
         * @brief Construtor parametrizado.
         * @param rua Rua do endereço.
         * @param cidade Cidade do endereço.
         * @param estado Estado do endereço (2 letras).
         */
        Endereco(const char* rua, const char* cidade, const char* estado) {
            strncpy(this->rua, rua, sizeof(this->rua) - 1);
            this->rua[sizeof(this->rua) - 1] = '\0';
            strncpy(this->cidade, cidade, sizeof(this->cidade) - 1);
            this->cidade[sizeof(this->cidade) - 1] = '\0';
            strncpy(this->estado, estado, sizeof(this->estado) - 1);
            this->estado[sizeof(this->estado) - 1] = '\0';
        }

        /**
         * @brief Obtém os atributos do endereço.
         * @return Referência para o objeto Endereco.
         */
        const char* getRua() const { return rua; }

        /**
         * @brief Obtém os atributos do endereço.
         * @return Referência para o objeto Endereco.
         */
        const char* getCidade() const { return cidade; }

        /**
         * @brief Obtém os atributos do endereço.
         * @return Referência para o objeto Endereco.
         */
        const char* getEstado() const { return estado; }

        /**
         * @brief Define a rua do endereço.
         * @param rua Nova rua a ser atribuída ao endereço.
         */
        void setRua (const char* rua) {
            if (rua == nullptr) {
                std::cerr << "Rua não pode ser nula." << std::endl;
                return;
            }
            strncpy(this->rua, rua, sizeof(this->rua) - 1);
            this->rua[sizeof(this->rua) - 1] = '\0';
        }

        /**
         * @brief Define a cidade do endereço.
         * @param cidade Nova cidade a ser atribuída ao endereço.
         */
        void setCidade(const char* cidade) {
            if (cidade == nullptr) {
                std::cerr << "Cidade não pode ser nula." << std::endl;
                return;
            }
            strncpy(this->cidade, cidade, sizeof(this->cidade) - 1);
            this->cidade[sizeof(this->cidade) - 1] = '\0';
        }

        /**
         * @brief Define o estado do endereço.
         * @param estado Novo estado a ser atribuído ao endereço (2 letras).
         */
        void setEstado(const char* estado) {
            if (estado == nullptr) {
                std::cerr << "Estado não pode ser nulo." << std::endl;
                return;
            if(estado[0] == '\0' || estado[1] == '\0') {
                std::cerr << "Estado deve ter 2 letras." << std::endl;
                return;
            }
            strncpy(this->estado, estado, sizeof(this->estado) - 1);
            this->estado[sizeof(this->estado) - 1] = '\0';
        }
};

#endif // ENDERECO_H