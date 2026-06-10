#include "Personagem.h"

namespace Entidades {
	Personagem::Personagem() : num_vidas(9), Entidade(), frameInv(0) {

	}

	Personagem::~Personagem() {

	}

	void Personagem::salvarDataBuffer() {

	}

	void Personagem::pular() {
	}

	void Personagem::mover() {
		Entidade::mover();
	}

	void Personagem::forcar() {
		gravitar();
		arrastar();
		atritar();
	}

	void Personagem::operator-=(int dano) {
		num_vidas -= dano;
	}

	int Personagem::getVidas() {
		if (num_vidas <= 0) {
			num_vidas = 0;
		}
		return num_vidas;
	}
	/*
	void Personagem::podePular() {
		pulou = false;
	}
	*/
}