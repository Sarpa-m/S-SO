#include "EscalonadorPrioridade.hpp"
#include <iostream>
#include <limits>

Processo* EscalonadorPrioridade::selecionarProximo(std::vector<Processo*>& fila) {
    Processo* escolhido = nullptr;
    int menorPrioridade = std::numeric_limits<int>::max();

    for (auto* p : fila) {
        if (p->getEstado() == "Pronto" && p->getPrioridade() < menorPrioridade) {
            escolhido = p;
            menorPrioridade = p->getPrioridade();
        }
    }

    if (escolhido) {
        std::cout << "[*] Escalonador de prioridade selecionou processo " << escolhido->getPid() << "\n";
    }
    else {
        std::cout << "[!] Nenhum processo pronto na fila\n";
    }

    return escolhido;
}