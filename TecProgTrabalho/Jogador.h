#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "Personagem.h"
#include "Buraco_Negro.h"

namespace Entidades
{
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

		Buraco_Negro* pAtaque;
	public:
		Jogador();
		~Jogador();
		void colidir(Inimigo* pIn);
		void executar();
		void desenhar();
		void salvar();
		void acelerar();
		void pular();
		void mover();
		void atacar();
		void setPos(sf::Vector2f p);
		void setTeclas(sf::Keyboard::Key cima, sf::Keyboard::Key baixo, sf::Keyboard::Key esq, sf::Keyboard::Key dir);
		Buraco_Negro* getAtaque();
		//. . .
	};
}

#endif 