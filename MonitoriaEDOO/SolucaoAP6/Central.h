#ifndef CENTRAL_H
#define CENTRAL_H

#include "Jogador.h"

class Central : public Jogador {
private:
    int bloqueios;

public:
    Central(std::string nome = "", double peso = 0.0, double altura = 0.0, int bloqueios = 0);

    int getBloqueios() const;
    void setBloqueios(int bloqueios);

    void scanner();
    void printer();
};

#endif