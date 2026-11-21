#include <iostream>
using namespace std;

// kruskal: ordena as arestas por custo e vai aceitando as mais baratas, pulando as que ligam dois prédios que já estão no mesmo grupo (formariam ciclo), union-find guarda os grupos

struct Aresta
{
    int u, v, c;
};

int n, m;
Aresta arestas[40000]; // M é no máximo 4*10^4
Aresta aux[40000];     // vetor auxiliar do merge sort
int pai[20000];        // N é no máximo 2*10^4

// merge sort pelo custo (com 4*10^4 arestas, bubble/insertion ficariam lentos demais)
void merge_sort(int ini, int fim) // intervalo [ini, fim)
{
    if (fim - ini <= 1) return;

    int meio = (ini + fim) / 2;
    merge_sort(ini, meio);
    merge_sort(meio, fim);

    int i = ini, j = meio, k = ini;
    while (i < meio && j < fim)
    {
        if (arestas[i].c <= arestas[j].c) aux[k++] = arestas[i++];
        else aux[k++] = arestas[j++];
    }
    while (i < meio) aux[k++] = arestas[i++];
    while (j < fim) aux[k++] = arestas[j++];

    for (int x = ini; x < fim; x++) arestas[x] = aux[x];
}

// acha o representante do grupo de x
int find(int x)
{
    int raiz = x;
    while (pai[raiz] != raiz) raiz = pai[raiz];

    // compressão de caminho: todo mundo no caminho passa a apontar direto pra raiz
    while (pai[x] != raiz)
    {
        int proximo = pai[x];
        pai[x] = raiz;
        x = proximo;
    }
    return raiz;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> arestas[i].u >> arestas[i].v >> arestas[i].c;

    for (int i = 0; i < n; i++) pai[i] = i; // no início cada prédio é o próprio grupo

    merge_sort(0, m);

    long long total = 0; // a soma pode passar de 2^31 - 1
    int aceitas = 0;

    for (int i = 0; i < m && aceitas < n - 1; i++)
    {
        int ru = find(arestas[i].u);
        int rv = find(arestas[i].v);
        if (ru == rv) continue; // já conectados, essa aresta formaria ciclo

        pai[ru] = rv; // junta os dois grupos
        total += arestas[i].c;
        aceitas++;
    }

    // uma árvore com n vértices tem n - 1 arestas; menos que isso = desconexo
    if (aceitas == n - 1) cout << total << "\n";
    else cout << "IMPOSSIVEL\n";

    return 0;
}