#ifndef _PROJETIL_H
#define _PROJETIL_H

#include "Entidade.h"

namespace Entidades
{
	class Projetil : public Entidade {
	public:
		Projetil();
		~Projetil();
		//void ...();
		void executar();
		void salvar();
		void mover();
	protected:
		//int . . .;
		bool ativo;
	};
}

#endif  
