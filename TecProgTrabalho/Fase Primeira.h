#ifndef _FASE_PRIMEIRA_H
#define _FASE_PRIMEIRA_H

#include "Fase.h"

class Fase_Primeira: public Fase {
protected:
	void criarInimMedios();
	void criarObstMedios();
	void criarInimigos();
	void criarObstaculo();
	void criarCenario();
private:
	//int ...;
	//const int maxInimMedios;
public:
	//void ...();
	Fase_Primeira();
	~Fase_Primeira();
	void executar(float dt);
};

#endif 
