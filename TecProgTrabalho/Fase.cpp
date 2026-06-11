#include <cmath>
#include "Fase.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Alien.h"

namespace Fases {
	Gerenciador::Gerenciador_Colisoes* Fase::pGC = nullptr;

	Fase::Fase() : Ente(), maxAliens(rand() % 17 + 3), maxPlat(rand() % 5 + 3), chao(), pJog1(NULL) {
		std::cout << "Criando fase: " << getId() << std::endl;

		pJog1 = pGC->getJogadores(1);
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1->getAtaque()));

		pJog2 = pGC->getJogadores(2);
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog2));
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog2->getAtaque()));
	}

	Fase::~Fase() {
		std::cout << "Deletando fase: " << getId() << std::endl;
		lista_ents.deletarEntidades();
	}

	void Fase::criarAliens() {
		for (int i = 0; i < maxAliens; i++) {
			Entidades::Alien* pAlien = new Entidades::Alien(sf::Vector2f(1200.0f + 3400.f/maxAliens * i, 550.0f), 0, 1.0f);
			if (pAlien) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pAlien));
			}
		}
	}

	void Fase::criarPlataformas() {
		for (int i = 0; i < maxPlat; i++) {
			Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(1500.0f + 3000.f/maxPlat*i, 300.0f + std::rand() % 125 * 1.0f));
			if (pPlat) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pPlat));
			}
		}
	}

	void Fase::executar() {
		lista_ents.retiraEntidadesMortas();
		lista_ents.percorrer();
		if (pGC) {
			//std::cout << "Indo executar GC" << std::endl;
			pGC->executar();
			pGC->tratarColisoesChaoEntidades(chao);
		}
		else cerr << "Nenhuma GC para ser executada" << endl;
		moverCamera();
	}

	void Fase::moverCamera() {
		if (pJog1 && pJog2) {
			sf::Vector2f posJog = 0.5f * (pJog1->getPos() + pJog2->getPos());
			pGG->atualizarView(sf::Vector2f(std::fmax(posJog.x, pGG->getTamJanela().x * 0.5f),
				pGG->getTamJanela().y * 0.5f));
			pSprite->setPosition(sf::Vector2f(std::fmax(posJog.x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f));
		}
		else if (pJog1) {
			sf::Vector2f posJog = pJog1->getPos();
			pGG->atualizarView(sf::Vector2f(std::fmax(posJog.x, pGG->getTamJanela().x * 0.5f),
				pGG->getTamJanela().y * 0.5f));
			pSprite->setPosition(sf::Vector2f(std::fmax(posJog.x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f));
		}
		else if (pJog2) {
			sf::Vector2f posJog = pJog2->getPos();
			pGG->atualizarView(sf::Vector2f(std::fmax(posJog.x, pGG->getTamJanela().x * 0.5f),
				pGG->getTamJanela().y * 0.5f));
			pSprite->setPosition(sf::Vector2f(std::fmax(posJog.x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f));
		}
	}

	void Fase::incluirJogador(Entidades::Jogador* pE) {
		if (pE) lista_ents.incluir(static_cast<Entidades::Entidade*>(pE));
	}

	void Fase::desenhar() {
		pGG->desenhar(pSprite);
		chao.desenhar();
		lista_ents.desenhar();
	}

	void Fase::removerEntidade(int id) {
		lista_ents.remover(id);
	}

	void Fase::setGC(Gerenciador::Gerenciador_Colisoes* pG) {
		if (pG) pGC = pG;
		else cerr << "GC não incluido na fase." << endl;
	}
}