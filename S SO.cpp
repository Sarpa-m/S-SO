#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "SistemaOperacional.hpp"
#include "EscalonadorRoundRobin.hpp"
#include "EscalonadorPrioridade.hpp"
#include "MemoriaParticoesFixas.hpp"
#include "MemoriaPaginada.hpp"

int main() {
    std::srand(std::time(nullptr));
    std::vector<ProcessoBase> processosBase;
    int pidCounter = 1;
    bool executando = true;

    while (executando) {
        std::cout << "\n=== MENU DO SISTEMA ===\n";
        std::cout << "1 - Criar processos\n";
        std::cout << "2 - Listar processos\n";
        std::cout << "3 - Executar simulacao\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        int opcao;
        std::cin >> opcao;

        switch (opcao) {
        case 1: {
            int qtd;
            std::cout << "[*] Quantos processos deseja criar? ";
            std::cin >> qtd;

            processosBase.clear();
            for (int i = 0; i < qtd; ++i) {
                int prioridade = rand() % 10;
                int tempo = 2 + rand() % 8;
                processosBase.push_back({ pidCounter++, prioridade, 0, tempo });
            }
            std::cout << "[*] Processos base criados com sucesso.\n";
            break;
        }

        case 2: {
            if (processosBase.empty()) {
                std::cout << "[!] Nenhum processo criado.\n";
            }
            else {
                std::cout << "[*] Lista de processos:\n";
                for (const auto& p : processosBase) {
                    std::cout << "PID: " << p.pid << " | Prioridade: " << p.prioridade
                        << " | Chegada: " << p.tempoChegada << " | Execucao: " << p.tempoExecucao << "\n";
                }
            }
            break;
        }

        case 3: {
            if (processosBase.empty()) {
                std::cout << "[!] Nenhum processo criado ainda.\n";
                break;
            }

            std::cout << "[*] Tipo de escalonador:\n";
            std::cout << "1 - Round Robin\n";
            std::cout << "2 - Prioridade\n";
            int tipoEsc;
            std::cin >> tipoEsc;

            std::unique_ptr<Escalonador> esc;
            if (tipoEsc == 1) {
                int quantum;
                std::cout << "[*] Informe o quantum: ";
                std::cin >> quantum;
                esc = std::make_unique<EscalonadorRoundRobin>(quantum);
            }
            else {
                esc = std::make_unique<EscalonadorPrioridade>();
            }

            std::cout << "[*] Tipo de memoria:\n";
            std::cout << "1 - Particoes Fixas\n";
            std::cout << "2 - Paginada\n";
            int tipoMem;
            std::cin >> tipoMem;

            std::unique_ptr<GerenciadorMemoria> mem;
            if (tipoMem == 1)
                mem = std::make_unique<MemoriaParticoesFixas>(100, 10);
            else
                mem = std::make_unique<MemoriaPaginada>(100, 5);

            SistemaOperacional so(std::move(esc), std::move(mem));
            so.definirProcessosBase(processosBase);
            so.instanciarProcessos();
            so.executar();
            so.exibirResumo();
            break;
        }

        case 0:
            executando = false;
            std::cout << "[*] Encerrando...\n";
            break;

        default:
            std::cout << "[!] Opcao invalida.\n";
            break;
        }
    }

    return 0;
}
