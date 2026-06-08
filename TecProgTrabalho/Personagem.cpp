#include "Personagem.h"

namespace Entidades {
	Personagem::Personagem() : num_vidas(10), Entidade() {

	}

	Personagem::~Personagem() {

	}

	void Personagem::salvarDataBuffer() {

	}

	void Personagem::pular() {
	}

	void Personagem::mover() {
		pos.x += vel.x;
		pos.y += vel.y;
		setPos(pos);
	}
	/*
	void Personagem::podePular() {
		pulou = false;
	}
	*/
}