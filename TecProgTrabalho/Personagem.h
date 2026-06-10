#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H

#include "Entidade.h"

namespace Entidades
{
	class Personagem : public Entidade {
	protected:
		int num_vidas;
		//Gerenciador_Fisica* GF;
		//int ...;
	public:
		Personagem();
		~Personagem();
		void salvarDataBuffer();
		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual void pular();
		virtual void mover();
		void forcar();
		void operator-=(int dano);
		int getVidas();
		//void ...();
	};
}

#endif 