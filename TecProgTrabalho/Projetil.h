#ifndef _PROJETIL_H
#define _PROJETIL_H

#include "Entidade.h"

namespace Entidades
{
	class Projetil : public Entidade {
	protected:
		bool ativo;
	public:
		Projetil(sf::Vector2f p = sf::Vector2f(-100.f, -100.f));
		~Projetil();
		void executar();
		void salvar();
		void mover();
	};
}

#endif  
