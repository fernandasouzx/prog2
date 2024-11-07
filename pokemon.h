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
    int nivel;
    vector<Ataque> ataques;

    Pokemon(const string& nome, const vector<string>& tipos, int nivel)
        : nome(nome), tipos(tipos), nivel(nivel) {}

    void adicionarAtaque(const Ataque& ataque) {
        ataques.push_back(ataque);
    }
};
vector<Pokemon> carregarPokemons(const string& arquivo);

#endif // POKEMON_H
