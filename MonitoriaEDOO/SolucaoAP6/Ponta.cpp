#include "Ponta.h"
#include "Excecoes.h"
#include <iostream>
#include <iomanip>

Ponta::Ponta(std::string nome, double peso, double altura, double velocidadeAtaque)
    : Jogador(nome, peso, altura, 1), velocidadeAtaque(velocidadeAtaque) {}

double Ponta::getVelocidadeAtaque() const { return velocidadeAtaque; }
void Ponta::setVelocidadeAtaque(double velocidadeAtaque) { this->velocidadeAtaque = velocidadeAtaque; }

void Ponta::scanner() {
    Jogador::scanner();
    std::cin >> velocidadeAtaque;
    if (velocidadeAtaque <= 0) {
        throw ExcecaoAtributoInvalido(
            "Velocidade de ataque invalida para " + nome + " (tem que ser maior que zero)");
    }
}

void Ponta::printer() {
    std::cout << "[Ponta] ";
    Jogador::printer();
    std::cout << " | Vel. Ataque: " << std::fixed << std::setprecision(1)
               << velocidadeAtaque << " km/h" << std::endl;
}