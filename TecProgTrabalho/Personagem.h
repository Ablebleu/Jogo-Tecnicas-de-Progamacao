#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H

#include "Entidade.h"

namespace Entidades
{
	class Personagem : public Entidade {
	protected:
		int num_vidas;
		int frameInv;
	public:
		Personagem();
		~Personagem();
		void salvarDataBuffer();
		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void pular();
		virtual void mover();
		virtual void operator-=(int dano);
		void forcar();
		int getVidas();
		//void ...();
	};
}

#endif 