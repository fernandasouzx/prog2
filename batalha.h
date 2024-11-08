#ifndef BATALHA_H
#define BATALHA_H

#include "jogador.h"
#include "pokemon.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

// definição estrutura ATAQUE
struct structAtaque {
    string nome;
    int poder;
    int precisao;
    string tipo;
};

// definição estrutura POKEMON
struct structPokemon {
    string nome;
    int nivel;
    int hp;
    int ataque;
    int defesa;
    vector <structAtaque> ataques;
    string tipo1;
    string tipo2;
};

// funçoes da batalha
void iniciarBatalha(Dificuldade dificuldadeAtual, vector<Pokemon> pokemons, string nomeJogador);
int calcularDano(const Pokemon& atacante, const Pokemon& defensor, const Ataque& ataqueEscolhido);
void selecionarDificuldade(Dificuldade& dificuldadeAtual);

#endif
