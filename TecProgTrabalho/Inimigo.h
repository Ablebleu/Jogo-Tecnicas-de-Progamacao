#ifndef _INIMIGO_H
#define _INIMIGO_H

#include "Personagem.h"

class Jogador;
class Inimigo : public Personagem {
protected:
	int nivel_maldade;
	//int ...;
public:
	//void ...();
	void salvarDataBuffer();
	virtual void executar(float dt) = 0;
	virtual void danificar(Jogador *p) = 0;
	virtual void salva() = 0;
	virtual void mover(float dt) = 0;
};

#endif  //_INIMIGO_H
