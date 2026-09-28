#include <iomanip>
#include "Oposto.h"

using namespace std;

Oposto::Oposto(string n, double p, double a, double f)
    : Jogador(n, p, a, 4), forcaSaque(f) {}

double Oposto::getForcaSaque() const { return forcaSaque; }
void Oposto::setForcaSaque(double f) { forcaSaque = f; }

istream& operator>>(istream& in, Oposto& j) {
    in >> static_cast<Jogador&>(j);
    double f;
    in >> f;
    j.setForcaSaque(f);
    return in;
}

ostream& operator<<(ostream& out, const Oposto& j) {
    out << "[Oposto] " << static_cast<const Jogador&>(j)
        << " | Forca Saque: " << fixed << setprecision(1)
        << j.getForcaSaque() << " km/h" << endl;
    return out;
}
