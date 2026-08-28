#include "Ponta.h"
#include "Libero.h"
#include "Levantador.h"
#include "Oposto.h"
#include "Central.h"
#include "Relatorio.h"

int main() {
    // Formacao didatica simplificada: 2 Pontas, 1 Libero, 1 Levantador, 1 Oposto, 1 Central
    Ponta ponta1;
    Ponta ponta2;
    Libero libero;
    Levantador levantador;
    Oposto oposto;
    Central central;

    // Leitura na ordem: Ponta1, Ponta2, Libero, Levantador, Oposto, Central usando a função criada na questão 2 --> requisito 4
    ponta1.lerComValidacao(); 
    ponta2.lerComValidacao() ;
    libero.lerComValidacao();
    levantador.lerComValidacao() ;
    oposto.lerComValidacao();
    central.lerComValidacao() ;

    // Upcasting implicito: guardando os enderecos em um array de ponteiros para a base
    Jogador* time[6];
    time[0] = &ponta1;
    time[1] = &ponta2;
    time[2] = &libero;
    time[3] = &levantador;
    time[4] = &oposto;
    time[5] = &central;

    gerarRelatorio(time);

    return 0;
}