#include <iostream>
#include "Ente.h"

Ente::Ente(): id(cont_id++), pSprite(NULL) {

}

Ente::Ente(int id) :id(id), pSprite(NULL) {
	cont_id = std::max(cont_id, id + 1);
}

int Ente::cont_id(0);
Gerenciador::Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::~Ente() {
	if (pSprite) {
		std::cout << "Deletando sprite de " << id << std::endl;
		delete pSprite;
	}
}

sf::Sprite* Ente::getSprite() {
	if(pSprite) return pSprite;
	else {
		std::cerr << "Erro ao acessar Sprite em Ente" << std::endl;
		return NULL;
	}
}

void Ente::setGG(Gerenciador::Gerenciador_Grafico* pG) {
	if (pG) pGG = pG;
	else std::cerr << "Erro ao setar Gerenciador Grafico em Ente" << std::endl;
}

const int Ente::getId() const {
	return id;
}

/*void Ente::. . .() {

}*/

