#if !defined(_CHEFAO_H)
#define _CHEFAO_H

#include "Inimigo.h"

namespace Entidades {
	class Chefao : public Inimigo {
	private:
		//int ...;
		short int forca;
	public:
		//void ...();
		void salvar();
		void executar();
		void danificar(Jogador* p);
		void mover();
	};
}

#endif  //_CHEFAO_H
