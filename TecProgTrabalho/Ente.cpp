#include <iostream>
#include "Ente.h"

Ente::Ente(): id(cont_id++), pSprite(NULL) {

}
int Ente::cont_id(0);
Gerenciadores::Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::~Ente() {
	if (pSprite) delete pSprite;
}

void Ente::desenhar() {
	pGG->desenharEnte(this);
	//std::cout << "b";
}

sf::Sprite* Ente::getSprite() const {
	if(pSprite) return pSprite;
	else {
		std::cerr << "Erro ao acessar Sprite em Ente" << std::endl;
		return NULL;
	}
}

void Ente::setGG(Gerenciadores::Gerenciador_Grafico* pG) {
	if (pG) pGG = pG;
	else std::cerr << "Erro ao setar Gerenciador Grafico em Ente" << std::endl;
}

/*void Ente::. . .() {

}*/

