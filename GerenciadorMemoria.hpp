#ifndef GERENCIADOR_MEMORIA_HPP
#define GERENCIADOR_MEMORIA_HPP

#include "Processo.hpp"

class GerenciadorMemoria {
public:
    virtual ~GerenciadorMemoria() {}
    virtual bool alocar(Processo* p) = 0;
    virtual void liberar(Processo* p) = 0;
    virtual int getMemoriaDisponivel() const = 0;
};

#endif