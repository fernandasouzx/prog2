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

    // Pula a primeira linha (cabeçalho)
    getline(input, linha);

    while (getline(input, linha)) {
        stringstream ss(linha);
        string nome, tipo1, tipo2;
        int hp, nivel, ataque, defesa, velocidade, spAtaque, spDefesa;

        getline(ss, nome, ',');
        getline(ss, tipo1, ',');
        getline(ss, tipo2, ',');

        ss >> hp;
        ss.ignore(); // Ignora a vírgula
        ss >> nivel;
        ss.ignore();
        ss >> ataque;
        ss.ignore();
        ss >> defesa;
        ss.ignore();
        ss >> velocidade;
        ss.ignore();
        ss >> spAtaque;
        ss.ignore();
        ss >> spDefesa;

        vector<string> tipos = {tipo1};
        if (tipo2 != "Nenhum") {
            tipos.push_back(tipo2);
        }

        Pokemon pokemon(nome, tipos, nivel);
        pokemon.hp = hp;
        pokemon.ataque = ataque;
        pokemon.defesa = defesa;
        pokemon.velocidade = velocidade;
        pokemon.spAtaque = spAtaque;
        pokemon.spDefesa = spDefesa;

        pokemons.push_back(pokemon);
    }
    return pokemons;
}
