#ifndef LEVANTADOR_H
#define LEVANTADOR_H

#include <iostream>
#include <string>
#include "Jogador.h"

class Levantador : public Jogador {
    int assistencias;
public:
    Levantador(std::string n = "SemNome", double p = 0.0, double a = 0.0, int as = 0);

    int getAssistencias() const;
    void setAssistencias(int as);
};

std::istream& operator>>(std::istream& in, Levantador& j);
std::ostream& operator<<(std::ostream& out, const Levantador& j);

#endif
