#ifndef FUNC_localService_H
#define FUNC_localService_H

#include <iostream>
#include <vector>
#include <cstring>
#include "classes/Endereco.h"
#include "classes/Local.h"
#include "funcs/verificadores/verificadorLocal.h"
#include "database/repositorio.h"

class LocalService {
    private:
        Repositorio* repositorio;
    public:
        LocalService() = default;
        LocalService(Repositorio* repo) : repositorio(repo) {}
        
        // ================== CRUD PARA LOCAIS ==================
        int criarLocal(const Endereco& endereco, double x, double y) {
            Local novo(endereco, x, y);
            novo.setEndereco(endereco);
            if(!novo.setCoordenadaX(x))
                return -1; // Retorna -1 se coordenada X for inválida
            if(!novo.setCoordenadaY(y))
                return -1; // Retorna -1 se coordenada Y for inválida
            return repositorio->addLocal(novo);;
        }

        Local* lerLocal(int id) {
            return repositorio->getLocal(id);
        }

        bool atualizarLocal(int id, const Endereco& novoEndereco, double novoX, double novoY) {
            Local* local = repositorio->getLocal(id);
            if (!local) return false; // Local não encontrado

            local->setEndereco(novoEndereco);
            if (!local->setCoordenadaX(novoX)) {
                return false;
            }
            if (!local->setCoordenadaY(novoY)) {
                return false;
            }
            repositorio->updateLocal(*local);
            return true;
        }

        bool deletarLocal(int id) {
            try {
                repositorio->removeLocal(id);
                return true;
            } catch (const std::runtime_error& e) {
                std::cerr << "Erro ao deletar local: " << e.what() << std::endl;
                return false;
            }
        }

        std::vector<Local> listarLocais() {
            return repositorio->getAllLocal();
        }
};

#endif // FUNC_localServices_H
