#include <stdlib.h>
#include "Fase_Primeira.h"
#include "Plataforma.h"
#include "Acelerador.h"
#include "UFO.h"
#include "Alien.h"

namespace Fases {
	Fase_Primeira::Fase_Primeira() : Fase() {
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/blue-preview.png"));
		pSprite->setScale(sf::Vector2f(1.5f, 1.45f));
		pSprite->setPosition(sf::Vector2f(0.0f, 0.0f));
		criar();
	}

	Fase_Primeira::~Fase_Primeira() {

	}

	void Fase_Primeira::executar() {
		Fase::executar();
	}

	void Fase_Primeira::criar() {
		criarCenario();
		criarObstaculo();
		criarInimFaceis();
		criarInimMedios();
		//criarObstMedios();
		//criarInimgos();
		lista_ents.incluir(static_cast<Entidade*>(pJog1));
		lista_ents.incluir(static_cast<Entidade*>(pJog1->getAtaque()));
	}


	void Fase_Primeira::criarInimFaceis() {
		Alien* pAlien1 = new Alien(sf::Vector2f(1200.0f, 550.0f), 0, 1.0f);
		if (pAlien1) {
			lista_ents.incluir(static_cast<Entidade*>(pAlien1));
		}
		Alien* pAlien2 = new Alien(sf::Vector2f(2200.0f, 550.0f), 0, 1.0f);
		if (pAlien2) {
			lista_ents.incluir(static_cast<Entidade*>(pAlien2));
		}
		Alien* pAlien3 = new Alien(sf::Vector2f(3000.0f, 550.0f), 0, 1.0f);
		if (pAlien3) {
			lista_ents.incluir(static_cast<Entidade*>(pAlien3));
		}
		for (int i = 0; i < 50; i++) {
			if (std::rand() % 100 < 25) {
				Alien* pAlien = new Alien(sf::Vector2f(1200.0f + i * 150.f, 550.0f), 0, 1.0f);
				if (pAlien) {
					lista_ents.incluir(static_cast<Entidade*>(pAlien));
				}
			}
		}
	}

	void Fase_Primeira::criarInimMedios() {
		UFO* pUFO1 = new UFO(sf::Vector2f(1000.0f, 450.0f), 0, 1.0f);
		if (pUFO1) {
			lista_ents.incluir(static_cast<Entidade*>(pUFO1));
		}
	}

	void Fase_Primeira::criarObstMedios() {

	}

	void Fase_Primeira::criarInimigos() {

	}

	void Fase_Primeira::criarObstaculo() {
		Plataforma* pPlat1 = new Plataforma(sf::Vector2f(1200.0f, 300.0f), sf::Vector2f(2.0f, 1.0f));
		if (pPlat1) {
			lista_ents.incluir(static_cast<Entidade*>(pPlat1));
		}
		Plataforma* pPlat2 = new Plataforma(sf::Vector2f(2000.0f, 450.0f), sf::Vector2f(2.0f, 1.0f));
		if (pPlat2) {
			lista_ents.incluir(static_cast<Entidade*>(pPlat2));
		}
		Plataforma* pPlat3 = new Plataforma(sf::Vector2f(3200.0f, 300.0f), sf::Vector2f(2.0f, 1.0f));
		if (pPlat3) {
			lista_ents.incluir(static_cast<Entidade*>(pPlat3));
		}
		for (int i = 0; i < 30; i++) {
			if (std::rand() % 100 < 10 + i) {
				Plataforma* pPlat3 = new Plataforma(sf::Vector2f(800.0f + i * 200.f, 300.0f + std::rand() % 250 * 1.0f),
					sf::Vector2f(2.0f + rand() % 2 * 1.f - 1.0f, 1.0f + std::rand() % 2 * 0.5f - 0.5f));
				if (pPlat3) {
					lista_ents.incluir(static_cast<Entidade*>(pPlat3));
				}
			}
		}

		Acelerador* pAcel1 = new Acelerador(sf::Vector2f(1100.0f, 550.0f), 7.0f, 7.0f);
		if (pAcel1) {
			lista_ents.incluir(static_cast<Entidade*>(pAcel1));
		}
	}
	void Fase_Primeira::criarCenario() {
		/*Cenario* pBackground = new Cenario("assets/sprites/Background-fase-1/blue-with-stars.png",
			sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), 6.0f);
		if (pBackground)lista_ents.incluir(static_cast<Entidade*>(pBackground));
		Cenario* pPlanetaG = new Cenario("assets/sprites/Background-fase-1/prop-planet-big.png",
			sf::Vector2f(400.0f, 610.0f), sf::Vector2f(0.3f, -0.3f), 6.0f);
		if (pPlanetaG)lista_ents.incluir(static_cast<Entidade*>(pPlanetaG));
		Cenario* pPlanetaP = new Cenario("assets/sprites/Background-fase-1/prop-planet-small.png",
			sf::Vector2f(800.0f, 250.0f), sf::Vector2f(-0.5f, -0.2f), 6.0f);
		if (pPlanetaP)lista_ents.incluir(static_cast<Entidade*>(pPlanetaP));
		Cenario* Astro1 = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
			sf::Vector2f(1200.0f, 500.0f), sf::Vector2f(0.10f, -0.15f), 6.0f);
		if (Astro1)lista_ents.incluir(static_cast<Entidade*>(Astro1));
		Cenario* Astro1b = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
			sf::Vector2f(250.0f, 270.0f), sf::Vector2f(-0.8f, -0.13f), 6.0f);
		if (Astro1b)lista_ents.incluir(static_cast<Entidade*>(Astro1b));
		Cenario* Astro2 = new Cenario("assets/sprites/Background-fase-1/asteroid-2.png",
			sf::Vector2f(400.0f, 650.0f), sf::Vector2f(-10.0f, -0.1f), 6.0f);
		if (Astro2)lista_ents.incluir(static_cast<Entidade*>(Astro2*/
	}
}