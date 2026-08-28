#ifndef OPOSTO_H
#define OPOSTO_H

#include "Jogador.h"

class Oposto : public Jogador {
private:
    double forcaSaque; 

public:
    
    Oposto(std::string nome = "", double peso = 0.0, double altura = 0.0, double forcaSaque = 0.0);

    double getForcaSaque() const;
    void setForcaSaque(double forcaSaque);

    void scanner();
    void printer();
};

#endif