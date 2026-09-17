#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> countingSortNotas (vector<int> &v, int n, int range);

int main()
{
    int n, k, temp;
    vector<int> vetorAntes;
    vector<vector<int>> resposta;

    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vetorAntes.push_back(temp);
    }

    resposta = countingSortNotas(vetorAntes, n, k);

    for (vector<int> vetor : resposta)
    {
        for (int elemento : vetor)
        {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> countingSortNotas (vector<int> &v, int n, int range)
{
    vector<int> ordered(n);
    vector<int> contagemAcumulada(range + 1);
    vector<vector<int>> resposta;

    //loop de contagem
    for (int i = 0; i < n; i++)
    {
        contagemAcumulada.at(v.at(i))++;
    }
    //loop de contagem acumulada
    for (int j = 1; j <= range; j++)
    {
        contagemAcumulada.at(j) += contagemAcumulada.at(j-1);
    } 

    vector<int> acumuladaOriginal = contagemAcumulada; //copia da contagem acumulada pq contagemAcumulada vai ser alterado enquanto tá populando o vetor ordenado
    
    //populando vetor com elementos ordenados começando no ultimo elemento
    for (int l = n-1; l>=0; l--)
    {
        ordered.at(contagemAcumulada.at(v.at(l))-1) = v.at(l);
        contagemAcumulada.at(v.at(l)) -= 1;
    }
    
    resposta.push_back(acumuladaOriginal);
    resposta.push_back(ordered);
    return resposta;
} 