#include "Gerenciador_Eventos.h"
#include <SFML/Graphics.hpp>

using namespace Gerenciadores;

Gerenciador_Eventos::Gerenciador_Eventos(Gerenciador_Grafico *GG): pGG(GG) {}
Gerenciador_Eventos::~Gerenciador_Eventos();
void Gerenciador_Eventos::setGG(Gerenciador_Grafico* GG) { pGG = GG; }
void Gerenciador_Eventos::executar() {
	sf::Event evento;
	while (pGG->pollEvento(evento)) {
		if (evento.type == sf::Event::Closed) {
			pGG->fecharJanela();
		}
	}
}