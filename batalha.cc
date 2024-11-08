#include "batalha.h"
#include "pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

extern Dificuldade dificuldadeAtual;

double calcularEfetividadeTipo(const string &tipoAtaque, const string &tipoDefesa)
{
    static map<string, map<string, double>> tabelaEfetividade = {
        {"Normal", {{"Normal", 1}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 1}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 1}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 0.5}, {"Fantasma", 0}, {"Dragao", 1}, {"Metal", 0.5}, {"Fada", 1}}},
        {"Fogo", {{"Normal", 1}, {"Fogo", 0.5}, {"Agua", 0.5}, {"Eletrico", 1}, {"Grama", 2}, {"Gelo", 2}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 1}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 2}, {"Rocha", 0.5}, {"Fantasma", 1}, {"Dragao", 0.5}, {"Metal", 2}, {"Fada", 1}}},
        {"Agua", {{"Normal", 1}, {"Fogo", 2}, {"Agua", 0.5}, {"Eletrico", 1}, {"Grama", 0.5}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 2}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 2}, {"Fantasma", 1}, {"Dragao", 0.5}, {"Metal", 1}, {"Fada", 1}}},
        {"Eletrico", {{"Normal", 1}, {"Fogo", 1}, {"Agua", 2}, {"Eletrico", 0.5}, {"Grama", 0.5}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 0}, {"Voador", 2}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 1}, {"Fantasma", 1}, {"Dragao", 0.5}, {"Metal", 1}, {"Fada", 1}}},
        {"Grama", {{"Normal", 1}, {"Fogo", 0.5}, {"Agua", 2}, {"Eletrico", 1}, {"Grama", 0.5}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 0.5}, {"Terrestre", 2}, {"Voador", 0.5}, {"Psiquico", 1}, {"Inseto", 0.5}, {"Rocha", 2}, {"Fantasma", 1}, {"Dragao", 0.5}, {"Metal", 0.5}, {"Fada", 1}}},
        {"Gelo", {{"Normal", 1}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 2}, {"Gelo", 0.5}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 2}, {"Voador", 2}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 1}, {"Fantasma", 1}, {"Dragao", 2}, {"Metal", 0.5}, {"Fada", 1}}},
        {"Lutador", {{"Normal", 2}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 1}, {"Gelo", 2}, {"Lutador", 1}, {"Venenoso", 0.5}, {"Terrestre", 1}, {"Voador", 0.5}, {"Psiquico", 0.5}, {"Inseto", 0.5}, {"Rocha", 2}, {"Fantasma", 0}, {"Dragao", 1}, {"Metal", 1}, {"Fada", 0.5}}},
        {"Venenoso", {{"Normal", 1}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 2}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 0.5}, {"Terrestre", 0.5}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 0.5}, {"Fantasma", 0.5}, {"Dragao", 1}, {"Metal", 1}, {"Fada", 2}}},
        {"Terrestre", {{"Normal", 1}, {"Fogo", 2}, {"Agua", 1}, {"Eletrico", 2}, {"Grama", 0.5}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 2}, {"Terrestre", 1}, {"Voador", 0}, {"Psiquico", 1}, {"Inseto", 0.5}, {"Rocha", 2}, {"Fantasma", 1}, {"Dragao", 1}, {"Metal", 2}, {"Fada", 1}}},
        {"Voador", {{"Normal", 1}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 0.5}, {"Grama", 2}, {"Gelo", 1}, {"Lutador", 2}, {"Venenoso", 1}, {"Terrestre", 1}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 2}, {"Rocha", 0.5}, {"Fantasma", 1}, {"Dragao", 1}, {"Metal", 0.5}, {"Fada", 1}}},
        {"Psiquico", {{"Normal", 1}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 1}, {"Gelo", 1}, {"Lutador", 2}, {"Venenoso", 2}, {"Terrestre", 1}, {"Voador", 1}, {"Psiquico", 0.5}, {"Inseto", 1}, {"Rocha", 1}, {"Fantasma", 1}, {"Dragao", 1}, {"Metal", 0.5}, {"Fada", 1}}},
        {"Inseto", {{"Normal", 1}, {"Fogo", 0.5}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 2}, {"Gelo", 1}, {"Lutador", 0.5}, {"Venenoso", 0.5}, {"Terrestre", 1}, {"Voador", 0.5}, {"Psiquico", 2}, {"Inseto", 1}, {"Rocha", 1}, {"Fantasma", 0.5}, {"Dragao", 1}, {"Metal", 0.5}, {"Fada", 0.5}}},
        {"Rocha", {{"Normal", 1}, {"Fogo", 2}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 1}, {"Gelo", 2}, {"Lutador", 0.5}, {"Venenoso", 1}, {"Terrestre", 0.5}, {"Voador", 2}, {"Psiquico", 1}, {"Inseto", 2}, {"Rocha", 1}, {"Fantasma", 1}, {"Dragao", 1}, {"Metal", 0.5}, {"Fada", 1}}},
        {"Fantasma", {{"Normal", 0}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 1}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 1}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 1}, {"Fantasma", 2}, {"Dragao", 1}, {"Metal", 1}, {"Fada", 1}}},
        {"Dragao", {{"Normal", 1}, {"Fogo", 1}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 1}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 1}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 1}, {"Fantasma", 1}, {"Dragao", 2}, {"Metal", 0.5}, {"Fada", 0}}},
        {"Metal", {{"Normal", 1}, {"Fogo", 0.5}, {"Agua", 0.5}, {"Eletrico", 0.5}, {"Grama", 1}, {"Gelo", 2}, {"Lutador", 1}, {"Venenoso", 1}, {"Terrestre", 1}, {"Voador", 1}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 2}, {"Fantasma", 1}, {"Dragao", 1}, {"Metal", 0.5}, {"Fada", 2}}},
        {"Fada", {{"Normal", 1}, {"Fogo", 0.5}, {"Agua", 1}, {"Eletrico", 1}, {"Grama", 1}, {"Gelo", 1}, {"Lutador", 1}, {"Venenoso", 0.5}, {"Terrestre", 1}, {"Voador", 2}, {"Psiquico", 1}, {"Inseto", 1}, {"Rocha", 1}, {"Fantasma", 1}, {"Dragao", 2}, {"Metal", 0.5}, {"Fada", 1}}}};

    return tabelaEfetividade[tipoAtaque][tipoDefesa];
}

