#include "jogador.h"
#include "menu.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "dificuldade.h"

using namespace std;

vector<Jogador> ranking;


// funcao para criar ou listar jogadores
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
            if (opcao > 0 && static_cast<size_t>(opcao) <= ranking.size())
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

//funcao que carrega o ranking de um arquivo
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

    //funcao que salva o ranking em arquivo RANKING.TXT
    void salvarRanking()
    {
        ofstream arquivo("ranking.txt");
        for (const auto &jogador : ranking)
        {
            cout << "Salvando jogador: " << jogador.nome << " com pontuação " << jogador.pontuacao << endl; // Mostra os dados de cada jogador
            arquivo << jogador.nome << " " << jogador.vitorias << " " << jogador.derrotas << " " << jogador.pontuacao << endl;
        }
        arquivo.close();
    }

    // função para atualizar vitórias, derrotas e pontuação de um jogador
    void atualizarRanking(const string &nome, bool vitoria) {
    int pontos = (dificuldadeAtual == DIFICIL) ? 30 : (dificuldadeAtual == MEDIO) ? 20 : 10;
    bool encontrou = false;  // Verificar se o jogador já está no ranking

    for (auto &jogador : ranking) {
        if (jogador.nome == nome) {
            encontrou = true;
            if (vitoria) {
                jogador.vitorias++;
                jogador.pontuacao += pontos;
                cout << "Vitória registrada para " << nome << ". Pontuação atualizada para " << jogador.pontuacao << endl;
            } else {
                jogador.derrotas++;
                cout << "Derrota registrada para " << nome << endl;
            }
            salvarRanking();  // Salva imediatamente após atualizar o jogador
            return;
        }
    }

    // Caso o jogador não esteja no ranking, adiciona um novo
    if (!encontrou) {
        Jogador novoJogador = {nome, vitoria ? 1 : 0, vitoria ? 0 : 1, vitoria ? pontos : 0};
        ranking.push_back(novoJogador);
        cout << "Novo jogador adicionado: " << nome << " com pontuação inicial " << novoJogador.pontuacao << endl;
        salvarRanking();
    }
}

    
    
    
    // função para exibir o ranking final
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
