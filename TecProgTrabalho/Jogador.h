#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "Personagem.h"

//Fazer setTeclas depois para permitir 2 jogadores
class Inimigo;
class Jogador : public Personagem {
protected:
	int pontos;
	sf::Keyboard::Key tecla_cima;
	sf::Keyboard::Key tecla_baixo;
	sf::Keyboard::Key tecla_esquerda;
	sf::Keyboard::Key tecla_direita;
	//int ...;
public:
	Jogador();
	~Jogador();
	void colidir(Inimigo* pIn);
	void executar(float dt);
	void salvar();
	void mover(float dt);
	void setTeclas(sf::Keyboard::Key cima, sf::Keyboard::Key baixo, sf::Keyboard::Key esq, sf::Keyboard::Key dir);
	//. . .
};

#endif 