#include <algorithm>
#include <iostream>

using namespace std;

int n; 
int c[12][12]; // matriz de custos (a entrada) -> c[0][1] = 2 significa que o medico 0 no plantao 1 custa 2
int ordem[12][12]; // ordem em que cada médico faz os plantões -> médico 0: custos 9 2 7  :  ordem[0] = 1 2 0   (plantão 1 custa 2, plantão 2 custa 7, plantão 0 custa 9)
int melhor = 12000;
bool usados[12]; 

// limitante inferior: custo parcial + menor custo livre de cada médico restante
int limitante (int medico, int custo)
{
    int lb = custo;
    for (int i = medico; i < n; i++)
    {
        int menor = melhor;
        for (int j = 0; j < n; j++)
        {
            if (!usados[j])
            {
                menor = min(menor, c[i][j]);
            }
        }
        lb += menor;
    }
    return lb;

}

// cada chamada é um nó da árvore implícita
void busca(int medico, int custo)
{
    if (medico == n) // folha: escala completa
    {
        melhor = min(melhor, custo);
        return;
    }

    if (limitante(medico, custo) >= melhor) return; // poda

    for (int k = 0; k < n; k++)
    {
        int j = ordem[medico][k]; // plantoes mais baratos primeiro
        if (usados[j]) continue; // ocupado: pula
        usados[j] = true; // marca antes de descer
        busca(medico + 1, custo + c[medico][j]);
        usados[j] = false; //desmarca na volta (backtrack)
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j]; // recebendo cada um dos j custos do médico i
        }
    }

    // organizando a matriz de ordem
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) ordem[i][j] = j; 
    }

    busca(0, 0);
    cout << melhor << endl;
    return 0;
}

