#ifndef PONTA_H
#define PONTA_H

#include "Jogador.h"

class Ponta : public Jogador {
private:
    double velocidadeAtaque;

public:
    Ponta(std::string nome = "", double peso = 0.0, double altura = 0.0, double velocidadeAtaque = 0.0);

    double getVelocidadeAtaque() const;
    void setVelocidadeAtaque(double velocidadeAtaque);

    void scanner();
    void printer();
};

#endif