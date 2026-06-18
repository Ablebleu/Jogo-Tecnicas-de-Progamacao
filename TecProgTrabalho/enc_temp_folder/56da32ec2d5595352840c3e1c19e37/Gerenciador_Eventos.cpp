#include "Gerenciador_Eventos.h"
#include "Gerenciador_Grafico.h"
#include "Estado.h"
#include <iostream>

Gerenciador::Gerenciador_Evento* Gerenciador::Gerenciador_Evento::pEvento = nullptr;
namespace Gerenciador {
	Gerenciador_Evento::Gerenciador_Evento() : pGG(nullptr), enterLiberado(true), Observadores() {
		std::cout << "Criando Gerenciador de Eventos" << std::endl;
		Observadores.clear();
		pGG = Gerenciador_Grafico::getGerenciador_Grafico();
		Estados::Estado::setGE(this);
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
			if (0/*Observador*/) {
				/*Observador->processarEvento(evento);*/
			}
		}

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
			enterLiberado = true;
		}
	}

	void Gerenciador_Evento::incluirObservador(Observadores::Observer* pObs) {
		Observadores.push_back(pObs);
		enterLiberado = false;
	}

	void Gerenciador_Evento::removerObservador(Observadores::Observer* pObs) {
		if (pObs) {
			Observadores.erase(std::remove(Observadores.begin(), Observadores.end(), pObs),
				Observadores.end());
		}
	}

	Gerenciador_Evento::~Gerenciador_Evento() {
		std::cout << "Deletando Gerenciador de Eventos" << std::endl;
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