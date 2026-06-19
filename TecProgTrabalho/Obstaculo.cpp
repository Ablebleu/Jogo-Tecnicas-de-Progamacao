#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo() : Entidade(), danoso(false) {
			pGC->incluirObstaculo(this);
		}

		Obstaculo::Obstaculo(const nlohmann::json& dados) : Entidade(dados),
			danoso(dados["danoso"]) {
			pGC->incluirObstaculo(this);
		}

		Obstaculo::~Obstaculo() {
			pGC->removerObstaculo(this);
		}

		void Obstaculo::salvarDataBuffer() {
			Entidade::salvarDataBuffer();
			dadosSalvos["tipo_base"] = "Obstaculo";
			dadosSalvos["danoso"] = danoso;
		}

		void Obstaculo::levitar() {
			vel += (sf::Vector2f(0.f, -2.f));
		}

		void Obstaculo::forcar() {
			gravitar();
			levitar();
			arrastar();
			atritar();
		}

		const sf::FloatRect Obstaculo::getCorpo() {
			return pSprite->getGlobalBounds();
		}
	}
}
