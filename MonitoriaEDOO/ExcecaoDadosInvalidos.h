#ifndef EXCECAO_DADOS_INVALIDOS_H
#define EXCECAO_DADOS_INVALIDOS_H

#include <string>

class ExcecaoDadosInvalidos {
    std::string msg;
public:
    ExcecaoDadosInvalidos(std::string m = "Peso ou altura invalidos (devem ser > 0)");
    std::string mensagem() const;
};

#endif
