#include <iostream>
#include "Entidade.h"

Entidade::Entidade(sf::Vector2f p, sf::Vector2f v): 
	Ente(), pos(p), vel(v) {

}

Entidade::~ Entidade() {

}


void Entidade::salvarDataBuffer() {

}

//Hitbox/mudar depois
const sf::FloatRect Entidade::getCorpo() {
	return pSprite->getGlobalBounds();
}

void Entidade::setPos(sf::Vector2f p) {
	pos = p;
}

const sf::Vector2f Entidade::getPos() const {
	return pos;
}

void Entidade::desenhar() {
	if (pSprite) {
		pGG->desenharEnte(this);
	}
}