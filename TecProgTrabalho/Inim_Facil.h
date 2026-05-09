#ifndef _INIM_FACIL_H
#define _INIM_FACIL_H

#include "Inimigo.h"

class Inim_Facil : public Inimigo {
private:
	//int ...;
	float raio;
public:
	//void ...();
	void salvar();
	void executar(float dt);
	void danificar(Jogador* p);
	void mover(float dt);
};

#endif  //_INIM_FACIL_H
