#include "DispositivoES.hpp"
#include <iostream>

DispositivoES::DispositivoES(const std::string& nome)
    : nome(nome), ocupado(false), processoAtual(nullptr) {
    std::cout << "[*] Dispositivo " << nome << " inicializado\n";
}

void DispositivoES::requisitar(Processo* p) {
    fila.push(p);
    std::cout << "[*] Processo " << p->getPid() << " requisitou o dispositivo " << nome << "\n";
}

void DispositivoES::processar() {
    if (!ocupado && !fila.empty()) {
        processoAtual = fila.front();
        fila.pop();
        ocupado = true;
        std::cout << "[*] Processo " << processoAtual->getPid() << " esta usando o dispositivo " << nome << "\n";
    }
}

void DispositivoES::liberar() {
    if (ocupado) {
        std::cout << "[*] Dispositivo " << nome << " liberado pelo processo " << processoAtual->getPid() << "\n";
        processoAtual = nullptr;
        ocupado = false;
    }
}

bool DispositivoES::estaOcupado() const {
    return ocupado;
}

void DispositivoES::exibirFila() const {
    std::cout << "[*] Fila de espera do dispositivo " << nome << ": ";
    std::queue<Processo*> temp = fila;
    while (!temp.empty()) {
        std::cout << temp.front()->getPid() << " ";
        temp.pop();
    }
    std::cout << "\n";
}
