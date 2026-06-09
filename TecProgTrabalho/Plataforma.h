#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma : public Obstaculo {
		private:
			sf::Vector2f proporcao; //Proporções -> substituir altura e largura
		public:
			Plataforma(sf::Vector2f p, sf::Vector2f prop = { 1.0f, 1.0f });
			~Plataforma();
			const sf::FloatRect getCorpo();
			void executar();
			void salvar();
			void obstaculizar(Jogador* p);
		};
	}
}

#endif 