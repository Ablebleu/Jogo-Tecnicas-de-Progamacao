#include <iostream>
#include "Ente.h"

int Ente::cont_id(0);
Ente() : id(cont_id++) {}
~Ente() { id = -1; }

const int getID() const {
	return id;
}

void setGG(Gerenciador::Gerenciador_Grafico* pG) {
	if (pG) pGG = pG;
	else {
		std::cerr << "Gerenciador Grafico nao incluido em Ente" << std::endl;
		exit(1);
	}
}
