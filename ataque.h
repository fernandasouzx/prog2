#ifndef ATAQUE_H
#define ATAQUE_H

#include <string>
using namespace std;

class Ataque {
public:
    string nome;
    string tipo;
    int poder;
    int precisao;

    Ataque(const string& nome, const string& tipo, int poder, int precisao)
        : nome(nome), tipo(tipo), poder(poder), precisao(precisao) {}
};

#endif // ATAQUE_H
