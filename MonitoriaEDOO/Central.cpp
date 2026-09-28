#include "Central.h"

using namespace std;

Central::Central(string n, double p, double a, int b)
    : Jogador(n, p, a, 5), bloqueios(b) {}

int Central::getBloqueios() const { return bloqueios; }
void Central::setBloqueios(int b) { bloqueios = b; }

istream& operator>>(istream& in, Central& j) {
    in >> static_cast<Jogador&>(j);
    int b;
    in >> b;
    j.setBloqueios(b);
    return in;
}

ostream& operator<<(ostream& out, const Central& j) {
    out << "[Central] " << static_cast<const Jogador&>(j)
        << " | Bloqueios: " << j.getBloqueios() << endl;
    return out;
}
