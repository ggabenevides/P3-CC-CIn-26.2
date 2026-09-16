#include <iostream>
#include <string>
using namespace std;

// nó 
class Node{
    private:
        long long id;
        long long prioridade;
        Node* proximo;
    public:
        // construtor
        Node(long long _id, long long _prioridade) : id(_id), prioridade(_prioridade), proximo(nullptr) {}

        // getters e setters
        long long getId() { return id; }
        long long getPrioridade() { return prioridade; }
        Node* getProximo() {return proximo;}

        void setPrioridade(long long novaPrioridade) { prioridade = novaPrioridade; }
        void setProximo(Node* novoProximo) { proximo = novoProximo; }
};

// struct suporte pra o mecanismo de next
struct ResultadoNext {
    bool sucesso;
    long long id;
    int custo;
};

class FilaTarefas
{
    private:
        Node* inicio;
        Node* fim;
        int tamanho;

    public:

        // contrutor e destrutor
        FilaTarefas() : inicio(nullptr), fim(nullptr), tamanho(0) {}
        ~FilaTarefas()
        {
            Node* atual = inicio;
            while (atual != nullptr)
            {
                Node* temp = atual;
                atual = atual->getProximo();
                delete temp;
            }
        }

        // métodos
        bool vazia() { return inicio == nullptr;}
        int getTamanho() {return tamanho;}

        void add(long long id, long long prioridade)
        {
            Node* novo = new Node(id, prioridade);
            if (inicio == nullptr)
            {
                inicio = fim = novo;
            }
            else
            {
                fim->setProximo(novo);
                fim = novo;
            }
            tamanho++;
        }

        void update(long long id, long long novaPrioridade)
        {
            Node* atual = inicio; 
            while(atual != nullptr)   // percorre a lista inteira
            {
                if (atual->getId() == id)
                {
                    atual->setPrioridade(novaPrioridade);
                    return;
                }
                atual = atual->getProximo();
            }
        }

        ResultadoNext next()
        {
            if(inicio == nullptr){
            return {false, 0, 0};
            }
            
            Node* atual = inicio;
            Node* escolhido = inicio;
            Node* anteriorAoEscolhido = nullptr;
            Node* anterior = nullptr;
            
            int posicaoAtual = 1;
            int posicaoEscolhido = 1;
            
            while(atual != nullptr){
                bool melhorPrioridade = (atual->getPrioridade() > escolhido->getPrioridade());
                bool empatePorId = (atual->getPrioridade() == escolhido->getPrioridade() 
                                    && atual->getId() < escolhido->getId());
                
                if(melhorPrioridade || empatePorId){
                    escolhido = atual;
                    anteriorAoEscolhido = anterior;
                    posicaoEscolhido = posicaoAtual;
                }
                
                anterior = atual;
                atual = atual->getProximo();
                posicaoAtual++;
            }
            
            long long idEscolhido = escolhido->getId();
            
            if(anteriorAoEscolhido == nullptr){
                inicio = escolhido->getProximo();
            } else {
                anteriorAoEscolhido->setProximo(escolhido->getProximo());
            }
            
            if(escolhido == fim){
                fim = anteriorAoEscolhido;
            }
            
            delete escolhido;
            tamanho--;
            
            return {true, idEscolhido, posicaoEscolhido};
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    FilaTarefas fila;
    
    for(int i = 0; i < q; i++){
        string cmd;
        cin >> cmd;
        
        if(cmd == "ADD"){
            long long id, p;
            cin >> id >> p;
            fila.add(id, p);
        }
        else if(cmd == "UPDATE"){
            long long id, p;
            cin >> id >> p;
            fila.update(id, p);
        }
        else if(cmd == "NEXT"){
            ResultadoNext r = fila.next();
            
            if(!r.sucesso){
                cout << "FILA VAZIA\n";
            } else {
                cout << r.id << " " << r.custo << " " << fila.getTamanho() << "\n";
            }
        }
    }
    
    return 0;
}