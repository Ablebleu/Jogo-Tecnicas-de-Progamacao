#include <iostream>
#include "Ente.h"

Ente::Ente(): id(cont_id++) {

}
int Ente::cont_id(0);
Gerenciadores::Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::~Ente() {

}

void Ente::desenhar() {

}

void Ente::setGG(Gerenciadores::Gerenciador_Grafico* pG) {
	if (pG) pGG = pG;
	else std::cerr << "Erro ao setar Gerenciador Grafico em Ente" << std::endl;
}

/*void Ente::. . .() {

}*/

