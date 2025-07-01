#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include "Local.h"

/**
 * @class Veiculo
 * @brief Representa um veículo no sistema, contendo informações como placa, modelo, local, status e ID.
 */
class Veiculo {
    private:
        int id;                ///< ID único do veículo
        char placa[8];         ///< Placa do veículo (formato: 3 letras + 4 dígitos)
        char modelo[50];       ///< Modelo do veículo
        class Local local;     ///< Localização atual do veículo
        bool status;           ///< Status do veículo (true = disponível, false = indisponível)
    public:
        /**
         * @brief Construtor padrão.
         */
        Veiculo() = default;

        /**
         * @brief Construtor parametrizado.
         * @param placa Placa do veículo (string C, 7 caracteres).
         * @param modelo Modelo do veículo.
         * @param local Localização inicial do veículo.
         * @param status Status inicial do veículo.
         */ 
        Veiculo(const char* placa, const char* modelo, const Local& local, bool status)
            : local(local), status(status) {
            strncpy(this->placa, placa, sizeof(this->placa) - 1);
            this->placa[sizeof(this->placa) - 1] = '\0';
            strncpy(this->modelo, modelo, sizeof(this->modelo) - 1);
            this->modelo[sizeof(this->modelo) - 1] = '\0';
        }

        /**
         * @brief Obtém a placa do veículo.
         * @return Ponteiro para string C com a placa.
         */
        const char* getPlaca() const { return placa; }

        /**
         * @brief Obtém a placa do veículo.
         * @return Ponteiro para string C com a placa.
         */        
        const char* getModelo() const { return modelo; }

        /**
         * @brief Obtém a localização do veículo.
         * @return Referência para o objeto Local que representa a localização do veículo.
         */
        const Local& getLocal() const { return local; }

        /**
         * @brief Obtém o status do veículo.
         * @return true se o veículo está disponível, false se está indisponível.
         */
        bool getStatus() const { return status; }

        /**
         * @brief Obtém o ID do veículo.
         * @return ID do veículo.
         */
        int getId() const { return id; }

        /**
         * @brief Define o ID do veículo.
         * @param novoId Novo ID a ser atribuído ao veículo.
         * @return true se o ID foi definido com sucesso, false se o ID é inválido.
         */
        bool setId(int novoId) {
            if (novoId < 0) {
                std::cerr << "ID inválido." << std::endl;
                return false;
            }
            id = novoId;
            return true;
        }
        
        /**
         * @brief Define a placa do veículo.
         * @param placa Placa a ser atribuída ao veículo (formato: 3 letras + 4 dígitos).
         * @return true se a placa foi definida com sucesso, false se a placa é inválida.
         */
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

        /**
         * @brief Define o modelo do veículo.
         * @param modelo Modelo a ser atribuído ao veículo.
         * @return true se o modelo foi definido com sucesso, false se o modelo é inválido.
         */
        bool setModelo(const char* modelo) {
            if (modelo == nullptr) {
                return false;
            }
            strncpy(this->modelo, modelo, sizeof(this->modelo) - 1);
            this->modelo[sizeof(this->modelo) - 1] = '\0';
            return true;
        }

        /**
         * @brief Define a localização do veículo.
         * @param novoLocal Novo local a ser atribuído ao veículo.
         * @return true se o local foi definido com sucesso.
         */
        bool setLocal(const Local& novoLocal) {
            local = novoLocal;
            return true;
        }

        /**
         * @brief Define o status do veículo.
         * @param novoStatus Novo status a ser atribuído ao veículo (true = disponível, false = indisponível).
         * @return true se o status foi definido com sucesso.
         */
        bool setStatus(bool novoStatus) {
            status = novoStatus;
            return true;
        }
};  

#endif // VEICULO_H