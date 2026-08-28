#ifndef LIBERO_H
#define LIBERO_H

#include "Jogador.h"

class Libero : public Jogador {
private:
    int defesas;

public:
    Libero(std::string nome = "", double peso = 0.0, double altura = 0.0, int defesas = 0);

    int getDefesas() const;
    void setDefesas(int defesas);

    void scanner();
    void printer();
};

#endif