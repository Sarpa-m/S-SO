#include "SistemaOperacional.hpp"
#include <iostream>

SistemaOperacional::SistemaOperacional(std::unique_ptr<Escalonador> esc, std::unique_ptr<GerenciadorMemoria> mem)
    : escalonador(std::move(esc)), gerenciadorMemoria(std::move(mem)), tempoGlobal(0) {
    std::cout << "[*] Sistema operacional inicializado\n";
}

SistemaOperacional::~SistemaOperacional() {
    for (auto* p : processos) {
        gerenciadorMemoria->liberar(p);
        delete p;
    }
}

void SistemaOperacional::definirProcessosBase(const std::vector<ProcessoBase>& base) {
    processosBase = base;
    std::cout << "[*] Base de processos definida com " << base.size() << " processos\n";
}

const std::vector<ProcessoBase>& SistemaOperacional::getProcessosBase() const {
    return processosBase;
}

void SistemaOperacional::listarProcessosBase() const {
    if (processosBase.empty()) {
        std::cout << "[!] Nenhum processo criado ainda\n";
        return;
    }

    std::cout << "[*] Lista de processos base:\n";
    for (const auto& p : processosBase) {
        std::cout << "PID: " << p.pid << " | Prioridade: " << p.prioridade
            << " | Chegada: " << p.tempoChegada << " | Execucao: " << p.tempoExecucao << "\n";
    }
}

void SistemaOperacional::instanciarProcessos() {
    for (const auto& p : processosBase) {
        Processo* novo = new Processo(p.pid, p.prioridade, p.tempoChegada, p.tempoExecucao);
        processos.push_back(novo); // Sem alocar memoria ainda
    }
    std::cout << "[*] Processos instanciados: " << processos.size() << "\n";
}


void SistemaOperacional::executar() {
    std::cout << "[*] Iniciando execucao do sistema\n";
    bool processosRestantes = true;

    while (processosRestantes) {
        Processo* atual = escalonador->selecionarProximo(processos);
        if (atual) {
            if (atual->getEstado() == "Pronto") {
                // Tenta alocar memoria antes de executar
                bool alocado = gerenciadorMemoria->alocar(atual);
                if (!alocado) {
                    std::cout << "[!] Memoria insuficiente para processo " << atual->getPid() << "\n";
                    continue;
                }
                atual->setEstado("Executando");
            }

            int quantum = escalonador->getQuantum();
            int tempoExec = (quantum > 0) ? quantum : atual->getTempoRestante();
            atual->executar(tempoExec);
            tempoGlobal += tempoExec;

            if (atual->finalizado()) {
                gerenciadorMemoria->liberar(atual);
                atual->setEstado("Finalizado");
            }
            else {
                atual->setEstado("Pronto"); // Mantem alocacao de memoria
            }
        }
        else {
            std::cout << "[!] Nenhum processo pronto - aguardando\n";
            tempoGlobal += 1;
        }


        processosRestantes = false;
        for (auto* p : processos) {
            if (!p->finalizado()) {
                processosRestantes = true;
                break;
            }
        }
    }

    std::cout << "[*] Todos os processos foram finalizados\n";
}

void SistemaOperacional::exibirResumo() {
    std::cout << "[*] RESUMO DA EXECUCAO\n";
    std::cout << "Tempo total: " << tempoGlobal << " unidades\n";
    std::cout << "Memoria disponivel: " << gerenciadorMemoria->getMemoriaDisponivel() << "\n";
  
}
