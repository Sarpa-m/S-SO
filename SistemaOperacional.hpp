#ifndef SISTEMA_OPERACIONAL_HPP
#define SISTEMA_OPERACIONAL_HPP

#include <vector>
#include <memory>
#include "Processo.hpp"
#include "Escalonador.hpp"
#include "GerenciadorMemoria.hpp"
#include "DispositivoES.hpp"

struct ProcessoBase {
    int pid;
    int prioridade;
    int tempoChegada;
    int tempoExecucao;
};

class SistemaOperacional {
private:
    std::vector<Processo*> processos;
    std::unique_ptr<Escalonador> escalonador;
    std::unique_ptr<GerenciadorMemoria> gerenciadorMemoria;
    std::vector<ProcessoBase> processosBase;
    int tempoGlobal;

public:
    SistemaOperacional(std::unique_ptr<Escalonador> esc, std::unique_ptr<GerenciadorMemoria> mem);
    ~SistemaOperacional();

    void definirProcessosBase(const std::vector<ProcessoBase>& base);
    const std::vector<ProcessoBase>& getProcessosBase() const;
    void listarProcessosBase() const;
    void instanciarProcessos();
    void executar();
    void exibirResumo();
};

#endif