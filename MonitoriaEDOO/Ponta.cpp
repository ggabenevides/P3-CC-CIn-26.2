#include <iomanip>
#include "Ponta.h"

using namespace std;

Ponta::Ponta(string n, double p, double a, double v)
    : Jogador(n, p, a, 1), velocidadeAtaque(v) {}

double Ponta::getVelocidadeAtaque() const { return velocidadeAtaque; }
void Ponta::setVelocidadeAtaque(double v) { velocidadeAtaque = v; }

istream& operator>>(istream& in, Ponta& j) {
    in >> static_cast<Jogador&>(j);
    double v;
    in >> v;
    j.setVelocidadeAtaque(v);
    return in;
}

ostream& operator<<(ostream& out, const Ponta& j) {
    out << "[Ponta] " << static_cast<const Jogador&>(j)
        << " | Vel. Ataque: " << fixed << setprecision(1)
        << j.getVelocidadeAtaque() << " km/h" << endl;
    return out;
}
