#include "Fase_Segunda.h"
#include "Monstro.h"
#include "Projetil.h"
#include "Laser.h"
#include "Jogo.h"

using nlohmann::json;
namespace Fases {
	Fase_Segunda::Fase_Segunda() : Fase(), maxMonstros(rand()%3+3), maxLasers(rand()%3+3) {
		criarCenario();
		criarObstaculo();
		criarInimigos();
	}

	Fase_Segunda::Fase_Segunda(const nlohmann::json& dados) : Fase(dados), 
		maxMonstros(dados[0]["maxMonstros"]), maxLasers(dados[0]["maxLasers"]) {
		criarCenario();
		for (int i = 1; i < (int)dados.size(); i++) {
			std::string tipo = dados[i]["tipo"];
			if (tipo == "Plataforma") {
				Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma(dados[i]);
				if (pPlat) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pPlat));
				}
			}
			else if (tipo == "Laser") {
				Entidades::Obstaculos::Laser* pLaser = new Entidades::Obstaculos::Laser(dados[i]);
				if (pLaser) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pLaser));
				}
			}
			else if (tipo == "Alien") {
				Entidades::Alien* pAlien = new Entidades::Alien(dados[i]);
				if (pAlien) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pAlien));
				}
			}
			else if (tipo == "Projetil") {
				Entidades::Projetil* pProj = new Entidades::Projetil(dados[i]);
				if (pProj) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pProj));
				}
			}
			else if (tipo == "Monstro") {
				Entidades::Monstro* pMons = new Entidades::Monstro(dados[i]);
				if (pMons) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pMons));
				}
			}
			else if (tipo == "Jogador") {
				if (dados[i]["ordemJogador"] == 1) {
					pJog1 = pJogo->getJogador(dados[i]);
					if (pJog1) {
						lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1));
						if (pJog1->getAtaque()) lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog1->getAtaque()));
					}
				}
				if (dados[i]["ordemJogador"] == 2) {
					pJog2 = pJogo->getJogador(dados[i]);
					if (pJog2) {
						lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog2));
						if (pJog2->getAtaque()) lista_ents.incluir(static_cast<Entidades::Entidade*>(pJog2->getAtaque()));
					}
				}
			}
		}
		moverCamera();
	}

	Fase_Segunda::~Fase_Segunda() {
		salvar();
	}

	void Fase_Segunda::criarMonstros() {
		for (int i = 0; i < maxMonstros; i++) {
			Entidades::Monstro* pMons = new Entidades::Monstro(sf::Vector2f(1200.0f + 2500.f / maxMonstros * i, 300.0f), 0, rand()%2 + 2);
			if (pMons) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(pMons));
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
		for (int i = 0; i < maxMonstros; i++) {
			Entidades::Projetil* proj = new Entidades::Projetil();
			if (proj) {
				lista_ents.incluir(static_cast<Entidades::Entidade*>(proj));
			}
		}
	}

	void Fase_Segunda::criarInimigos() {
		criarAliens();
		criarProjeteis();
		criarMonstros();
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

	void Fase_Segunda::salvar() {
		json arquivoJson = json::array();
		json dadosFase{
			{"tipo", "Fase_Segunda"},
			{"id", getId()},
			{"maxAliens", maxAliens},
			{"maxPlat", maxPlat},
			{"maxMonstros", maxMonstros},
			{"maxLasers", maxLasers}
		};
		arquivoJson.push_back(dadosFase);
		lista_ents.salvarEntidades(arquivoJson);
		std::ofstream file("save.json");
		file << arquivoJson.dump(4);
		file.close();
	}
}