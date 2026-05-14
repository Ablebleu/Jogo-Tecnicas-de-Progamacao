#ifndef _INIM_MEDIO_H
#define _INIM_MEDIO_H

#include "Inimigo.h"

class Inim_Medio : public Inimigo {
private:
	//int ...;
	int tamanho;
public:
	//void ...();
	void salvar();
	void executar();
	void danificar(Jogador *p);
	void mover();
};

#endif  //_INIM_MEDIO_H
