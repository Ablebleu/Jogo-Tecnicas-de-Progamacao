#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H

#include "Entidade.h"

namespace Entidades
{
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			int num_vidas;
			bool vivo;
			bool virado;
			int frameInv;
		public:
			Personagem();
			Personagem(const nlohmann::json& dados);
			~Personagem();
			void salvarDataBuffer();
			virtual void executar() = 0;
			virtual void salvar() = 0;
			virtual void pular();
			virtual void mover();
			virtual void operator-=(int dano);
			void forcar();
			int getVidas() const;
			bool getVivo() const;
			void setVivo(bool v);
			virtual void desenhar();
		};
	}
}

#endif 