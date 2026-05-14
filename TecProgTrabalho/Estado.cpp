#include "Estado.h"
#include "Gerenciador_Estados.h"
#include <iostream>

Gerenciadores::Gerenciador_Estados* Estado::pGE = nullptr;

void Estado::setGE(Gerenciadores::Gerenciador_Estados* p) {
	if(p) pGE = p;
	else {
		std::cerr << "Erro setando gerenciador de estados para os estados" << std::endl;
		exit(1);
	}
}