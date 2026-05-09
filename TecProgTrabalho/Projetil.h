#ifndef _PROJETIL_H
#define _PROJETIL_H

#include "Entidade.h"

class Projetil : public Entidade {
public:
	Projetil();
	~Projetil();
	//void ...();
	void executar(float dt);
	void salvar();
	void mover(float dt);
protected:
	//int . . .;
	bool ativo;
};

#endif  
