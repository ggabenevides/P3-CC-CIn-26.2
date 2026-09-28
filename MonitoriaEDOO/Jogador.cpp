#include <iomanip>
#include "Jogador.h"
#include "ExcecaoDadosInvalidos.h"

using namespace std;

Jogador::Jogador(string n, double p, double a, int cod)
    : nome(n), peso(p), altura(a), codigoPosicao(cod) {}

string Jogador::getNome() const { return nome; }
void Jogador::setNome(string n) { nome = n; }
double Jogador::getPeso() const { return peso; }
void Jogador::setPeso(double p) { peso = p; }
double Jogador::getAltura() const { return altura; }
void Jogador::setAltura(double a) { altura = a; }
int Jogador::getCodigoPosicao() const { return codigoPosicao; }
void Jogador::setCodigoPosicao(int c) { codigoPosicao = c; }

// Leitura + validacao com retry, tudo dentro do operator>>
istream& operator>>(istream& in, Jogador& j) {
    bool valido = false;
    while (!valido) {
        string nome;
        double peso, altura;
        in >> nome >> peso >> altura;

        try {
            if (peso <= 0 || altura <= 0) {
                throw ExcecaoDadosInvalidos(
                    "Dados invalidos para " + nome + ": peso e altura devem ser > 0");
            }
            j.setNome(nome);
            j.setPeso(peso);
            j.setAltura(altura);
            valido = true;
        } catch (const ExcecaoDadosInvalidos& e) {
            cout << "[ERRO] " << e.mensagem() << " -- digite novamente." << endl;
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Jogador& j) {
    out << "Nome: " << j.getNome()
        << " | Peso: " << fixed << setprecision(1) << j.getPeso() << "kg"
        << " | Altura: " << fixed << setprecision(2) << j.getAltura() << "m";
    return out;
}
