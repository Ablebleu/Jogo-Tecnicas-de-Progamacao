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
	void executar();
	void danificar(Jogador* p);
	void mover();
};

#endif  //_INIM_FACIL_H
