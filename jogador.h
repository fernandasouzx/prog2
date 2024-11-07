#ifndef JOGADOR_H
#define JOGADOR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dificuldade.h"

using namespace std;

// Definindo a estrutura Jogador
struct Jogador {
    string nome;
    int vitorias;
    int derrotas;
    int pontuacao;
};

// Funções para manipulação do ranking
extern vector<Jogador> ranking;

void carregarRanking();
void salvarRanking();
void atualizarRanking(const string& nome, bool vitoria);
void exibirRanking();
string carregarJogadores();

#endif
