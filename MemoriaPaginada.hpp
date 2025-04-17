// MEMORIAPAGINADA.HPP
#ifndef MEMORIA_PAGINADA_HPP
#define MEMORIA_PAGINADA_HPP

#include "GerenciadorMemoria.hpp"
#include <vector>
#include <map>

class MemoriaPaginada : public GerenciadorMemoria {
private:
    int tamanhoTotal;
    int tamanhoPagina;
    int totalPaginas;
    std::vector<bool> paginas;
    std::map<int, std::vector<int>> alocacoes;

public:
    MemoriaPaginada(int tamanhoTotal, int tamanhoPagina);
    bool alocar(Processo* p) override;
    void liberar(Processo* p) override;
    int getMemoriaDisponivel() const override;
};

#endif