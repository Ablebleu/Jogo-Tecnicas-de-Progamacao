#ifndef _LASER_H
#define _LASER_H

#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Laser : public Obstaculo {
		private:
			float altura;
			float largura;
			int tempoAtivo; //frames
		public:
			Laser(sf::Vector2f p, float h, float l, int t = 60);
			Laser(const nlohmann::json& dados);
			~Laser();
			const sf::FloatRect getCorpo();
			void executar();
			void salvar();
			void obstaculizar(Jogador* p);
			void cicloOnOff();
		};
	}
}

#endif 