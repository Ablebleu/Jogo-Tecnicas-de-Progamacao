#include "Fase_Segunda.h"
#include "Chefao.h"
#include "Projetil.h"
#include "Laser.h"

namespace Fases {
	Fase_Segunda::Fase_Segunda() : Fase(), maxChefoes(rand()%3+3), maxLasers(rand()%3+3) {
		criarCenario();
		criarObstaculo();
		criarInimigos();
	}

	Fase_Segunda::~Fase_Segunda() {

	}

	void Fase_Segunda::criarChefoes() {
		for (int i = 0; i < maxChefoes; i++) {
			Entidades::Chefao* pChef = new Entidades::Chefao(sf::Vector2f(1200.0f + 2500.f / maxChefoes * i, 300.0f), 0, 1);
			if (pChef) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pChef));
			}
		}
	}

	void Fase_Segunda::criarLasers() {
		for (int i = 0; i < maxLasers; i++) {
			Entidades::Obstaculos::Laser* pLaser = new Entidades::Obstaculos::Laser(sf::Vector2f(1200.0f + 2500.f / maxLasers * i, -60.0f), 1.0f, 1.5f, 60);
			if (pLaser) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pLaser));
			}
		}
	}

	void Fase_Segunda::criarProjeteis() {
		for (int i = 0; i < maxChefoes; i++) {
			Entidades::Projetil* proj = new Entidades::Projetil();
			if (proj) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(proj));
			}
		}
	}

	void Fase_Segunda::criarInimigos() {
		criarAliens();
		criarProjeteis();
		criarChefoes();
	}

	void Fase_Segunda::criarObstaculo() {
		criarPlataformas();
		criarLasers();
	}

	void Fase_Segunda::criarCenario() {
		//Adicionar sprite diferente
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/red-preview.png"));
		pSprite->setScale(sf::Vector2f(5.0f, 5.43f));
		pSprite->setPosition(sf::Vector2f(0.0f, 0.0f));
	}

	void Fase_Segunda::executar() {
		Fase::executar();
	}
}