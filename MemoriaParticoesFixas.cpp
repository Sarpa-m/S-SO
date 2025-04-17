#include "MemoriaParticoesFixas.hpp"
#include <iostream>

MemoriaParticoesFixas::MemoriaParticoesFixas(int total, int particao)
    : tamanhoTotal(total), tamanhoParticao(particao) {
    int qtdParticoes = total / particao;
    particoes.resize(qtdParticoes, false);
    std::cout << "[*] Gerenciador de memoria por particoes fixas iniciado\n";
}

bool MemoriaParticoesFixas::alocar(Processo* p) {
    for (size_t i = 0; i < particoes.size(); ++i) {
        if (!particoes[i]) {
            particoes[i] = true;
            alocacoes[p->getPid()] = i;
            std::cout << "[*] Processo " << p->getPid() << " alocado na particao " << i << "\n";
            return true;
        }
    }
    std::cout << "[!] Falha na alocacao para processo " << p->getPid() << " - sem particoes disponiveis\n";
    return false;
}

void MemoriaParticoesFixas::liberar(Processo* p) {
    auto it = alocacoes.find(p->getPid());
    if (it != alocacoes.end()) {
        int idx = it->second;
        particoes[idx] = false;
        alocacoes.erase(it);
        std::cout << "[*] Particao " << idx << " liberada para processo " << p->getPid() << "\n";
    }
}

int MemoriaParticoesFixas::getMemoriaDisponivel() const {
    int livres = 0;
    for (bool ocupada : particoes) {
        if (!ocupada) ++livres;
    }
    return livres * tamanhoParticao;
}
