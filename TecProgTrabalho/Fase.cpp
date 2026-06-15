#include <cmath>
#include "Jogo.h"
#include "Fase.h"

namespace Fases {
	Jogo* Fase::pJogo = nullptr;
	Gerenciador::Gerenciador_Colisoes* Fase::pGC = nullptr;

	Fase::Fase() : Ente(), maxAliens(rand() % 17 + 3), maxPlat(rand() % 5 + 3), chao(), pJog1(NULL), pJog2(NULL) {
		std::cout << "Criando fase: " << getId() << std::endl;

		pJog1 = pJogo->getJogador(1);
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
		if (pJog1->getAtaque()) lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1->getAtaque()));

		pJog2 = pJogo->getJogador(2);
		lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog2));
		if (pJog2->getAtaque()) lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog2->getAtaque()));
	}

	Fase::Fase(const nlohmann::json& dados) : Ente(dados[0]["id"]),
		maxAliens(dados[0]["maxAliens"]), maxPlat(dados[0]["maxPlat"]), chao(), pJog1(NULL), pJog2(NULL) {

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
		else std::cerr << "Nenhuma GC para ser executada" << std::endl;
		moverCamera();
	}

	void Fase::moverCamera() {
		if (pJog1 && pJog2 && pJog1->getVidas() && pJog2->getVidas()) {
			sf::Vector2f posJog = 0.5f * (pJog1->getPos() + pJog2->getPos());
			pGG->atualizarView(sf::Vector2f(std::fmax(posJog.x, pGG->getTamJanela().x * 0.5f),
				pGG->getTamJanela().y * 0.5f));
			pSprite->setPosition(sf::Vector2f(std::fmax(posJog.x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f));
		}
		else if (pJog1 && pJog1->getVidas()) {
			sf::Vector2f posJog = pJog1->getPos();
			pGG->atualizarView(sf::Vector2f(std::fmax(posJog.x, pGG->getTamJanela().x * 0.5f),
				pGG->getTamJanela().y * 0.5f));
			pSprite->setPosition(sf::Vector2f(std::fmax(posJog.x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f));
		}
		else if (pJog2 && pJog2->getVidas()) {
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

	void Fase::setJogo(Jogo* pJ) {
		pJogo = pJ;
	}

	void Fase::setGC(Gerenciador::Gerenciador_Colisoes* pG) {
		if (pG) pGC = pG;
		else std::cerr << "GC não incluido na fase." << std::endl;
	}
	
	/*void Fase::salvar() {

	}*/
}