#include "EscalonadorRoundRobin.hpp"
#include <iostream>

EscalonadorRoundRobin::EscalonadorRoundRobin(int quantum)
    : quantum(quantum), indiceAtual(0) {
    std::cout << "[*] Escalonador Round Robin criado com quantum = " << quantum << "\n";
}

Processo* EscalonadorRoundRobin::selecionarProximo(std::vector<Processo*>& fila) {
    if (fila.empty()) {
        std::cout << "[!] Fila de processos vazia\n";
        return nullptr;
    }

    for (size_t i = 0; i < fila.size(); ++i) {
        size_t index = (indiceAtual + i) % fila.size();
        Processo* p = fila[index];
        if (p->getEstado() == "Pronto") {
            indiceAtual = (index + 1) % fila.size();
            std::cout << "[*] Round Robin selecionou processo " << p->getPid() << "\n";
            return p;
        }
    }

    std::cout << "[!] Nenhum processo pronto na fila\n";
    return nullptr;
}

int EscalonadorRoundRobin::getQuantum() const {
    return quantum;
}