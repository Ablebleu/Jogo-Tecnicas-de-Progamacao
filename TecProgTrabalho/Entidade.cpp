#include <iostream>
#include "Entidade.h"

namespace Entidades {
	Gerenciador::Gerenciador_Colisoes* Entidade::pGC = nullptr;
	Entidade::Entidade(sf::Vector2f p, sf::Vector2f v) :
		Ente(), pos(p), vel(v), corpo(sf::Vector2f{ 50.0f, 50.0f }), contatoBase(false) {
		setPos(p);
		corpo.setFillColor(sf::Color::Red);
	}

	Entidade::~Entidade() {
		std::cout << "Deletando entidade: " << getId() << std::endl;
	}


	void Entidade::salvarDataBuffer() {

	}

	//Hitbox/mudar depois
	const sf::FloatRect Entidade::getCorpo() {
		return corpo.getGlobalBounds();
	}

	void Entidade::mover() {
		pos += vel;
		setPos(pos);
	}

	void Entidade::gravitar() {
		vel += (sf::Vector2f(0.f, 2.f));
	}
	void Entidade::arrastar() {
		vel += (sf::Vector2f(0.004f * -vel.x * std::abs(vel.x), 0.004f * -vel.y * std::abs(vel.y)));
	}
	void Entidade::atritar() {
		if (contatoBase) vel +=(sf::Vector2f(0.03f * -vel.x, 0.f));
	}

	void Entidade::forcar(sf::Vector2f f) {
		vel += f;
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
		//pGG->desenhar(&corpo);
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

	const bool Entidade::getContatoBase() const {
		return contatoBase;
	}

	void Entidade::houveContatoBase() {
		contatoBase = true;
	}
}