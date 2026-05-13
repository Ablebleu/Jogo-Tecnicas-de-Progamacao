#ifndef _OBSTACULO_H
#define _OBSTACULO_H

#include "Entidade.h"

class Jogador;
class Obstaculo : public Entidade {
protected:
	bool danoso;
	//int ...;
public:
	Obstaculo();
	~Obstaculo();
	void salvarDataBuffer();
	virtual void executar(float dt) = 0;
	virtual void salvar() = 0;
	virtual void obstaculizar(Jogador *p) = 0;
};

#endif 
