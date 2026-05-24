#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2f p, int n) : posInicial(p), nivel_maldade(n) {
	pGC->incluirInimigo(this);
}

Inimigo::~Inimigo() {
	nivel_maldade = 0;
}

void Inimigo::salvarDataBuffer() {

}