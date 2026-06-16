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
		std::string Nome;
		int pontos;
		int ordemJogador;
		sf::Sprite hp;
		sf::Keyboard::Key tecla_cima;
		sf::Keyboard::Key tecla_baixo;
		sf::Keyboard::Key tecla_esquerda;
		sf::Keyboard::Key tecla_direita;
		//int ...;

		Buraco_Negro* pAtaque;
	public:
		Jogador(int i = 1);
		Jogador(const nlohmann::json& dados);
		~Jogador();
		void colidir(Inimigo* pIn);
		void executar();
		void desenhar();
		void salvar();
		void acelerar();
		void pular();
		void mover();
		void operator-=(int dano);
		void atacar();
		void addPontos(int pont = 100);
		void setPos(sf::Vector2f p);
		void setTeclas(sf::Keyboard::Key cima, sf::Keyboard::Key baixo, sf::Keyboard::Key esq, sf::Keyboard::Key dir);
		Buraco_Negro* getAtaque();
		//. . .
	};
}

#endif 