#include "Libero.h"

using namespace std;

Libero::Libero(string n, double p, double a, int d)
    : Jogador(n, p, a, 2), defesas(d) {}

int Libero::getDefesas() const { return defesas; }
void Libero::setDefesas(int d) { defesas = d; }

istream& operator>>(istream& in, Libero& j) {
    in >> static_cast<Jogador&>(j);
    int d;
    in >> d;
    j.setDefesas(d);
    return in;
}

ostream& operator<<(ostream& out, const Libero& j) {
    out << "[Libero] " << static_cast<const Jogador&>(j)
        << " | Defesas: " << j.getDefesas() << endl;
    return out;
}
