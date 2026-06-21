#ifndef _INIMIGO_H
#define _INIMIGO_H

#include "Personagem.h"

namespace Entidades
{
	namespace Personagens {
		class Jogador;
		class Inimigo : public Personagem {
		protected:
			int nivel_maldade;
			int framesPosAprox;
			const sf::Vector2f posInicial;
		public:
			Inimigo(sf::Vector2f p = sf::Vector2f(1400.f, 500.f), int n = 0);
			Inimigo(const nlohmann::json& dados);
			~Inimigo();
			void salvarDataBuffer();
			virtual void executar() = 0;
			virtual void danificar(Jogador* p) = 0;
			virtual void salvar() = 0;
			virtual void mover() = 0;
		};
	}
}

#endif  
