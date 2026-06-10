#include <stdlib.h>
#include "Fase_Primeira.h"
#include "Acelerador.h"
#include "UFO.h"

namespace Fases {
	Fase_Primeira::Fase_Primeira() : Fase(), maxUFOs(rand() % 3 + 3), maxAcel(rand() % 3 + 3) {
		criarCenario();
		criarObstaculo();
		criarInimigos();
		//criarObstMedios();
		//criarInimgos();

		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1->getAtaque()));
	}

	Fase_Primeira::~Fase_Primeira() {

	}

	void Fase_Primeira::executar() {
		Fase::executar();
	}

	void Fase_Primeira::criarUFOs() {
		for (int i = 0; i < maxUFOs; i++) {
			Entidades::UFO* pUFO1 = new Entidades::UFO(sf::Vector2f(1400.0f + 2500.f / maxUFOs * i, 350.0f+rand()%125* 1.0f), 0, 1.0f);
			if (pUFO1) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pUFO1));
			}			
		}
	}

	void Fase_Primeira::criarAceleradores() {
		for (int i = 0; i < maxAcel; i++) {
			Entidades::Obstaculos::Acelerador* pAcel = new Entidades::Obstaculos::Acelerador(sf::Vector2f(1500.0f+2500.f/maxAcel*i, 550.0f), 7.0f, 7.0f);
			if (pAcel) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pAcel));
			}
		}
	}

	void Fase_Primeira::criarInimigos() {
		criarAliens();
		criarUFOs();
	}

	void Fase_Primeira::criarObstaculo() {
		criarPlataformas();
		criarAceleradores();
	}
	void Fase_Primeira::criarCenario() {
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/blue-preview.png"));
		pSprite->setScale(sf::Vector2f(1.5f, 1.45f));
		pSprite->setPosition(sf::Vector2f(0.0f, 0.0f));
	}
}