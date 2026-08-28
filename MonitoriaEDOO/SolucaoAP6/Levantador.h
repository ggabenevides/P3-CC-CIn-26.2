#ifndef LEVANTADOR_H
#define LEVANTADOR_H

#include "Jogador.h"

class Levantador : public Jogador {
private:
    int assistencias;

public:
    // codigoPosicao = 3, passado internamente ao construtor da base
    Levantador(std::string nome = "", double peso = 0.0, double altura = 0.0, int assistencias = 0);

    int getAssistencias() const;
    void setAssistencias(int assistencias);

    void scanner();
    void printer();
};

#endif