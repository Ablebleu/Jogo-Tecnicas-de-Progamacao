#include "Inimigo.h"

namespace Entidades {
	Inimigo::Inimigo(sf::Vector2f p, int n) : posInicial(p), nivel_maldade(n), framesPosAprox(0) {
		pGC->incluirInimigo(this);
		pos = p;
	}

	Inimigo::Inimigo(const nlohmann::json& dados) : Personagem(dados), 
		posInicial(sf::Vector2f(dados["posInicialx"], dados["posInicialy"])), 
		nivel_maldade(dados["nivel_maldade"]), framesPosAprox(dados["framesPosAprox"]) {
		pGC->incluirInimigo(this);
	}

	Inimigo::~Inimigo() {
		nivel_maldade = 0;
	}

	void Inimigo::salvarDataBuffer() {
		Personagem::salvarDataBuffer();

		dadosSalvos["tipo_base"] = "Inimigo";
		dadosSalvos["nivel_maldade"] = nivel_maldade;
		dadosSalvos["framesPosAprox"] = framesPosAprox;
		dadosSalvos["posInicialx"] = posInicial.x;
		dadosSalvos["posInicialy"] = posInicial.y;
	}
}