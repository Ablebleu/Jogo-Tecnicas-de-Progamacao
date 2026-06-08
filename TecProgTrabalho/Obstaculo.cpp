#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo() : danoso(false) {
			pGC->incluirObstaculo(this);
		}

		Obstaculo::~Obstaculo() {

		}

		void Obstaculo::salvarDataBuffer() {

		}
	}
}
