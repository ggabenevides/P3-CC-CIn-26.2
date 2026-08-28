#include "Libero.h"
#include "Excecoes.h"
#include <iostream>

Libero::Libero(std::string nome, double peso, double altura, int defesas)
    : Jogador(nome, peso, altura, 2), defesas(defesas) {}

int Libero::getDefesas() const { return defesas; }
void Libero::setDefesas(int defesas) { this->defesas = defesas; }

void Libero::scanner() {
    Jogador::scanner();
    std::cin >> defesas;
        if (defesas < 0) {
            throw ExcecaoAtributoInvalido(
                "Numero de defesas invalido para " + nome + " (nao pode ser negativo)");
        }
    }

void Libero::printer() {
    std::cout << "[Libero] ";
    Jogador::printer();
    std::cout << " | Defesas: " << defesas << std::endl;
}