#ifndef MEMORIA_PARTICOES_FIXAS_HPP
#define MEMORIA_PARTICOES_FIXAS_HPP

#include "GerenciadorMemoria.hpp"
#include <vector>
#include <map>

class MemoriaParticoesFixas : public GerenciadorMemoria {
private:
    int tamanhoTotal;
    int tamanhoParticao;
    std::vector<bool> particoes;
    std::map<int, int> alocacoes;

public:
    MemoriaParticoesFixas(int tamanhoTotal, int tamanhoParticao);
    bool alocar(Processo* p) override;
    void liberar(Processo* p) override;
    int getMemoriaDisponivel() const override;
};

#endif
