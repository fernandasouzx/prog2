#include "menu.h"
#include "jogador.h"
#include "batalha.h"
#include "pokemon.h"
#include <iostream>
#include <vector>
#include "pokemon.h"
using namespace std;

extern Dificuldade dificuldadeAtual;
extern vector<Jogador> ranking;

void exibirMenu(vector<Pokemon>pokemons) {
    int escolha = 0;
    string jogador;
    cout << dificuldadeAtual << endl;

    while (escolha != 4) {
        cout << "=== Menu Principal ===" << endl;
        cout << "1. Iniciar Batalha" << endl;
        cout << "2. Dificuldade do Jogo" << endl;
        cout << "3. Ranking" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                jogador = carregarJogadores();
                iniciarBatalha(dificuldadeAtual, pokemons); // Inicia a batalha com a dificuldade atual
                break;
            case 2:
                selecionarDificuldade(dificuldadeAtual); // Define a dificuldade do jogo
                break;
            case 3:
                exibirRanking(); // Exibe o ranking
                break;
            case 4:
                sairDoJogo(); // Sair do jogo
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }
}

void selecionarDificuldade(Dificuldade& dificuldadeAtual) {
    int opcao;
    cout << "Escolha o nível de dificuldade:" << endl;
    cout << "1. Fácil" << endl;
    cout << "2. Médio" << endl;
    cout << "3. Difícil" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;

    switch(opcao) {
        case 1:
            dificuldadeAtual = FACIL;
            cout << "Dificuldade definida para: Fácil" << endl;
            break;
        case 2:
            dificuldadeAtual = MEDIO;
            cout << "Dificuldade definida para: Médio" << endl;
            break;
        case 3:
            dificuldadeAtual = DIFICIL;
            cout << "Dificuldade definida para: Difícil" << endl;
            break;
        default:
            cout << "Opção inválida. A dificuldade será mantida em: ";
            if (dificuldadeAtual == FACIL) cout << "Fácil" << endl;
            else if (dificuldadeAtual == MEDIO) cout << "Médio" << endl;
            else cout << "Difícil" << endl;
            break;
    }

}

void sairDoJogo() {
    cout << "Saindo do jogo..." << endl;
    salvarRanking();
    exit(0);
}
