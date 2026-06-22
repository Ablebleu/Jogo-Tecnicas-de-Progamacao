#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma : public Obstaculo {
		private:
			const float comprimento;
		public:
			Plataforma(sf::Vector2f p, float l = 1.f);
			Plataforma(const nlohmann::json& dados);
			~Plataforma();
			void executar();
			void salvar();
			void obstaculizar(Personagens::Jogador* p);
		};
	}
}

#endif 