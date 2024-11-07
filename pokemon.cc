#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "pokemon.h"

using namespace std;

// Função para carregar Pokémons
vector<Pokemon> carregarPokemons(const string& arquivo) {
    vector<Pokemon> pokemons;
    ifstream input(arquivo);
    string linha;

    while (getline(input, linha)) {
        stringstream ss(linha);
        string nome, tipo1, tipo2;
        int nivel;
        
        getline(ss, nome, ',');
        getline(ss, tipo1, ',');
        ss >> nivel;
        
        // Lê o tipo2, se existir
        getline(ss, tipo2, ',');
        vector<string> tipos = {tipo1};
        if (!tipo2.empty()) {
            tipos.push_back(tipo2);
        }

        pokemons.push_back(Pokemon(nome, tipos, nivel));
    }
    return pokemons;
}
