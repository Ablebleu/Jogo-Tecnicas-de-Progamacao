#ifndef _ACELERADOR_H
#define _ACELERADOR_H

#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Acelerador : public Obstaculo {
		private:
			float altura;
			float largura;
		public:
			Acelerador(sf::Vector2f p, float h, float l);
			~Acelerador();
			const sf::FloatRect getCorpo();
			void executar();
			void salvar();
			void obstaculizar(Jogador* p);
		};
	}
}

#endif 