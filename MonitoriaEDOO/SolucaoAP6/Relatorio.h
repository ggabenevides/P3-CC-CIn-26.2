#ifndef RELATORIO_H
#define RELATORIO_H

#include "Jogador.h"

// Percorre o time, identifica a posicao de cada jogador via codigoPosicao
// e realiza o downcasting (static_cast) para chamar o printer() especifico.
void gerarRelatorio(Jogador* titulares[6]);

#endif