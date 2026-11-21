#include <iostream>
using namespace std;

// árvore binária de decisão -> nível i decide sobre a comida i, a decisão é incluir ou não (cada nó tem dois filhos, um é o caminho incluindo e o outro é o caminho não incluindo)

int n, s;
int c[21]; // como n é no máximo 20, 21 slots é o suficiente p representar qualquer case mesmo descartando o index 0
int resto[22]; // desconsiderando o index 0 e adicionando mais uma posição pra ser o caso base, precisamos de 22 slots
bool teve_combo = false;
int atual[21];
int tamanho = 0;

void busca(int comida_atual, int soma_parcial)
{
    if (soma_parcial == s)
    {
        teve_combo = true;
        cout << atual[0];
        for (int i = 1; i<tamanho; i++)
        {
            cout << " " << atual[i];
        }
        cout << "\n";
        return;
    }
    else if (soma_parcial > s) return;
    else if (soma_parcial + resto[comida_atual] < s) return;
    else if (comida_atual > n) return;

    // inclui
    atual[tamanho] = comida_atual;
    tamanho++;
    busca(comida_atual+1, soma_parcial+c[comida_atual]); // teste incluindo a comida atual 
    tamanho--; //backtrack
    busca(comida_atual+1, soma_parcial); // teste sem incluir a comida atual
}

int main()
{
    cin >> n >> s;

    for (int i = 1; i <= n; i++) cin >> c[i]; // desconsidera o indice 0 pq aí o indice já vai ser o id correto da comida 

    // soma de sufixos
    resto[n+1] = 0;
    for (int i = n; i>0; i--) resto[i] = c[i] + resto[i+1];

    busca(1, 0);
    if (!teve_combo) cout << "NENHUM\n";

}