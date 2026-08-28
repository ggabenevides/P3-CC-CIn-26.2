#ifndef EXCECOES_H
#define EXCECOES_H

#include <string>
using namespace std;

// EXERCICIO 2
//hierarquia de classes de exceção personalizadas --> requisito 1

class ExcecaoJogador {
protected:
    string msg;
public:
    ExcecaoJogador(string m = "Erro generico no sistema de jogadores") : msg(m) {}
    virtual string mensagem() const { return msg; }
    virtual ~ExcecaoJogador() {}
};

class ExcecaoDadosInvalidos : public ExcecaoJogador {
public:
    ExcecaoDadosInvalidos(string m = "Peso ou altura invalidos (devem ser > 0)")
        : ExcecaoJogador(m) {}
};

class ExcecaoAtributoInvalido : public ExcecaoJogador {
public:
    ExcecaoAtributoInvalido(string m = "Atributo especifico de posicao fora do dominio valido")
        : ExcecaoJogador(m) {}
};

class ExcecaoPosicaoInvalida : public ExcecaoJogador {
public:
    ExcecaoPosicaoInvalida(string m = "Codigo de posicao nao reconhecido")
        : ExcecaoJogador(m) {}
};

#endif