#include "Jogo.h"
#include "Estado_Fase.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include <iostream>

namespace Estados {
	Estado_Fase::Estado_Fase(int n) : Estado(), pFase(nullptr) {
		pFase = pJogo->getFase(n);
	}
	Estado_Fase::~Estado_Fase() {
		if (pFase) delete pFase;
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
}