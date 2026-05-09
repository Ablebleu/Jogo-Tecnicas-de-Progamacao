#include <iostream>
#include "Cenario.h"

Cenario::Cenario(const char* caminho, float px, float py, float vx, float vy): Entidade() {
	if (caminho) {
		if (!textura.loadFromFile(caminho)) {
			std::cerr << "Erro ao carregar textura: " << caminho << std::endl;
		}
	}
	pSprite = new sf::Sprite(textura);
	x = px;
	y = py;
}

Cenario::~Cenario() {

}

void Cenario::executar() {

}

void Cenario::salvar() {

}

void Cenario::mover() {

}