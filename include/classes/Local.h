#ifndef LOCAL_H
#define LOCAL_H

#include <iostream>
#include <vector>
#include <cstring>
#include "Endereco.h"

class Local {
    private:
        int id;
        class Endereco endereco;
        double coordenadaX;
        double coordenadaY;
    public:
        Local() = default;
        Local(const Endereco& endereco, double x, double y)
            : endereco(endereco), coordenadaX(x), coordenadaY(y) {}
        const Endereco& getEndereco() const { return endereco; }
        double getCoordenadaX() const { return coordenadaX; }
        double getCoordenadaY() const { return coordenadaY; }
        int getId() const { return id; }

        bool setId(int novoId) {
            if (novoId < 0) {
                std::cerr << "ID inválido." << std::endl;
                return false;
            }
            id = novoId;
            return true;
        }

        void setEndereco(const Endereco& novoEndereco) {
            endereco = novoEndereco;
        }
    
        bool setCoordenadaX(double x) {
            if (std::isnan(x)) {
                std::cerr << "Coordenada X inválida." << std::endl;
                return false;
            }
            coordenadaX = x;
            return true;
        }

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
