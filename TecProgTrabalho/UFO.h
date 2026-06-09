#ifndef _UFO_H
#define _UFO_H

#include "Inimigo.h"

namespace Entidades
{
	class UFO : public Inimigo {
	private:
		float raio;
		float posEixoY;
		int graus;
	public:
		UFO(sf::Vector2f p = sf::Vector2f(1400.f, 500.f), int n = 0, float r = 1.f);
		~UFO();
		void salvar();
		void executar();
		void desenhar();
		void setPos(sf::Vector2f p);
		void danificar(Jogador* p);
		void levitar();
		void mover();
	};
}

#endif 
