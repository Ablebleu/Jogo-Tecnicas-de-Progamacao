#ifndef _PROJETIL_H
#define _PROJETIL_H

#include "Entidade.h"

namespace Entidades
{
	class Chefao;
	class Projetil : public Entidade {
	protected:
		bool ativo;
		Chefao* pChef;
	public:
		Projetil(sf::Vector2f p = sf::Vector2f(-100.f, -100.f));
		Projetil(const nlohmann::json& dados);
		~Projetil();
		const bool estaRelacionado() const;
		void relacionarChefe(Chefao* pC);
		void executar();
		void levitar();
		void forcar();
		void salvar();
		void mover();
	};
}

#endif  
