#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

class Jogador {
protected:
    std::string nome;
    double peso;
    double altura;
    int codigoPosicao;

public:
    // Construtor com parametros (tambem serve como construtor padrao via defaults)
    Jogador(std::string nome = "", double peso = 0.0, double altura = 0.0, int codigoPosicao = 0);

    // Getters
    std::string getNome() const;
    double getPeso() const;
    double getAltura() const;
    int getCodigoPosicao() const;

    // Setters
    void setNome(std::string nome);
    void setPeso(double peso);
    void setAltura(double altura);
    void setCodigoPosicao(int codigoPosicao);

    // Leitura e exibicao dos dados basicos
    void scanner();
    void lerComValidacao(); // adicionado no exercicio 2
    void printer();

    ~Jogador();
};

#endif