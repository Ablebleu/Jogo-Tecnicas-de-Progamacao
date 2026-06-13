#ifndef _CHEFAO_H
#define _CHEFAO_H

#include "Inimigo.h"

namespace Entidades {
	class Projetil;
	class Chefao : public Inimigo {
	private:
		short int forca;
		int cadencia; //tempo entre cada disparo
		Projetil* pProj;
	public:
		Chefao(sf::Vector2f p = sf::Vector2f(1400.f, 500.f), int n = 0, int f = 0);
		Chefao(const nlohmann::json& dados);
		~Chefao();
		void salvar();
		void executar();
		void danificar(Jogador* p);
		void mover();
		void atirar();
		void setPos(sf::Vector2f p);
	};
}

#endif  //_CHEFAO_H
