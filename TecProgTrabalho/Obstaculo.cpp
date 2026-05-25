#include "Obstaculo.h"

Obstaculo::Obstaculo() : danoso(false) {
	GC->incluirObstaculo(this);
}

Obstaculo::~Obstaculo() {

}

void Obstaculo::salvarDataBuffer() {

}
