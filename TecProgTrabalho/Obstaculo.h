#ifndef _OBSTACULO_H
#define _OBSTACULO_H

#include "Entidade.h"

namespace Entidades
{
	namespace Personagens {
		class Jogador;
	}
	namespace Obstaculos
	{
		class Obstaculo : public Entidade {
		protected:
			bool danoso;
		public:
			Obstaculo();
			Obstaculo(const nlohmann::json& dados);
			~Obstaculo();
			void salvarDataBuffer();
			void levitar();
			void forcar();
			virtual void executar() = 0;
			virtual void salvar() = 0;
			virtual void obstaculizar(Personagens::Jogador* p) = 0;
			const sf::FloatRect getCorpo();
		};
	}
}

#endif 
