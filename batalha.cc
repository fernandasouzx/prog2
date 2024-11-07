#include "batalha.h"
#include "pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

extern Dificuldade dificuldadeAtual;

void iniciarBatalha(Dificuldade dificuldadeAtual, vector<Pokemon>pokemons) {
    cout << "Iniciando a batalha..." << endl;
    srand(time(0));

    srand(pokemons.size());
    int index = rand();
    Pokemon poke = pokemons[index];
    
    
   
   /* 
    // Ajustando o nível da CPU baseado na dificuldade
    if (dificuldadeAtual == FACIL) {
        cpuPokemon.nivel = min(jogadorPokemon.nivel - 1, cpuPokemon.nivel);
    } else if (dificuldadeAtual == MEDIO) {
        cpuPokemon.nivel = jogadorPokemon.nivel;
    } else if (dificuldadeAtual == DIFICIL) {
        cpuPokemon.nivel = max(jogadorPokemon.nivel + 1, cpuPokemon.nivel);
    }

    // Loop de batalha
    while (jogadorPokemon.hp > 0 && cpuPokemon.hp > 0) {
        // Ações do jogador e CPU (simplificado para exemplo)
    }

    
    if (jogadorPokemon.hp > 0) {
        cout << "Parabéns, você venceu a batalha!" << endl;
        atualizarRanking("Jogador", true);
    } else {
        cout << "Você perdeu a batalha." << endl;
        atualizarRanking("Jogador", false);
    }
}   */

}
int calcularDano(const structPokemon& atacante, const structPokemon& defensor, const structAtaque& ataqueEscolhido) {
    return (ataqueEscolhido.poder * atacante.ataque / defensor.defesa);
}
