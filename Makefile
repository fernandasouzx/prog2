CXX = g++
CXXFLAGS = -Wall -std=c++17

# Lista de arquivos-objetos
OBJS = main.o menu.o pokemon.o batalha.o jogador.o

# Regra para gerar o executável
batalhaPokemon: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regras para compilar os arquivos-objetos
main.o: main.cc dificuldade.h
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

menu.o: menu.cc dificuldade.h
	$(CXX) $(CXXFLAGS) -c menu.cc -o menu.o

pokemon.o: pokemon.cc dificuldade.h
	$(CXX) $(CXXFLAGS) -c pokemon.cc -o pokemon.o

batalha.o: batalha.cc dificuldade.h
	$(CXX) $(CXXFLAGS) -c batalha.cc -o batalha.o

jogador.o: jogador.cc dificuldade.h
	$(CXX) $(CXXFLAGS) -c jogador.cc -o jogador.o

clean: 
	rm -f *.o batalhaPokemon
