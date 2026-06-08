#include "Obstaculo.h"

namespace Entidades
{
	Obstaculo::Obstaculo() : danoso(false) {
		pGC->incluirObstaculo(this);
	}

	Obstaculo::~Obstaculo() {

	}

	void Obstaculo::salvarDataBuffer() {

	}
}
