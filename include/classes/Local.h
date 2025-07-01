#ifndef LOCAL_H
#define LOCAL_H

#include <iostream>
#include <vector>
#include <cstring>
#include "Endereco.h"

/**
 * @class Local
 * @brief Representa um local no sistema, contendo informações como endereço, coordenadas e ID.
 */
class Local {
    private:
        int id;                     ///< ID único do local
        class Endereco endereco;    ///< Endereço do local
        double coordenadaX;         ///< Coordenada X do local
        double coordenadaY;         ///< Coordenada Y do local
    public:
        /**
         * @brief Construtor padrão.
         */
        Local() = default;

        /**
         * @brief Construtor parametrizado.
         * @param endereco Endereço do local.
         * @param x Coordenada X do local.
         * @param y Coordenada Y do local.
         */
        Local(const Endereco& endereco, double x, double y)
            : endereco(endereco), coordenadaX(x), coordenadaY(y) {}
        
        /**
         * @brief Obtém o endereço do local.
         * @return Referência para o objeto Endereco que representa o endereço do local.
         */
        const Endereco& getEndereco() const { return endereco; }

        /**
         * @brief Obtém a coordenada X do local.
         * @return Coordenada X do local.
         */
        double getCoordenadaX() const { return coordenadaX; }

        /**
         * @brief Obtém a coordenada Y do local.
         * @return Coordenada Y do local.
         */
        double getCoordenadaY() const { return coordenadaY; }

        /**
         * @brief Obtém o ID do local.
         * @return ID do local.
         */
        int getId() const { return id; }

        /**
         * @brief Define o ID do local.
         * @param novoId Novo ID a ser atribuído ao local.
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
         * @brief Define o endereço do local.
         * @param novoEndereco Novo endereço a ser atribuído ao local.
         */
        void setEndereco(const Endereco& novoEndereco) {
            endereco = novoEndereco;
        }
        
        /**
         * @brief Define a coordenada X do local.
         * @param x Coordenada X a ser atribuída ao local.
         * @return true se a coordenada X foi definida com sucesso, false se a coordenada é inválida.
         */
        bool setCoordenadaX(double x) {
            if (std::isnan(x)) {
                std::cerr << "Coordenada X inválida." << std::endl;
                return false;
            }
            coordenadaX = x;
            return true;
        }

        /**
         * @brief Define a coordenada Y do local.
         * @param y Coordenada Y a ser atribuída ao local.
         * @return true se a coordenada Y foi definida com sucesso, false se a coordenada é inválida.
         */
        bool setCoordenadaY(double y) {
            if (std::isnan(y)) {
                std::cerr << "Coordenada Y inválida." << std::endl;
                return false;
            }
            coordenadaY = y;
            return true;
        }
};

#endif // LOCAL_H
