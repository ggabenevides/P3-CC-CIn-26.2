#include "Relatorio.h"
#include "Ponta.h"
#include "Libero.h"
#include "Levantador.h"
#include "Oposto.h"
#include "Central.h"
#include "Excecoes.h"
#include <iostream>

// requisito 3 da questão 2
void gerarRelatorio(Jogador* titulares[6]) {
    for (int i = 0; i < 6; i++) {
        try
        {
                switch (titulares[i]->getCodigoPosicao()) {
                case 1: { // Ponta
                    Ponta* jogador = static_cast<Ponta*>(titulares[i]);
                    jogador->printer();
                    break;
                }
                case 2: { // Libero
                    Libero* jogador = static_cast<Libero*>(titulares[i]);
                    jogador->printer();
                    break;
                }
                case 3: { // Levantador
                    Levantador* jogador = static_cast<Levantador*>(titulares[i]);
                    jogador->printer();
                    break;
                }
                case 4: { // Oposto
                    Oposto* jogador = static_cast<Oposto*>(titulares[i]);
                    jogador->printer();
                    break;
                }
                case 5: { // Central
                    Central* jogador = static_cast<Central*>(titulares[i]);
                    jogador->printer();
                    break;
                }
                default:
                    throw ExcecaoPosicaoInvalida(
                        "Jogador na posicao " + to_string(i) + " possui codigo de posicao invalido");
            }
        }
        catch(const ExcecaoJogador& e)
        {
            cout << "[ERRO] " << e.mensagem() << " -- jogador ignorado no relatorio." << endl;
        } 
    }
}