#ifndef _PROJETIL_H
#define _PROJETIL_H

#include "Entidade.h"

namespace Entidades
{
	namespace Personagens {
		class Jogador;
		class Monstro;
	}
	class Projetil : public Entidade {
	protected:
		bool ativo;
		Personagens::Monstro* pMons;
	public:
		Projetil(sf::Vector2f p = sf::Vector2f(-100.f, -100.f));
		Projetil(const nlohmann::json& dados);
		~Projetil();
		const bool estaRelacionado() const;
		void relacionarMonstro(Personagens::Monstro* pM);
		void executar();
		void levitar();
		void forcar();
		void salvar();
		void mover();
		void danificar(Personagens::Jogador* p);
		void setAtivo(bool a);
		bool getAtivo() const;
	};
}

#endif  
