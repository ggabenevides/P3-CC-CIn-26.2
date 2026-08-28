#include "Central.h"
#include "Excecoes.h"
#include <iostream>

Central::Central(std::string nome, double peso, double altura, int bloqueios)
    : Jogador(nome, peso, altura, 5), bloqueios(bloqueios) {}

int Central::getBloqueios() const { return bloqueios; }
void Central::setBloqueios(int bloqueios) { this->bloqueios = bloqueios; }

void Central::scanner() {
    Jogador::scanner();
    std::cin >> bloqueios;
    // linhas abaixo adicionadas só na resolução do exercício 2
    if (bloqueios < 0) {
    throw ExcecaoAtributoInvalido(
        "Numero de bloqueios invalido para " + nome + " (nao pode ser negativo)");
}
}

void Central::printer() {
    std::cout << "[Central] ";
    Jogador::printer();
    std::cout << " | Bloqueios: " << bloqueios << std::endl;
}