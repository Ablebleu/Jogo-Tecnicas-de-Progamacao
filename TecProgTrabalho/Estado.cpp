#include "Estado.h"
#include <iostream>

void Estado::setGE(Gerenciador_Estados* p) {
	if(p) pGE = p;
	else {
		std::cerr << "Erro setando gerenciador de estados para os estados" << std::endl;
		exit(1);
	}
}