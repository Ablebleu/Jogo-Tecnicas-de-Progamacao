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

		void Obstaculo::levitar() {
			vel += (sf::Vector2f(0.f, -0.5f));
		}

		void Obstaculo::forcar() {
			gravitar();
			arrastar();
			atritar();
			levitar();
		}
	}
}