vector<Ataque> carregarAtaques()
{
    vector<Ataque> ataques;
    ifstream arquivo("ataques.txt");
    string linha;

    getline(arquivo, linha); // Pula a primeira linha (cabeçalho)

    while (getline(arquivo, linha))
    {
        stringstream ss(linha);
        string move, categoria, poder, precisao, tipo;

        getline(ss, move, ',');
        getline(ss, categoria, ',');
        getline(ss, poder, ',');
        getline(ss, precisao, ',');
        getline(ss, tipo, ',');

        Ataque novoAtaque(move, categoria, stoi(poder), stof(precisao), tipo);
        ataques.push_back(novoAtaque);
    }

    return ataques;
}

vector<Ataque> sortearAtaques(const Pokemon &pokemon, const vector<Ataque> &todosAtaques)
{
    vector<Ataque> ataquesCompativeis;
    vector<Ataque> ataquesEscolhidos;

    // Filtra ataques compatíveis com os tipos do pokemon
    for (const Ataque &ataque : todosAtaques)
    {
        if (ataque.tipo == pokemon.tipo1 || ataque.tipo == pokemon.tipo2)
        {
            ataquesCompativeis.push_back(ataque);
        }
    }

    // Embaralha os ataques compatíveis
    random_shuffle(ataquesCompativeis.begin(), ataquesCompativeis.end());

    // Seleciona os 4 primeiros ataques (ou menos se não houver 4 disponíveis)
    for (int i = 0; i < min(4, (int)ataquesCompativeis.size()); i++)
    {
        ataquesEscolhidos.push_back(ataquesCompativeis[i]);
    }


    return ataquesEscolhidos;
}

