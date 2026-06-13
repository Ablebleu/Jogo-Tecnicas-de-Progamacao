#ifndef _OBSTACULO_H
#define _OBSTACULO_H

#include "Entidade.h"

namespace Entidades
{
	class Jogador;
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
			virtual void obstaculizar(Jogador* p) = 0;
		};
	}
}

#endif 
