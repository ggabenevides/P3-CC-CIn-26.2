#include <iostream>
using namespace std;

//nó
class Node
{
    public:
        int key; 
        Node *left, *right;
        Node (int k)
        {
            key = k;
            left = right = nullptr;
        }
};

// fila simples p auxiliar inserção
class FilaNode
{
    private:
        struct ItemFila {
            Node* ptr;
            ItemFila* proximo;
            ItemFila(Node* p) : ptr(p), proximo(nullptr) {}
        };
        
        ItemFila* inicio;
        ItemFila* fim;
        
    public:
        FilaNode() : inicio(nullptr), fim(nullptr) {}
        
        ~FilaNode(){
            while(inicio != nullptr){
                ItemFila* temp = inicio;
                inicio = inicio->proximo;
                delete temp;
            }
        }
        
        bool vazia(){
            return inicio == nullptr;
        }
        
        void push(Node* p){
            ItemFila* novo = new ItemFila(p);
            if(inicio == nullptr){
                inicio = fim = novo;
            } else {
                fim->proximo = novo;
                fim = novo;
            }
        }
        
        Node* front(){
            return inicio->ptr;
        }
        
        void pop(){
            ItemFila* temp = inicio;
            inicio = inicio->proximo;
            if(inicio == nullptr) fim = nullptr;
            delete temp;
        }
};

class Tree
{
    private:
        Node* root;
        int nodecount;   
        
        // funções auxiliares recursivas dos algoritmos de busca clássicos, usando booleano "first" pra facilitar a organização do display
        void inorder_helper(Node* r, bool& first)
        {
            if (r != nullptr)
            {
                inorder_helper(r->left, first);
                if (!first) cout << " ";
                cout << r->key;
                first = false;
                inorder_helper(r->right, first);
            }
        }
        void preorder_helper(Node* r, bool& first)
        {
            if (r != nullptr)
            {                
                if (!first) cout << " ";
                cout << r->key;
                first = false;
                preorder_helper(r->left, first);
                preorder_helper(r->right, first);
            }
        }
        void posorder_helper(Node* r, bool& first)
        {
            if (r != nullptr)
            {
                posorder_helper(r->left, first);
                posorder_helper(r->right, first);                
                if (!first) cout << " ";
                cout << r->key;
                first = false;
            }
        }
    public:
        // construtor
        Tree()
        {
            root = nullptr;
            nodecount = 0;
        }
        
        // primeiro criamos um nó novo com o conteúdo que vai ser inserido
        // depois inicia uma fila com a raiz
        // entra no loop que pega o proximo elemento da fila, remove ele da fila e avalia os seus filhos diretos:
        // se um dos filhos estiver vazio, adiciona ali mesmo e para (como avalia primeiro a esquerda e dps a direita vai na ordem por nível)
        // se não estiver vazio, adiciona no final da fila pra ser avaliado depois e segue p proxima iteração (filho direito ou então proximo elemento na fila)
        void insertLevel(int k)
        {
            Node* novo = new Node(k);
            nodecount++;
            
            if (root == nullptr)
            {
                root = novo;
                return;
            }
            
            FilaNode fila;
            fila.push(root);
            
            while (!fila.vazia())
            {
                Node* atual = fila.front();
                fila.pop();
                
                if (atual->left == nullptr)
                {
                    atual->left = novo;
                    return;
                }
                else
                {
                    fila.push(atual->left);
                }
                
                if (atual->right == nullptr)
                {
                    atual->right = novo;
                    return;
                }
                else
                {
                    fila.push(atual->right);
                }
            }
        }
        
        // algoritmos de ordenação clássico (lógica recursiva contida nas funções auxiliares)
        void preorder() 
        {
            bool first = true;
            preorder_helper(root, first);
        }
        void inorder() 
        {
            bool first = true;
            inorder_helper(root, first);
        }
        void posorder()
        {
            bool first = true;
            posorder_helper(root, first);
        }
};

int main()
{
    Tree t;  
    int count;
    cin >> count;
    int element;
    for (int i = 0; i < count; i++)
    {
        cin >> element;
        t.insertLevel(element);
    }
    cout << "Pre-order: ";
    t.preorder();
    cout << endl;
    cout << "In-order: ";
    t.inorder();
    cout << endl;
    cout << "Post-order: ";
    t.posorder();
    cout << endl;
}