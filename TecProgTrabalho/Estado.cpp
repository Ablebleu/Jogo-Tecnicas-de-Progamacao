#include "Estado.h"
#include "Gerenciador_Estados.h"
#include <iostream>

namespace Estados {
	Gerenciador::Gerenciador_Estados* Estado::pGE = nullptr;

	Estado::Estado() : Ente() {
		incluirEstado();
		std::cout << "Criando estado: " << getId() << std::endl;
	}

	Estado::~Estado() {

	}

	void Estado::incluirEstado() {
		if (pGE) {
			pGE->incluirEstado(this);
		}
		else {
			std::cerr << "Gerenciador de estados não definido!" << std::endl;
			exit(1);
		}
	}

	void Estado::setGE(Gerenciador::Gerenciador_Estados* p) {
		if (p) pGE = p;
		else {
			std::cerr << "Erro setando gerenciador de estados para os estados" << std::endl;
			exit(1);
		}
	}
}