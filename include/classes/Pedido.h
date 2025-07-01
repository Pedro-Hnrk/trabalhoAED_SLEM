#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include "Local.h"

/**
 * @class Pedido
 * @brief Representa um pedido de entrega no sistema, contendo informações como origem, destino, peso e status.
 */
class Pedido {
    private:
        int id;                 ///< ID único do pedido
        class Local origem;     ///< Local de origem do pedido
        class Local destino;    ///< Local de destino do pedido
        float peso;             ///< Peso do pedido em quilogramas
        bool status;            ///< false = pendente, true = concluído
    public:
        /**
         * @brief Construtor padrão.
         */
        Pedido() = default;

        /**
         * @brief Construtor parametrizado.
         * @param origem Local de origem do pedido.
         * @param destino Local de destino do pedido.
         * @param peso Peso do pedido em quilogramas.
         * @param status Status do pedido (false = pendente, true = concluído).
         */
        Pedido(const Local& origem, const Local& destino, float peso, bool status)
            :  origem(origem), destino(destino), peso(peso), status(status) {}
        
        /**
         * @brief Obtém o ID do pedido.
         * @return ID do pedido.
         */
        int getId() const { return id; }

        /**
         * @brief Obtém o local de origem do pedido.
         * @return Referência para o objeto Local que representa a origem do pedido.
         */
        const Local& getOrigem() const { return origem; }

        /**
         * @brief Obtém o local de destino do pedido.
         * @return Referência para o objeto Local que representa o destino do pedido.
         */
        const Local& getDestino() const { return destino; }

        /**
         * @brief Obtém o peso do pedido.
         * @return Peso do pedido em quilogramas.
         */
        float getPeso() const { return peso; }

        /**
         * @brief Obtém o status do pedido.
         * @return true se o pedido foi concluído, false se está pendente.
         */
        bool getStatus() const { return status; }

        /**
         * @brief Define o ID do pedido.
         * @param novoId Novo ID a ser atribuído ao pedido.
         * @return true se o ID foi definido com sucesso, false se o ID é inválido.
         */
        bool setId(int novoId) {
            id = novoId;
            return true;
        }

        /**
         * @brief Define o local de origem do pedido.
         * @param novaOrigem Novo local a ser atribuído como origem do pedido.
         * @return true se a origem foi definida com sucesso.
         */
        bool setOrigem(const Local& novaOrigem) {
            origem = novaOrigem;
            return true;
        }

        /**
         * @brief Define o local de destino do pedido.
         * @param novoDestino Novo local a ser atribuído como destino do pedido.
         * @return true se o destino foi definido com sucesso.
         */
        bool setDestino(const Local& novoDestino) {
            destino = novoDestino;
            return true;
        }

        /**
         * @brief Define o peso do pedido.
         * @param novoPeso Novo peso a ser atribuído ao pedido em quilogramas.
         * @return true se o peso foi definido com sucesso, false se o peso é inválido.
         */
        bool setPeso(float novoPeso) {
            if (novoPeso <= 0) {
                std::cerr << "Peso deve ser maior que 0 Kg." << std::endl;
                return false;
            }
            if (std::isnan(novoPeso)) {
                std::cerr << "Peso inválido." << std::endl;
                return false;
            }
            peso = novoPeso;
            return true;
        }

        /**
         * @brief Define o status do pedido.
         * @param novoStatus Novo status a ser atribuído ao pedido (true = concluído, false = pendente).
         * @return true se o status foi definido com sucesso.
         */
        bool setStatus(bool novoStatus) {
            status = novoStatus;
            return true;
        }

}; 

#endif // PEDIDO_H