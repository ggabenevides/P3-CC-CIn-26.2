#include "ExcecaoDadosInvalidos.h"

using namespace std;

ExcecaoDadosInvalidos::ExcecaoDadosInvalidos(string m) : msg(m) {}

string ExcecaoDadosInvalidos::mensagem() const {
    return msg;
}
