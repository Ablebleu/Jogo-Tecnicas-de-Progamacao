#ifndef _FASE_PRIMEIRA_H
#define _FASE_PRIMEIRA_H

#include "Jogador.h"
#include "Fase.h"
#include <list>

class Fase_Primeira: public Fase {
private:
	Jogador *pJog1;
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
	Fase_Primeira();
	~Fase_Primeira();
	void executar();
};

#endif 
