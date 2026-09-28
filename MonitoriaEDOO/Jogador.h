#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>

class Jogador {
protected:
    std::string nome;
    double peso;
    double altura;
    int codigoPosicao;

public:
    Jogador(std::string n = "SemNome", double p = 0.0, double a = 0.0, int cod = 0);

    // getters/setters
    std::string getNome() const;
    void setNome(std::string n);
    double getPeso() const;
    void setPeso(double p);
    double getAltura() const;
    void setAltura(double a);
    int getCodigoPosicao() const;
    void setCodigoPosicao(int c);
};

// Operadores globais 
std::istream& operator>>(std::istream& in, Jogador& j);
std::ostream& operator<<(std::ostream& out, const Jogador& j);

#endif
