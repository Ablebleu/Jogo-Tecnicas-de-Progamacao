#include "Estado.h"
#include "Jogo.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Estados.h"
#include "Gerenciador_Eventos.h"
#include <iostream>


namespace Estados {
	Gerenciador::Gerenciador_Grafico* Estado::pGG = nullptr;
	Gerenciador::Gerenciador_Estados* Estado::pGEs = nullptr;
	Gerenciador::Gerenciador_Evento* Estado::pGE = nullptr;
	Jogo* Estado::pJogo = nullptr;

	Estado::Estado() : Ente() {
		incluirEstado();
		pGG = Gerenciador::Gerenciador_Grafico::getGerenciador_Grafico();
		std::cout << "Criando estado: " << getId() << std::endl;
	}

	Estado::~Estado() {

	}

	void Estado::incluirEstado() {
		if (pGEs) {
			pGEs->incluirEstado(this);
		}
		else {
			std::cerr << "Gerenciador de estados não definido!" << std::endl;
			exit(1);
		}
	}

	void Estado::setGEs(Gerenciador::Gerenciador_Estados* p) {
		if (p) pGEs = p;
		else {
			std::cerr << "Erro setando gerenciador de estados para os estados" << std::endl;
			exit(1);
		}
	}
	void Estado::setGE(Gerenciador::Gerenciador_Evento* p) {
		if (p) pGE = p;
		else {
			std::cerr << "Erro setando gerenciador de estados para os estados" << std::endl;
			exit(1);
		}
	}

	void Estado::setJogo(Jogo* p) {
		if (p) pJogo = p;
		else {
			std::cerr << "Erro setando jogo para os estados" << std::endl;
			exit(1);
		}
	}
}