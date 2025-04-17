#include "Processo.hpp"
#include <iostream>

Processo::Processo(int pid, int prioridade, int tempoChegada, int tempoExecucao)
    : pid(pid), prioridade(prioridade), tempoChegada(tempoChegada), tempoExecucao(tempoExecucao),
    tempoRestante(tempoExecucao), estado("Pronto") {
    std::cout << "[*] Processo criado - PID: " << pid << ", Prioridade: " << prioridade
        << ", Tempo de execucao: " << tempoExecucao << "\n";
}

int Processo::getPid() const {
    return pid;
}

int Processo::getPrioridade() const {
    return prioridade;
}

int Processo::getTempoChegada() const {
    return tempoChegada;
}

int Processo::getTempoExecucao() const {
    return tempoExecucao;
}

int Processo::getTempoRestante() const {
    return tempoRestante;
}

std::string Processo::getEstado() const {
    return estado;
}

void Processo::setEstado(const std::string& novoEstado) {
    estado = novoEstado;
    std::cout << "[*] Estado do processo " << pid << " alterado para: " << estado << "\n";
}

void Processo::executar(int tempo) {
    if (tempoRestante > 0) {
        int executado = (tempoRestante >= tempo) ? tempo : tempoRestante;
        tempoRestante -= executado;
        std::cout << "[*] Processo " << pid << " executando por " << executado << " unidades de tempo\n";
        if (tempoRestante <= 0) {
            tempoRestante = 0;
            estado = "Finalizado";
            std::cout << "[*] Processo " << pid << " finalizado\n";
        }
    }
}

bool Processo::finalizado() const {
    return tempoRestante <= 0;
}
