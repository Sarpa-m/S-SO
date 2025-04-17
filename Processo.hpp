// PROCESSO.HPP
#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <string>

class Processo {
private:
    int pid;
    int prioridade;
    int tempoChegada;
    int tempoExecucao;
    int tempoRestante;
    std::string estado; // Pronto, Executando, Bloqueado, Finalizado

public:
    Processo(int pid, int prioridade, int tempoChegada, int tempoExecucao);

    int getPid() const;
    int getPrioridade() const;
    int getTempoChegada() const;
    int getTempoExecucao() const;
    int getTempoRestante() const;
    std::string getEstado() const;

    void setEstado(const std::string& novoEstado);
    void executar(int tempo);
    bool finalizado() const;
};

#endif