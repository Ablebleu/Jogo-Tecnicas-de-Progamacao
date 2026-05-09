#include <iostream>
#include "Ente.h"

Ente::Ente() {

}

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

