#ifndef _ENTIDADE_H
#define _ENTIDADE_H

#include "Ente.h"

class Entidade : public Ente {
protected:
	int x;
	int y;
	//int ...;
	//ostream buffer;
	void salvarDataBuffer();
public:
	Entidade();
	virtual  ~Entidade();
	virtual void executar() = 0;
	virtual void salvar() = 0;
	virtual void mover() = 0;
	//void ...();
};

#endif
