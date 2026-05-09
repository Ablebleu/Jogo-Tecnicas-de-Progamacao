#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H

#include "Entidade.h"

class Personagem : public Entidade {
protected:
	int num_vidas;
	//int ...;
public:
	Personagem();
	~Personagem();
	void salvarDataBuffer();
	virtual void executar(float dt) = 0;
	virtual void salvar() = 0;
	virtual void mover(float dt) = 0;
	//void ...();
};

#endif 