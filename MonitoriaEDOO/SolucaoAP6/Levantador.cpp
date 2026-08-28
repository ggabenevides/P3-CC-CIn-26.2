#include "Levantador.h"
#include "Excecoes.h"
#include <iostream>

Levantador::Levantador(std::string nome, double peso, double altura, int assistencias)
    : Jogador(nome, peso, altura, 3), assistencias(assistencias) {}

int Levantador::getAssistencias() const { return assistencias; }
void Levantador::setAssistencias(int assistencias) { this->assistencias = assistencias; }

void Levantador::scanner() {
    Jogador::scanner();
    std::cin >> assistencias;
    if (assistencias < 0) {
    throw ExcecaoAtributoInvalido("Numero de assistencias invalido para " + nome + " (nao pode ser negativo)");
    }
}

void Levantador::printer() {
    std::cout << "[Levantador] ";
    Jogador::printer();
    std::cout << " | Assistencias: " << assistencias << std::endl;
}