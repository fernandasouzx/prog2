#ifndef ATAQUE_H
#define ATAQUE_H

#include <string>
using namespace std;

class Ataque {
public:
    string nome;
    string categoria;
    int poder;
    float precisao;
    string tipo;

    Ataque(const string& nome, const string& categoria, int poder, float precisao, const string& tipo)
        : nome(nome), categoria(categoria), poder(poder), precisao(precisao), tipo(tipo) {}
};

#endif // ATAQUE_H
