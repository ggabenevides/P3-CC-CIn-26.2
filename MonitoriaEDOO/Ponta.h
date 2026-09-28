
#ifndef PONTA_H
#define PONTA_H

#include <iostream>
#include <string>
#include "Jogador.h"

class Ponta : public Jogador {
    double velocidadeAtaque;
public:
    Ponta(std::string n = "SemNome", double p = 0.0, double a = 0.0, double v = 0.0);

    double getVelocidadeAtaque() const;
    void setVelocidadeAtaque(double v);
};

std::istream& operator>>(std::istream& in, Ponta& j);
std::ostream& operator<<(std::ostream& out, const Ponta& j);

#endif
