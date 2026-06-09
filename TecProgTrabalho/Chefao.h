#ifndef _CHEFAO_H
#define _CHEFAO_H

#include "Inimigo.h"

namespace Entidades {
	class Chefao : public Inimigo {
	private:
		short int forca;
	public:
		Chefao(sf::Vector2f p = sf::Vector2f(1400.f, 500.f), int n = 0, int f = 0);
		~Chefao();
		void salvar();
		void executar();
		void danificar(Jogador* p);
		void mover();
	};
}

#endif  //_CHEFAO_H
