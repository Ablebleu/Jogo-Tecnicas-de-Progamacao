#include <iostream>
#include "Entidade.h"

Entidade::Entidade(sf::Vector2f p, sf::Vector2f v): 
	Ente(), pos(p), vel(v), corpo(sf::Vector2f{ 50.0f, 50.0f }) {
	setPos(p);
	corpo.setFillColor(sf::Color::Red);
}

Entidade::~ Entidade() {

}


void Entidade::salvarDataBuffer() {

}

//Hitbox/mudar depois
const sf::FloatRect Entidade::getCorpo() {
	return corpo.getGlobalBounds();
}

void Entidade::setPos(sf::Vector2f p) {
	pos = p;
	corpo.setPosition(p);
}

const sf::Vector2f Entidade::getPos() const {
	return pos;
}

void Entidade::desenhar() {
	//Modificar depois
	pGG->desenhar(&corpo);
	//std::cout << "ID: " << getId() << " Pos: (" << pos.x << ", " << pos.y << ")" << std::endl;
}