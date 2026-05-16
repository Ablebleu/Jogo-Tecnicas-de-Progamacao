#ifndef _FASE_PRIMEIRA_H
#define _FASE_PRIMEIRA_H

#include "Fase.h"
#include <list>

class Fase_Primeira: public Fase {
private:
	//int ...;
	//const int maxInimMedios;
protected:
	void criar();
	void criarInimMedios();
	void criarObstMedios();
	void criarInimigos();
	void criarObstaculo();
	void criarCenario();
public:
	//void ...();
	Fase_Primeira(Gerenciador::Gerenciador_Colisoes *pG = NULL);
	~Fase_Primeira();
	void executar();
};

#endif 
