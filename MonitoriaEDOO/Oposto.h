#ifndef OPOSTO_H
#define OPOSTO_H

#include <iostream>
#include <string>
#include "Jogador.h"

class Oposto : public Jogador {
    double forcaSaque;
public:
    Oposto(std::string n = "SemNome", double p = 0.0, double a = 0.0, double f = 0.0);

    double getForcaSaque() const;
    void setForcaSaque(double f);
};

std::istream& operator>>(std::istream& in, Oposto& j);
std::ostream& operator<<(std::ostream& out, const Oposto& j);

#endif
