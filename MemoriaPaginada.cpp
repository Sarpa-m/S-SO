#include "MemoriaPaginada.hpp"
#include <iostream>
#include <cmath>

MemoriaPaginada::MemoriaPaginada(int total, int pagina)
    : tamanhoTotal(total), tamanhoPagina(pagina) {
    totalPaginas = total / pagina;
    paginas.resize(totalPaginas, false);
    std::cout << "[*] Gerenciador de memoria paginada iniciado\n";
}

bool MemoriaPaginada::alocar(Processo* p) {
    if (alocacoes.find(p->getPid()) != alocacoes.end()) {
        std::cout << "[*] Processo " << p->getPid() << " ja possui paginas alocadas\n";
        return true; // Ja esta alocado, nao precisa alocar de novo
    }

    int paginasNecessarias = std::ceil((double)p->getTempoExecucao() / 2);
    std::vector<int> alocadas;

    for (size_t i = 0; i < paginas.size() && alocadas.size() < (size_t)paginasNecessarias; ++i) {
        if (!paginas[i]) {
            paginas[i] = true;
            alocadas.push_back(i);
        }
    }

    if (alocadas.size() == (size_t)paginasNecessarias) {
        alocacoes[p->getPid()] = alocadas;
        std::cout << "[*] Processo " << p->getPid() << " alocado em " << alocadas.size() << " paginas\n";
        return true;
    }

    for (int i : alocadas) {
        paginas[i] = false;
    }
    std::cout << "[!] Falha na alocacao para processo " << p->getPid() << " - memoria insuficiente\n";
    return false;
}

void MemoriaPaginada::liberar(Processo* p) {
    auto it = alocacoes.find(p->getPid());
    if (it != alocacoes.end()) {
        for (int i : it->second) {
            paginas[i] = false;
        }
        alocacoes.erase(it);
        std::cout << "[*] Memoria liberada para processo " << p->getPid() << "\n";
    }
}

int MemoriaPaginada::getMemoriaDisponivel() const {
    int livres = 0;
    for (bool ocupada : paginas) {
        if (!ocupada) ++livres;
    }
    return livres * tamanhoPagina;
}
