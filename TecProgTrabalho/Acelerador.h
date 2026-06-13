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
			Acelerador(sf::Vector2f p = sf::Vector2f(-100.f, -100.f), float h = 1.f, float l = 1.f);
			Acelerador(const nlohmann::json& dados);
			~Acelerador();
			const sf::FloatRect getCorpo();
			void executar();
			void salvar();
			void obstaculizar(Jogador* p);
		};
	}
}

#endif 