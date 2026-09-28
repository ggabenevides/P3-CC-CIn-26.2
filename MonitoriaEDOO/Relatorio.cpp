#include <iostream>
#include "Relatorio.h"
#include "Ponta.h"
#include "Libero.h"
#include "Levantador.h"
#include "Oposto.h"
#include "Central.h"

using namespace std;

// Metodo estatico, downcasting via static_cast
void Relatorio::gerarRelatorio(Jogador* titulares[6]) {
    for (int i = 0; i < 6; i++) {
        switch (titulares[i]->getCodigoPosicao()) {
            case 1:
                cout << *static_cast<Ponta*>(titulares[i]);
                break;
            case 2:
                cout << *static_cast<Libero*>(titulares[i]);
                break;
            case 3:
                cout << *static_cast<Levantador*>(titulares[i]);
                break;
            case 4:
                cout << *static_cast<Oposto*>(titulares[i]);
                break;
            case 5:
                cout << *static_cast<Central*>(titulares[i]);
                break;
            default:
                cout << "[ERRO] codigo de posicao desconhecido, jogador ignorado." << endl;
        }
    }
}
