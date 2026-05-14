#include <iostream>
#include "Cenario.h"

Cenario::Cenario(const char* caminho, sf::Vector2f p, sf::Vector2f v, float size):
	Entidade(p, v) {
	if (caminho) {
		if (!textura.loadFromFile(caminho)) {
			std::cerr << "Erro ao carregar textura: " << caminho << std::endl;
		}
	}
	pSprite = new sf::Sprite(textura);
	tam = size;
	pSprite->setScale(sf::Vector2f(1.0f, 1.0f)*tam);
	pSprite->setPosition(pos);
}

Cenario::~Cenario() {

}

void Cenario::executar() {
	mover();
}

void Cenario::salvar() {

}

void Cenario::mover() {
	pos += vel;
	if (pos.x > 1700) pos.x = -100;
	if (pos.x < -500) pos.x = 1700;
	if (pos.y > 1000) pos.y = -100;
	if (pos.y < -100) pos.y = 1000;

	pSprite->setPosition(pos);
}