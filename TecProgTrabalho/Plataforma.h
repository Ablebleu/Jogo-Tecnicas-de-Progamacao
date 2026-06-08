#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include "Obstaculo.h"

namespace Entidades
{
	class Plataforma : public Obstaculo {
	private:
		sf::Vector2f proporcao; //Proporções -> substituir altura e largura
	public:
		Plataforma(sf::Vector2f p, sf::Vector2f prop = sf::Vector2f{ 1.0f, 1.0f });
		~Plataforma();
		const sf::FloatRect getCorpo();
		void executar();
		void mover();
		virtual void salvar();
		void obstaculizar(Jogador* p);
	};
}

#endif 