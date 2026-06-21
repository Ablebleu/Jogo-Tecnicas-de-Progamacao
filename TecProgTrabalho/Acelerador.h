#ifndef _ACELERADOR_H
#define _ACELERADOR_H

#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Acelerador : public Obstaculo {
		private:
			float aceleracao;
		public:
			Acelerador(sf::Vector2f p = sf::Vector2f(-100.f, -100.f), float acel = 1.f);
			Acelerador(const nlohmann::json& dados);
			~Acelerador();
			void executar();
			void salvar();
			void obstaculizar(Personagens::Jogador* p);
		};
	}
}

#endif 