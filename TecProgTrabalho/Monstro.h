#ifndef _MONSTRO_H
#define _MONSTRO_H

#include "Inimigo.h"

namespace Entidades {
	class Projetil;
	namespace Personagens {
		class Monstro : public Inimigo {
		private:
			const short int forca;
			int cadencia; //tempo entre cada disparo
			Projetil* pProj;
		public:
			Monstro(sf::Vector2f p = sf::Vector2f(1400.f, 500.f), int n = 0, short int f = 0);
			Monstro(const nlohmann::json& dados);
			~Monstro();
			void salvar();
			void executar();
			void danificar(Jogador* p);
			void mover();
			void atirar();
			void setPos(sf::Vector2f p);
			short int getForca() const;
		};
	}
}

#endif  //_MONSTRO_H
