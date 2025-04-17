#ifndef DISPOSITIVO_ES_HPP
#define DISPOSITIVO_ES_HPP

#include <string>
#include <queue>
#include "Processo.hpp"

class DispositivoES {
private:
    std::string nome;
    bool ocupado;
    Processo* processoAtual;
    std::queue<Processo*> fila;

public:
    DispositivoES(const std::string& nome);
    void requisitar(Processo* p);
    void processar();
    void liberar();
    bool estaOcupado() const;
    void exibirFila() const;
};

#endif