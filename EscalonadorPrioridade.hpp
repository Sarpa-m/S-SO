#ifndef ESCALONADOR_PRIORIDADE_HPP
#define ESCALONADOR_PRIORIDADE_HPP

#include "Escalonador.hpp"

class EscalonadorPrioridade : public Escalonador {
public:
    Processo* selecionarProximo(std::vector<Processo*>& fila) override;
};

#endif