void iniciarBatalha(Dificuldade dificuldadeAtual, vector<Pokemon> pokemons, string nomeJogador)
{
    cout << "Iniciando a batalha..." << endl;
    srand(time(0));

    // Carrega todos os ataques do arquivo
    vector<Ataque> todosAtaques = carregarAtaques();

    // Vetores para armazenar os pokemons escolhidos
    vector<Pokemon> pokemonsJogador;
    vector<Pokemon> pokemonsCPU;

    cout << "\nSorteando 3 Pokemons para sua equipe:\n";

    // Sorteio dos pokemons do jogador
    for (int i = 0; i < 3; i++)
    {
        int index = rand() % pokemons.size();
        Pokemon pokemonSorteado = pokemons[index];
        pokemonSorteado.ataques = sortearAtaques(pokemonSorteado, todosAtaques);
        cout << i + 1 << ". " << pokemonSorteado.nome << " (Nível " << pokemonSorteado.nivel << ")\n";
        pokemonsJogador.push_back(pokemonSorteado);
    }

    cout << "\nPokemons da CPU:\n";

    // Sorteio dos pokemons da CPU
    for (int i = 0; i < 3; i++)
    {
        int index = rand() % pokemons.size();
        Pokemon pokemonSorteado = pokemons[index];
        pokemonSorteado.ataques = sortearAtaques(pokemonSorteado, todosAtaques);
        cout << i + 1 << ". " << pokemonSorteado.nome << " (Nível " << pokemonSorteado.nivel << ")\n";
        pokemonsCPU.push_back(pokemonSorteado);
    }

    // Encontrar o pokemon mais fraco e mais forte do jogador
    int nivelMaisForte = pokemonsJogador[0].nivel;
    int nivelMaisFraco = pokemonsJogador[0].nivel;

    for (const Pokemon &pokemon : pokemonsJogador)
    {
        if (pokemon.nivel > nivelMaisForte)
            nivelMaisForte = pokemon.nivel;
        if (pokemon.nivel < nivelMaisFraco)
            nivelMaisFraco = pokemon.nivel;
    }

    // Ajustando o nível da CPU baseado na dificuldade
    for (Pokemon &pokemon : pokemonsCPU)
    {
        if (dificuldadeAtual == FACIL)
        {
            pokemon.nivel = min(pokemon.nivel, nivelMaisFraco);
        }
        else if (dificuldadeAtual == MEDIO)
        {
            pokemon.nivel = min(pokemon.nivel, nivelMaisForte);
        }
        else if (dificuldadeAtual == DIFICIL)
        {
            pokemon.nivel = max(pokemon.nivel, nivelMaisForte);
        }
    }

    // Seleção inicial de pokemons
    cout << "\nEscolha seu Pokemon inicial (1-3): ";
    int escolhaJogador;
    cin >> escolhaJogador;
    Pokemon *pokemonAtualJogador = &pokemonsJogador[escolhaJogador - 1];
    Pokemon *pokemonAtualCPU = &pokemonsCPU[0];

    bool batalhaEmAndamento = true;
    bool turnoJogador = true;

    while (batalhaEmAndamento)
    {
        if (turnoJogador)
        {
            cout << "\nSeu turno!" << endl;
            cout << "Pokemon atual: " << pokemonAtualJogador->nome << " (HP: " << pokemonAtualJogador->hp << ")" << endl;
            cout << "Pokemon inimigo: " << pokemonAtualCPU->nome << " (HP: " << pokemonAtualCPU->hp << ")" << endl;

            cout << "1. Atacar" << endl;
            cout << "2. Trocar Pokemon" << endl;
            int escolha;
            cin >> escolha;

            if (escolha == 1)
            {
                // Lógica de ataque
                cout << "Escolha seu ataque (1-4):" << endl;
                for (int i = 0; i < pokemonAtualJogador->ataques.size(); i++)
                {
                    cout << i + 1 << ". " << pokemonAtualJogador->ataques[i].nome << endl;
                }
                int ataqueEscolhido;
                cin >> ataqueEscolhido;

                // Cálculo do dano
                int dano = calcularDano(*pokemonAtualJogador, *pokemonAtualCPU, pokemonAtualJogador->ataques[ataqueEscolhido - 1]);

                // Verificação da precisão do ataque
                float precisaoAtaque = pokemonAtualJogador->ataques[ataqueEscolhido - 1].precisao * 100;
                int chanceAcerto = rand() % 100;
                if (chanceAcerto < precisaoAtaque)
                {
                    pokemonAtualCPU->hp -= dano;
                    cout << "O ataque causou " << dano << " de dano!" << endl;

                    // Verifica se o pokemon da CPU foi derrotado
                    if (pokemonAtualCPU->hp <= 0) {
                        cout << pokemonAtualCPU->nome << " foi derrotado!" << endl;
                        // Procura próximo pokemon disponível da CPU
                        bool encontrouProximo = false;
                        for (Pokemon &p : pokemonsCPU) {
                            if (p.hp > 0 && &p != pokemonAtualCPU) {
                                pokemonAtualCPU = &p;
                                encontrouProximo = true;
                                cout << "CPU enviou " << p.nome << "!" << endl;
                                break;
                            }
                        }
                        if (!encontrouProximo) {
                            cout << "CPU não tem mais pokemons disponíveis!" << endl;
                            batalhaEmAndamento = false;
                            cout << "Você venceu!" << endl;
                            atualizarRanking(nomeJogador, true);
                            break;
                        }
                    }
                }
                else
                {
                    cout << "O ataque falhou!" << endl;
                }

                turnoJogador = false;
            }
            else if (escolha == 2)
            {
                // Lógica de troca
                cout << "Escolha o Pokemon para trocar (1-3):" << endl;
                for (int i = 0; i < pokemonsJogador.size(); i++)
                {
                    if (pokemonsJogador[i].hp > 0) {
                        cout << i + 1 << ". " << pokemonsJogador[i].nome << " (HP: " << pokemonsJogador[i].hp << ")" << endl;
                    }
                }
                int novoPokemon;
                cin >> novoPokemon;
                if (pokemonsJogador[novoPokemon - 1].hp > 0) {
                    pokemonAtualJogador = &pokemonsJogador[novoPokemon - 1];
                    turnoJogador = false;
                } else {
                    cout << "Este pokemon foi derrotado! Escolha outro." << endl;
                }
            }
        }
        else
        {
            // Turno da CPU
            int ataqueCPU = rand() % pokemonAtualCPU->ataques.size();
            int dano = calcularDano(*pokemonAtualCPU, *pokemonAtualJogador, pokemonAtualCPU->ataques[ataqueCPU]);

            float precisaoAtaque = pokemonAtualCPU->ataques[ataqueCPU].precisao * 100;
            int chanceAcerto = rand() % 100;
            if (chanceAcerto < precisaoAtaque)
            {
                pokemonAtualJogador->hp -= dano;
                cout << "CPU causou " << dano << " de dano!" << endl;

                // Verifica se o pokemon do jogador foi derrotado
                if (pokemonAtualJogador->hp <= 0) {
                    cout << pokemonAtualJogador->nome << " foi derrotado!" << endl;
                    // Procura próximo pokemon disponível do jogador
                    bool encontrouProximo = false;
                    for (Pokemon &p : pokemonsJogador) {
                        if (p.hp > 0 && &p != pokemonAtualJogador) {
                            bool escolhaValida = false;
                            while (!escolhaValida) {
                                cout << "Escolha seu próximo pokemon:" << endl;
                                for (int i = 0; i < pokemonsJogador.size(); i++) {
                                    if (pokemonsJogador[i].hp > 0) {
                                        cout << i + 1 << ". " << pokemonsJogador[i].nome << " (HP: " << pokemonsJogador[i].hp << ")" << endl;
                                    }
                                }
                                int novoPokemon;
                                cin >> novoPokemon;

                                if (novoPokemon >= 1 && novoPokemon <= pokemonsJogador.size() && pokemonsJogador[novoPokemon-1].hp > 0) {
                                    pokemonAtualJogador = &pokemonsJogador[novoPokemon - 1];
                                    escolhaValida = true;
                                    encontrouProximo = true;
                                    break;
                                } else {
                                    cout << "Escolha inválida! Por favor, escolha um pokemon disponível." << endl;
                                }
                            }
                        }
                    }
                    if (!encontrouProximo) {
                        cout << "Você não tem mais pokemons disponíveis!" << endl;
                        batalhaEmAndamento = false;
                        cout << "CPU venceu!" << endl;
                        atualizarRanking(nomeJogador, false);
                        break;
                    }
                }
            }
            else
            {
                cout << "O ataque da CPU falhou!" << endl;
            }

            turnoJogador = true;
        }

        // Verificar condições de vitória
        bool todosJogadorDerrotados = true;
        bool todosCPUDerrotados = true;

        for (const Pokemon &p : pokemonsJogador)
        {
            if (p.hp > 0)
                todosJogadorDerrotados = false;
        }

        for (const Pokemon &p : pokemonsCPU)
        {
            if (p.hp > 0)
                todosCPUDerrotados = false;
        }

        if (todosJogadorDerrotados || todosCPUDerrotados)
        {
            batalhaEmAndamento = false;
            cout << (todosCPUDerrotados ? "Você venceu!" : "CPU venceu!") << endl;
        }
    }
}

