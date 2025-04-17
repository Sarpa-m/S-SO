#ifndef ESCALONADOR_ROUND_ROBIN_HPP
#define ESCALONADOR_ROUND_ROBIN_HPP

#include "Escalonador.hpp"
#include <cstddef>

class EscalonadorRoundRobin : public Escalonador {
private:
    int quantum;
    size_t indiceAtual;

public:
    EscalonadorRoundRobin(int quantum = 2);
    Processo* selecionarProximo(std::vector<Processo*>& fila) override;
    int getQuantum() const override;
};

#endif