#ifndef _ALIEN_H
#define _ALIEN_H

#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens {
		class Alien : public Inimigo {
		private:
			int tamanho;
		public:
			Alien(sf::Vector2f p = sf::Vector2f(1400.f, 500.f), int n = 0, int tam = 1);
			Alien(const nlohmann::json& dados);
			~Alien();
			void salvar();
			void executar();
			void danificar(Jogador* p);
			void mover();
			void setPos(sf::Vector2f p);
		};
	}
}

#endif 