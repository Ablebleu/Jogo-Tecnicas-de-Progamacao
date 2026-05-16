#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
#include <iostream>

Gerenciador::Gerenciador_Evento* Gerenciador::Gerenciador_Evento::pEvento = nullptr;
namespace Gerenciador {
	Gerenciador_Evento::Gerenciador_Evento() : pGG(nullptr) {
		pGG = Gerenciador_Grafico::getGerenciador_Grafico();
		if (!pGG) {
			std::cerr << "Erro ao disponibilizar Gerenciador Gráfico para o Gerenciador Eventos" << std::endl;
			exit(1);
		}
	}

	void Gerenciador_Evento::executar() {
		while (const std::optional<sf::Event> evento = pGG->atualizaEvento()) {
			if (evento->is<sf::Event::Closed>()) {
				pGG->fecharJanela();
			}
		}
	}

	Gerenciador_Evento::~Gerenciador_Evento() {

	}

	Gerenciador_Evento* Gerenciador_Evento::getGerenciador_Evento() {
		if (pEvento == nullptr) {
			pEvento = new Gerenciador_Evento();
		}
		return pEvento;
	}
	void Gerenciador_Evento::deletar() {
		if (pEvento) {
			delete pEvento;
			pEvento = nullptr;
		}
	}
}