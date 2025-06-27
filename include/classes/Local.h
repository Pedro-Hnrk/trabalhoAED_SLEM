#ifndef LOCAL_H
#define LOCAL_H

#include <iostream>
#include <vector>
#include <cstring>
#include "Endereco.h"

class Local {
    private:
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
        void setEndereco(const Endereco& novoEndereco) {
            endereco = novoEndereco;
        }
    
        void setCoordenadaX(double x) {
            if (std::isnan(x)) {
                std::cerr << "Coordenada X inválida." << std::endl;
                return;
            }
            coordenadaX = x;
        }

        void setCoordenadaY(double y) {
            if (std::isnan(y)) {
                std::cerr << "Coordenada Y inválida." << std::endl;
                return;
            }
            coordenadaY = y;
        }
};

#endif // LOCAL_H
