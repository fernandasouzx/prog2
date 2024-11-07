#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "dificuldade.h"



// Declaração de `dificuldadeAtual` como extern
extern Dificuldade dificuldadeAtual;

// Declarações de funções
void exibirMenu(vector<Pokemon>pokemons);
void selecionarDificuldade();
void exibirRanking();
void sairDoJogo();

#endif
