#ifndef CENTRAL_H
#define CENTRAL_H

#include <iostream>
#include <string>
#include "Jogador.h"

class Central : public Jogador {
    int bloqueios;
public:
    Central(std::string n = "SemNome", double p = 0.0, double a = 0.0, int b = 0);

    int getBloqueios() const;
    void setBloqueios(int b);
};

std::istream& operator>>(std::istream& in, Central& j);
std::ostream& operator<<(std::ostream& out, const Central& j);

#endif
