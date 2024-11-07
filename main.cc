#include "menu.h"
#include "jogador.h"
#include "batalha.h"
#include "pokemon.h"
#include <iostream>
#include <string>
#include <vector>
#include "dificuldade.h"

Dificuldade dificuldadeAtual = FACIL;

int main() {

    vector<Pokemon> pokemons = carregarPokemons("pokemons.txt"); // carregando e alocando em um vetors os pokemons
    carregarRanking(); // Carrega o ranking quando iniciado o jogo
    
    exibirMenu(pokemons); // Mostra o menu principal
    return 0;
}
