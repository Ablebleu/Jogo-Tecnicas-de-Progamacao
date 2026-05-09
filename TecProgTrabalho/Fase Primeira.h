#ifndef _FASE PRIMEIRA_H
#define _FASE PRIMEIRA_H

#include "Fase.h"

class Fase_Primeira: public Fase {
protected:
	void criarInimMedios();
	void criarObstMedios();
	void criarInimgos();
	void criarObstaculo();
	void criarCenario();
private:
	//int ...;
	//const int maxInimMedios;
public:
	//void ...();
	Fase_Primeira();
	~Fase_Primeira();
	virtual void executar();
};

#endif 
