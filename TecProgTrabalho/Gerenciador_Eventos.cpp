#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;

Gerenciador_Eventos::Gerenciador_Eventos(Gerenciador_Grafico *GG): pGG(GG) {}
Gerenciador_Eventos::~Gerenciador_Eventos() {}

void Gerenciador_Eventos::setGG(Gerenciador_Grafico* GG) { pGG = GG; }
void Gerenciador_Eventos::executar() {
	if(!pGG) {
		std::cerr << "Gerenciador Grafico nao setado em Gerenciador Eventos" << std::endl;
		return;
	}
	while (const std::optional<sf::Event> evento = pGG->atualizaEvento()){
		if (evento->is<sf::Event::Closed>()) {
			pGG->fecharJanela();
		}
	}
}