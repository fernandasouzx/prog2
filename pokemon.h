#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "ataque.h"
using namespace std;

class Pokemon {
public:
    string nome;
    vector<string> tipos;
    string tipo1;
    string tipo2;
    int nivel;
    int hp;
    int ataque;
    int defesa;
    int velocidade;
    int spAtaque;
    int spDefesa;
    vector<Ataque> ataques;

    Pokemon(const string& nome, const vector<string>& tipos, int nivel)
        : nome(nome), tipos(tipos), nivel(nivel) {
        tipo1 = tipos[0];
        tipo2 = tipos.size() > 1 ? tipos[1] : "";
    }

    void adicionarAtaque(const Ataque& ataque) {
        ataques.push_back(ataque);
    }
};

vector<Pokemon> carregarPokemons(const string& arquivo);

#endif // POKEMON_H
