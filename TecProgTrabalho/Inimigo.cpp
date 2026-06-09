#include "Inimigo.h"

namespace Entidades {
	Inimigo::Inimigo(sf::Vector2f p, int n) : posInicial(p), nivel_maldade(n), framesPosAprox(0) {
		pGC->incluirInimigo(this);
		pos = p;
	}

	Inimigo::~Inimigo() {
		nivel_maldade = 0;
	}

	void Inimigo::salvarDataBuffer() {

	}
}