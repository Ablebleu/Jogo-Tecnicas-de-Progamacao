#include <stdlib.h>
#include "Fase_Primeira.h"
#include "Acelerador.h"
#include "UFO.h"
#include "Jogo.h"

using nlohmann::json;
namespace Fases {
	Fase_Primeira::Fase_Primeira() : Fase(), maxUFOs(rand() % 3 + 3), maxAcel(rand() % 3 + 3) {
		criarCenario();
		criarObstaculo();
		criarInimigos();
	}

	Fase_Primeira::Fase_Primeira(const nlohmann::json& dados) : Fase(dados),
		maxUFOs(dados[0]["maxUFOs"]), maxAcel(dados[0]["maxAcel"]) {
		criarCenario();
		for(int i = 1; i < (int)dados.size(); i++) {
			std::string tipo = dados[i]["tipo"];
			if (tipo == "Plataforma") {
				Entidades::Obstaculos::Plataforma* pPlat = new Entidades::Obstaculos::Plataforma(dados[i]);
				if (pPlat) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pPlat));
				}
			}
			else if (tipo == "Acelerador") {
				Entidades::Obstaculos::Acelerador* pAcel = new Entidades::Obstaculos::Acelerador(dados[i]);
				if (pAcel) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pAcel));
				}
			}
			else if (tipo == "Alien") {
				Entidades::Alien* pAlien = new Entidades::Alien(dados[i]);
				if (pAlien) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pAlien));
				}
			}
			else if (tipo == "UFO") {
				Entidades::UFO* pUFO = new Entidades::UFO(dados[i]);
				if (pUFO) {
					lista_ents.incluir(static_cast<Entidades::Entidade*>(pUFO));
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

	Fase_Primeira::~Fase_Primeira() {
		salvar();
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

	void Fase_Primeira::salvar() {
		json arquivoJson = json::array();
		json dadosFase = {
			{"tipo", "Fase_Primeira"},
			{"id", getId()},
			{"maxAliens", maxAliens},
			{"maxPlat", maxPlat},
			{"maxUFOs", maxUFOs},
			{"maxAcel", maxAcel}
		};
		arquivoJson.push_back(dadosFase);
		lista_ents.salvarEntidades(arquivoJson);
		std::ofstream file("save.json");
		file << arquivoJson.dump(4);
		file.close();
	}
}