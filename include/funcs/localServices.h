#ifndef FUNC_localServices_H
#define FUNC_localServices_H

#include <iostream>
#include <vector>
#include <cstring>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "funcs/verificadores/verificadorLocal.h"

class LocalServices {
    private:
        class Local locais[100];
        int proximoIdLocal = 0;
    public:
        LocalServices() = default;
        
        // ================== CRUD PARA LOCAIS ==================
        int criarLocal(const Endereco& endereco, double x, double y) {
            if (!verificaLocal(Local(endereco, x, y))) {
                return -1;
            }
            Local novo(endereco, x, y);
            locais[proximoIdLocal] = novo;
            return proximoIdLocal++;
        }

        Local* lerLocal(int id) {
            if (id < 0 || id >= proximoIdLocal) return nullptr;
            return &locais[id];
        }

        bool atualizarLocal(int id, const Endereco& novoEndereco, double novoX, double novoY) {
            if (id < 0 || id >= proximoIdLocal) return false;
            Local atualizado(novoEndereco, novoX, novoY);
            if (!verificaLocal(atualizado)) {
                return false;
            }
            locais[id] = atualizado;
            return true;
        }

        bool deletarLocal(int id) {
            if (id < 0 || id >= proximoIdLocal) return false;
            // Para deletar, movemos o último local para a posição do deletado
            locais[id] = locais[--proximoIdLocal];
            return true;
        }

        std::vector<Local> listarLocais() {
            std::vector<Local> resultado;
            for (int i = 0; i < proximoIdLocal; ++i) {
                resultado.push_back(locais[i]);
            }
            return resultado;
        }

}
