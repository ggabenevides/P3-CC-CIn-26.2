#include <iostream>
using namespace std;

// lista de adjacênci: cada bairro aponta pra sua primeira aresta (cabeca) e cada aresta aponta pra próxima do mesmo bairro (prox).
// cada ponte vira duas arestas, uma em cada sentido, então são até 2*M arestas
// regiões: uma BFS a partir de cada bairro ainda não visitado; cada BFS nova = uma região
// menor número de pontes: BFS a partir do bairro 0 (todas as pontes têm o mesmo "peso")
// BFS em vez de DFS recursiva porque a profundidade pode chegar a 2*10^4

int n, m;
int cabeca[20000];  // N é no máximo 2*10^4
int destino[80000]; // 2*M
int prox[80000];
int qtd_arestas = 0;

bool visitado[20000];
int dist[20000];
int fila[20000]; // cada bairro entra na fila no máximo uma vez

void adiciona_aresta(int u, int v)
{
    destino[qtd_arestas] = v;
    prox[qtd_arestas] = cabeca[u];
    cabeca[u] = qtd_arestas;
    qtd_arestas++;
}

// BFS a partir de origem, marcando visitados e preenchendo dist
void bfs(int origem)
{
    int ini = 0, fim = 0;
    fila[fim++] = origem;
    visitado[origem] = true;
    dist[origem] = 0;

    while (ini < fim)
    {
        int atual = fila[ini++];
        for (int e = cabeca[atual]; e != -1; e = prox[e])
        {
            int vizinho = destino[e];
            if (!visitado[vizinho])
            {
                visitado[vizinho] = true;
                dist[vizinho] = dist[atual] + 1;
                fila[fim++] = vizinho;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) cabeca[i] = -1; // -1 = sem arestas ainda

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adiciona_aresta(u, v); // a ponte vale nos dois sentidos
        adiciona_aresta(v, u);
    }

    // a primeira BFS sai do bairro 0, assim ela já serve pras duas respostas
    int regioes = 0;
    bfs(0);
    regioes++;

    int resposta_dist;
    if (visitado[n - 1]) resposta_dist = dist[n - 1];
    else resposta_dist = -1; // o abrigo ficou em outra região

    // o resto dos bairros não visitados são regiões novas
    for (int i = 1; i < n; i++)
    {
        if (!visitado[i])
        {
            bfs(i);
            regioes++;
        }
    }

    cout << regioes << "\n";
    cout << resposta_dist << "\n";

    return 0;
}