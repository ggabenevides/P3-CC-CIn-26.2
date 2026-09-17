// ordenar em ordem crescente de acordo com o número de registro mas so consegue trocar livros adjacentes e precisa ser 
// O(n log n) -> merge sort? só que contando as inversões durante o merge: toda vez que um elemento do lado direito é escolhido, ele "
//passou na frente" de cada um dos restantes do lado esquerdo, ou seja a contagem de trocas tem q somar a qtde de elementos restantes do outro lado
// rastrear número MINIMO de trocas "nivel de caos"
// input n tem que ser long p lidar com entradas mt grandes OK
// tratamento de entrada pra pegar os numeros de registro (vai vir tudo numa string) OK

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll; // evitando o overflow que pode acontecer se usar int normal de 32 bits p contar swaps/nivel de caos

vector<int> mergeCaos (ll &nivelDeCaos, vector<int> &va, int na, vector<int> &vb, int nb);
void mergeSortCaos (ll &nivelDeCaos, vector<int> &v, int n);


int main()
{    
    ll nivelDeCaos = 0;
    vector<int> v;
    int n;

    cin >> n;

    int temp;
    for (int i = 0; i<=n-1; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    mergeSortCaos(nivelDeCaos, v, n);

    for (int j : v)
    {
        cout << j << " ";
    }
    cout << endl << nivelDeCaos << endl;
}

void mergeSortCaos (ll &nivelDeCaos, vector<int> &v, int n)
{
    if(n>1)
    {

        //copiar cada metade do array inicial nos dois arrays auxiliares
        int middle = n/2;        
        vector<int> va, vb;
        va.insert(va.begin(), v.begin(), v.begin() + middle);
        vb.insert(vb.begin(), v.begin() + middle, v.end());
        // passo recursivo
        mergeSortCaos(nivelDeCaos, va, va.size());
        mergeSortCaos(nivelDeCaos, vb, vb.size());
        v = mergeCaos (nivelDeCaos, va, va.size(), vb, vb.size());

    }
}

vector<int> mergeCaos (ll &nivelDeCaos, vector<int> &va, int na, vector<int> &vb, int nb)
{

    vector<int> v;
    int iv(0), ia(0), ib(0); // v é o vetor que estamos ordenando, a e b são suas metades esquerda e direita respectivamente, começando com i pq representa o indice

    while(ia < na and ib < nb)
    {
        if (va.at(ia) <= vb.at(ib))
        {
            v.push_back(va.at(ia));
            ia++;
        }
        else
        {
            v.push_back(vb.at(ib));
            nivelDeCaos += (na - ia);  // os swaps feitos são quantos elementos o elemento da direta precisou "andar" até chegar na posição certa
            ib++;
        }
        iv++;
    }

    v.insert(v.end(), va.begin() + ia, va.end()); // como a inserção começa a partir de va.begin() + ia, não tem perigo de inserir elementos que já foram inseridos antes
    v.insert(v.end(), vb.begin() + ib, vb.end());

    return v;
}