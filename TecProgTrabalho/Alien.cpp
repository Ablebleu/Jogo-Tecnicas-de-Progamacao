#include <cmath>
#include "Alien.h"
#include "Jogador.h"

namespace Entidades {
	Alien::Alien(sf::Vector2f p, int n, float tam) : Inimigo(p, n), tamanho(tam) {
		std::cout << "Criando Alien: " << getId() << std::endl;
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien_idle.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 32,32 }));
		pSprite->setPosition(pos);
		pSprite->setScale(tam * sf::Vector2f(3.5f, 3.5f));
	}

	Alien::Alien(const nlohmann::json& dados) : Inimigo(dados), tamanho(dados["tamanho"]) {
		std::cout << "Criando Alien: " << getId() << std::endl;
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien_idle.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 32,32 }));
		pSprite->setPosition(pos);
		pSprite->setScale(tamanho * sf::Vector2f(3.5f, 3.5f));
	}

	Alien::~Alien() {
	}

	void Alien::salvar() {
		Inimigo::salvarDataBuffer();
		dadosSalvos["tipo"] = "Alien";
		dadosSalvos["tamanho"] = tamanho;
	}

	void Alien::executar() {
		//std::cout << "Movendo Alien" << pos.x << " " << pos.y << std::endl;
		forcar();
		mover();
	}

	void Alien::desenhar() {
		pGG->desenhar(pSprite);
		//std::cout << "Desenhando Alien" << pos.x << " " << pos.y << std::endl;
		Entidade::desenhar();
	}

	void Alien::danificar(Jogador* p) {
		*p -= 1;
	}

	void Alien::mover() {
		if (framesPosAprox > 0) {
			framesPosAprox--;
		}
		else {
			sf::Vector2f posJog;
			Jogador* pJog1 = pGC->getJogadores(1);
			Jogador* pJog2 = pGC->getJogadores(2);
			if (!pJog1)
				return;
			if(pJog2) {
				if (!pJog1->getVivo() || (std::abs(pJog2->getPos().x - pos.x) < std::abs(pJog1->getPos().x - pos.x) && pJog2->getVivo()))
					posJog = pJog2->getPos();
				else
					posJog = pJog1->getPos();
			}
			if (std::abs(posJog.x - pos.x) < 250) {
				if (std::abs(posJog.x - pos.x) < 10) {
					framesPosAprox = 30;
				}
				if (posJog.x < pos.x) {
					vel.x += -0.25f;
				}
				else if (posJog.x > pos.x) {
					vel.x += 0.25f;
				}
			}
			else {
				if (posInicial.x < pos.x) {
					vel.x += -0.3f;
				}
				else if (posInicial.x > pos.x) {
					vel.x += 0.3f;
				}
			}
		}
		//std::cout << "Movendo Alien " << getId() << " Vel: (" << vel.x << ", " << vel.y << ")" << std::endl;
		Personagem::mover();
	}

	void Alien::setPos(sf::Vector2f p) {
		//Hitbox
		Entidade::setPos(p);

		//Sprite
		pSprite->setPosition(pos + sf::Vector2f(-32.f, -26.f));
	}
}