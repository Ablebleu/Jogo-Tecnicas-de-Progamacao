#include "Estado_Fase.h"
#include "Fase_Primeira.h"
//#include "Fase_Segunda.h"
#include <iostream>

Estado_Fase::Estado_Fase(int n) : Estado(), pFase(nullptr) {
	switch (n) {
	case 1: 
		criarFase1();
		break;
	case 2: 
		criarFase2();
		break;
	default: 
		break;
	}
}
Estado_Fase::~Estado_Fase() {}

void Estado_Fase::criarFase1() {
	Fase_Primeira *nFase = new Fase_Primeira;
	if (nFase) pFase = nFase;
	else {
		std::cerr << "Erro ao criar fase1" << std::endl;
	}
}
void Estado_Fase::criarFase2() {
	std::cerr << "Erro ao criar fase2" << std::endl;
}

void Estado_Fase::executar() {
	if (pFase) pFase->executar();
	else {
		std::cerr << "Sem fase" << std::endl;
		exit(1);
	}
}
void Estado_Fase::desenhar() {
	if (pFase) pFase->desenhar();
	else {
		std::cerr << "Sem fase" << std::endl;
		exit(1);
	}
}