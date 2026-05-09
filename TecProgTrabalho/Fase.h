#ifndef _FASE_H
#define _FASE_H

#include "Ente.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisões.h"

class Fase : public Ente {
protected:
	//ListaEntidades lista_ents;
	Gerenciadores::Gerenciador_Colisões* GC;
	void criarInimFaceis();
	void criarPlataformas();
	virtual void criarInimgos() = 0;
	virtual void criarObstaculo() = 0;
	void criarCenario();
public:
	//int ...;
	Fase();
	virtual ~Fase();
	//void ...();
	virtual void executar() = 0;
};
#endif  