#ifndef _ENTIDADE_H
#define _ENTIDADE_H

#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace Entidade {
	class Entidade : public Ente {
	private:
		sf::Vector2f pos;
		sf::FloatRect corpo;
	public:
		Entidade();
		virtual ~Entidade();

		virtual void executar() = 0;
		virtual void salvar() = 0;
	};
}
#endif