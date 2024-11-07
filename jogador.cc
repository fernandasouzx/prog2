#include "jogador.h"
#include "menu.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "dificuldade.h"

using namespace std;

vector<Jogador> ranking;

string carregarJogadores()
{
    int opcao;

    if (ranking.size() == 0)
    {
        string nome;
        cout << "Digite o nome do novo jogador: " << endl;
        cin >> nome;
        ranking.push_back({nome, 0, 0, 0});
        return nome;
    }
    else
    {
        cout << "Escolha uma das opções: " << endl;
        cout << "[1] Criar novo jogador" << endl;
        cout << "[2] Listar jogadores" << endl;
        cin >> opcao;

        string nome;
        switch (opcao)
        {
        case 1:
            cout << "Digite o nome do novo jogador: " << endl;
            cin >> nome;
            ranking.push_back({nome, 0, 0, 0});
            return nome;
            break;
        case 2:
            cout << "Escolha um jogador da lista: " << endl;
            for (size_t i = 0; i < ranking.size(); ++i)
            {
                cout << i + 1 << ". " << ranking[i].nome << endl;
            }
            cin >> opcao;
            if (opcao > 0 && opcao <= ranking.size())
            {
                return ranking[opcao - 1].nome;
            }

            else
            {
                cout << "Opção inválida. Tente novamente." << endl;
                return carregarJogadores();
            }
            break;
    
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
}

    void carregarRanking()
    {
        ifstream arquivo("ranking.txt");
        if (!arquivo)
        {
            cout << "Arquivo de ranking não encontrado. Um novo será criado ao salvar." << endl;
            return;
        }

        Jogador jogador;
        while (arquivo >> jogador.nome >> jogador.vitorias >> jogador.derrotas >> jogador.pontuacao)
        {
            ranking.push_back(jogador);
        }
        arquivo.close();
    }

    void salvarRanking()
    {
        ofstream arquivo("ranking.txt");
        for (const auto &jogador : ranking)
        {
            arquivo << jogador.nome << " " << jogador.vitorias << " " << jogador.derrotas << " " << jogador.pontuacao << endl;
        }
        arquivo.close();
    }

    void atualizarRanking(const string &nome, bool vitoria)
    {
        for (auto &jogador : ranking)
        {
            if (jogador.nome == nome)
            {
                if (vitoria)
                {
                    jogador.vitorias++;
                    jogador.pontuacao += (dificuldadeAtual == DIFICIL) ? 30 : (dificuldadeAtual == MEDIO) ? 20
                                                                                                          : 10;
                }
                else
                {
                    jogador.derrotas++;
                }
                return;
            }
        }
        // Adiciona novo jogador ao ranking caso não seja encontrado
        Jogador novoJogador = {nome, vitoria ? 1 : 0, vitoria ? 0 : 1, vitoria ? (dificuldadeAtual == DIFICIL ? 30 : dificuldadeAtual == MEDIO ? 20
                                                                                                                                               : 10)
                                                                               : 0};
        ranking.push_back(novoJogador);
    }
    void exibirRanking()
    {
        if (ranking.empty())
        {
            cout << "Nenhum jogador no ranking." << endl;
            return;
        }

        cout << "=== Ranking dos Jogadores ===" << endl;
        for (const auto &jogador : ranking)
        {
            cout << "Nome: " << jogador.nome
                 << " | Vitórias: " << jogador.vitorias
                 << " | Derrotas: " << jogador.derrotas
                 << " | Pontuação: " << jogador.pontuacao << endl;
        }
    }
