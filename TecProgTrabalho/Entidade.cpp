#include <iostream>
#include "Entidade.h"

Gerenciador::Gerenciador_Colisoes* Entidade::pGC = nullptr;
Entidade::Entidade(sf::Vector2f p, sf::Vector2f v): 
	Ente(), pos(p), vel(v), corpo(sf::Vector2f{ 50.0f, 50.0f }), contatoBase(false) {
	setPos(p);
	corpo.setFillColor(sf::Color::Red);
}

Entidade::~ Entidade() {
	std::cout << "Deletando entidade: " << getId() << std::endl;
}


void Entidade::salvarDataBuffer() {

}

//Hitbox/mudar depois
const sf::FloatRect Entidade::getCorpo() {
	return corpo.getGlobalBounds();
}

void Entidade::forcar(sf::Vector2f F) {
	//std::cout << "Força aplicada: (" << F.x << ", " << F.y << ")" << std::endl;
	vel += F;
}

void Entidade::setPos(sf::Vector2f p) {
	pos = p;
	corpo.setPosition(p);
}

void Entidade::setVel(sf::Vector2f v) {
	vel = v;
}

const sf::Vector2f Entidade::getPos() const {
	return pos;
}

const sf::Vector2f Entidade::getVel() const {
	return vel;
}

void Entidade::desenhar() {
	//Modificar depois
	pGG->desenhar(&corpo);
	pGG->desenhar(pSprite);
	//std::cout << "ID: " << getId() << " Pos: (" << pos.x << ", " << pos.y << ")" << std::endl;
}

void Entidade::setGC(Gerenciador::Gerenciador_Colisoes* pG) {
	if (pG) pGC = pG;
	else {
		std::cerr << "Erro ao setar Gerenciador de Colisões em Entidade" << std::endl;
		exit(1);
	}
}

	void Entidade::houveContatoBase() {
		contatoBase = true;
	}