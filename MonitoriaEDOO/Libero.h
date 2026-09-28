#ifndef LIBERO_H
#define LIBERO_H

#include <iostream>
#include <string>
#include "Jogador.h"

class Libero : public Jogador {
    int defesas;
public:
    Libero(std::string n = "SemNome", double p = 0.0, double a = 0.0, int d = 0);

    int getDefesas() const;
    void setDefesas(int d);
};

std::istream& operator>>(std::istream& in, Libero& j);
std::ostream& operator<<(std::ostream& out, const Libero& j);

#endif
