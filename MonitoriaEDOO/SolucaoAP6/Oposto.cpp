#include "Oposto.h"
#include "Excecoes.h"
#include <iostream>
#include <iomanip>

Oposto::Oposto(std::string nome, double peso, double altura, double forcaSaque)
    : Jogador(nome, peso, altura, 4), forcaSaque(forcaSaque) {}

double Oposto::getForcaSaque() const { return forcaSaque; }
void Oposto::setForcaSaque(double forcaSaque) { this->forcaSaque = forcaSaque; }

void Oposto::scanner() {
    Jogador::scanner();
    std::cin >> forcaSaque;
        if (forcaSaque <= 0) {
            throw ExcecaoAtributoInvalido(
                "Força do saque invalida para " + nome + " (tem que ser maior que zero)");
        }
}


void Oposto::printer() {
    std::cout << "[Oposto] ";
    Jogador::printer();
    std::cout << " | Forca Saque: " << std::fixed << std::setprecision(1)
               << forcaSaque << " km/h" << std::endl;
}