int calcularDano(const Pokemon &atacante, const Pokemon &defensor, const Ataque &ataqueEscolhido)
{
    // Cálculo do dano conforme a fórmula fornecida
    double dano = 2 * atacante.nivel;
    dano *= ataqueEscolhido.poder;

    // Verificar se o ataque é físico ou especial
    if (ataqueEscolhido.categoria == "Físico")
    {
        dano *= (double)atacante.ataque / defensor.defesa;
    }
    else
    {
        dano *= (double)atacante.spAtaque / defensor.spDefesa;
    }

    dano = (dano / 50) + 2;

    // Critical hit (1/16 chance)
    bool critico = (rand() % 16 == 0);
    if (critico)
    {
        dano *= 2;
        cout << "Foi um golpe crítico!" << endl;
    }

    // STAB bonus
    if (atacante.tipo1 == ataqueEscolhido.tipo || atacante.tipo2 == ataqueEscolhido.tipo)
    {
        dano *= 1.5;
    }

    // Type effectiveness
    double type1Effectiveness = calcularEfetividadeTipo(ataqueEscolhido.tipo, defensor.tipo1);
    double type2Effectiveness = defensor.tipo2.empty() ? 1 : calcularEfetividadeTipo(ataqueEscolhido.tipo, defensor.tipo2);

    if (type1Effectiveness * type2Effectiveness == 0)
    {
        cout << "O ataque não é efetivo!" << endl;
        return 0;
    }

    dano *= type1Effectiveness * type2Effectiveness;

    // Random factor
    if (dano > 1)
    {
        int random = 217 + (rand() % 39); // 217 to 255
        dano *= random;
        dano /= 255;
    }

    return (int)dano;
}
