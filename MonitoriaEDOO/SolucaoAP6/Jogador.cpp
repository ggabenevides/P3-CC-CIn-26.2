#include "Jogador.h"
#include "Excecoes.h"
#include <iostream>
#include <iomanip>

Jogador::Jogador(std::string nome, double peso, double altura, int codigoPosicao)
    : nome(nome), peso(peso), altura(altura), codigoPosicao(codigoPosicao) {}

Jogador::~Jogador() {}

std::string Jogador::getNome() const { return nome; }
double Jogador::getPeso() const { return peso; }
double Jogador::getAltura() const { return altura; }
int Jogador::getCodigoPosicao() const { return codigoPosicao; }


void Jogador::setNome(std::string nome) { this->nome = nome; }
void Jogador::setPeso(double peso) { this->peso = peso; }
void Jogador::setAltura(double altura) { this->altura = altura; }
void Jogador::setCodigoPosicao(int codigoPosicao) { this->codigoPosicao = codigoPosicao; }

void Jogador::scanner() {
    std::cin >> nome >> peso >> altura;
    // linhas abaixo adicionadas só no exercício 2
     if (peso <= 0 || altura <= 0) {
            throw ExcecaoDadosInvalidos(
                "Dados invalidos para " + nome + ": peso e altura devem ser > 0");
        }
}

void Jogador::printer() {
    std::cout << "Nome: " << nome
               << " | Peso: " << std::fixed << std::setprecision(1) << peso << "kg"
               << " | Altura: " << std::fixed << std::setprecision(2) << altura << "m";
}

// p o exercicio 2 --> requisito 4
void Jogador::lerComValidacao() {
    bool valido = false;
    while (!valido) {
        try {
            this->scanner();   // despacho virtual: chama a versao da classe derivada
            valido = true;
        } catch (const ExcecaoAtributoInvalido& e) {
            cout << "[ERRO] " << e.mensagem() << " -- digite novamente." << endl;
        } catch (const ExcecaoDadosInvalidos& e) {
            cout << "[ERRO] " << e.mensagem() << " -- digite novamente." << endl;
        } catch (const ExcecaoJogador& e) {
            cout << "[ERRO] " << e.mensagem() << " -- digite novamente." << endl;
        }
    }
}