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
		Entidade::mover();
	}

	void Personagem::forcar() {
		gravitar();
		arrastar();
		atritar();
	}

	void Personagem::operator-=(int dano) {
		num_vidas -= dano;
		verificarVivo();
	}

	void Personagem::verificarVivo() {
		if (num_vidas <= 0) {
			num_vidas = 0;
			//morrer
		}
	}
	/*
	void Personagem::podePular() {
		pulou = false;
	}
	*/
}