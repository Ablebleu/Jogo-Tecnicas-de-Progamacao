#include "Obstaculo.h"

Obstaculo::Obstaculo() : danoso(false) {
	pGC->incluirObstaculo(this);
}

Obstaculo::~Obstaculo() {

}

void Obstaculo::salvarDataBuffer() {

}
