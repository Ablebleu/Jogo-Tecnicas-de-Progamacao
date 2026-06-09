#include "Fase_Segunda.h"
#include "Chefao.h"
#include "Projetil.h"

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
			Entidades::Chefao* pChef = new Entidades::Chefao(sf::Vector2f(1200.0f + 2500.f / maxChefoes * i, 550.0f), 0, 1);
			if (pChef) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pChef));
			}
		}
	}

	void Fase_Segunda::criarLasers() {

	}

	void Fase_Segunda::criarProjeteis() {
		Entidades::Projetil* proj = new Entidades::Projetil();
		if (proj) {
			lista_ents.incluir(static_cast<Entidades::Entidade*>(proj));
		}
	}

	void Fase_Segunda::criarInimigos() {
		criarAliens();
		//criarChefoes();
		//criarProjeteis();
	}

	void Fase_Segunda::criarObstaculo() {
		criarPlataformas();
		//criarLasers();
	}

	void Fase_Segunda::criarCenario() {
		//Adicionar sprite diferente
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/blue-preview.png"));
		pSprite->setScale(sf::Vector2f(1.5f, 1.45f));
		pSprite->setPosition(sf::Vector2f(0.0f, 0.0f));
	}

	void Fase_Segunda::executar() {
		Fase::executar();
	}
}