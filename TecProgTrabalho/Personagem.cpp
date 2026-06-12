#include "Personagem.h"

namespace Entidades {
	Personagem::Personagem() : num_vidas(9), vivo(true), Entidade(), frameInv(0) {

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
		if (num_vidas <= 0) {
			num_vidas = 0;
			setVivo(false);
		}
	}

	int Personagem::getVidas() const{
		return num_vidas;
	}

	bool Personagem::getVivo() const{
		return vivo;
	}

	void Personagem::setVivo(bool v) {
		vivo = v;
	}
	/*
	void Personagem::podePular() {
		pulou = false;
	}
	*/
}