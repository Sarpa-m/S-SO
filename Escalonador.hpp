// ESCALONADOR.HPP
#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include <vector>
#include "Processo.hpp"

class Escalonador {
public:
    virtual ~Escalonador() {}
    virtual Processo* selecionarProximo(std::vector<Processo*>& fila) = 0;
    virtual int getQuantum() const { return -1; }
};

#endif
