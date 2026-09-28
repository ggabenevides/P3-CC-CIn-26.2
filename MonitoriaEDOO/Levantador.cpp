#include "Levantador.h"

using namespace std;

Levantador::Levantador(string n, double p, double a, int as)
    : Jogador(n, p, a, 3), assistencias(as) {}

int Levantador::getAssistencias() const { return assistencias; }
void Levantador::setAssistencias(int as) { assistencias = as; }

istream& operator>>(istream& in, Levantador& j) {
    in >> static_cast<Jogador&>(j);
    int as;
    in >> as;
    j.setAssistencias(as);
    return in;
}

ostream& operator<<(ostream& out, const Levantador& j) {
    out << "[Levantador] " << static_cast<const Jogador&>(j)
        << " | Assistencias: " << j.getAssistencias() << endl;
    return out;
}
