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
	void executar(float dt);
	void danificar(Jogador *p);
	void mover(float dt);
};

#endif  //_INIM_MEDIO_H
