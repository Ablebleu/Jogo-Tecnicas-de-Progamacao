#define _USE_MATH_DEFINES
#include <cmath>
#include "UFO.h"
#include "Jogador.h"

namespace Entidades {
	UFO::UFO(sf::Vector2f p, int n, float r) : Inimigo(p, n), raio(r), posEixoY(p.y), graus(0) {
		std::cout << "Criando Alien Medio: " << getId() << std::endl;
		//hitbox
		corpo.setSize(sf::Vector2f(16.f, 16.f));
		corpo.setScale(raio * sf::Vector2f(3.5f, 3.5f));
		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien2.png"));
		pSprite->setPosition(pos);
		pSprite->setScale(raio * sf::Vector2f(3.5f, 3.5f));
	}

	UFO::UFO(const nlohmann::json& dados) : Inimigo(dados), raio(dados["raio"]), 
		posEixoY(pos.y), graus(dados["graus"]) {
		std::cout << "Criando Alien Medio: " << getId() << std::endl;
		//hitbox
		corpo.setSize(sf::Vector2f(16.f, 16.f));
		corpo.setScale(raio * sf::Vector2f(3.5f, 3.5f));
		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien2.png"));
		pSprite->setPosition(pos);
		pSprite->setScale(raio * sf::Vector2f(3.5f, 3.5f));

	}

	UFO::~UFO() {

	}

	void UFO::salvar() {
		Inimigo::salvarDataBuffer();
		dadosSalvos["tipo"] = "UFO";
		dadosSalvos["raio"] = raio;
		dadosSalvos["graus"] = graus;
	}

	void UFO::executar() {
		//std::cout << "Movendo Alien" << pos.x << " " << pos.y << std::endl;
		forcar();
		levitar();
		mover();
	}

	void UFO::desenhar() {
		pGG->desenhar(pSprite);
		//std::cout << "Desenhando Alien" << pos.x << " " << pos.y << std::endl;
		Entidade::desenhar();
	}

	void UFO::danificar(Jogador* p) {
		if (getVel().x < 0)
			p->setVel(p->getVel() + sf::Vector2f(-0.5f * raio, 0.f));
		else
			p->setVel(p->getVel() + sf::Vector2f(0.5f * raio, 0.f));
		(*p) -= (1 + nivel_maldade);
	}

	void UFO::levitar() {
		vel.y -= 0.5f;
	}

	void UFO::mover() {
		if (framesPosAprox > 0) {
			framesPosAprox--;
		}
		else {
			sf::Vector2f posJog;
			Jogador* pJog1 = pGC->getJogadores(1);
			Jogador* pJog2 = pGC->getJogadores(2);
			if (!pJog1)
				return;
			if (pJog2) {
				if (!pJog1->getVivo() || (std::abs(pJog2->getPos().x - pos.x) < std::abs(pJog1->getPos().x - pos.x) && pJog2->getVivo()))
					posJog = pJog2->getPos();
				else
					posJog = pJog1->getPos();
			}
			if (std::abs(posJog.x - pos.x) < 500) {
				if (std::abs(posJog.x - pos.x) < 10) {
					framesPosAprox = 60;
				}
				if (posJog.x < pos.x) {
					vel.x += -1.5f;
				}
				else if (posJog.x > pos.x) {
					vel.x += 1.5f;
				}
			}
			else {
				if (posInicial.x < pos.x) {
					vel.x += -1.f;
				}
				else if (posInicial.x > pos.x) {
					pos.x += 1.f;
				}
			}
		}
		//std::cout << "Movendo Alien " << getId() << " Vel: (" << vel.x << ", " << vel.y << ")" << std::endl;
		Personagem::mover();
		graus = (graus + 1) % 360;
	}

	void UFO::setPos(sf::Vector2f p) {
		//Hitbox
		float angulo = (float) M_PI / 180;
		Entidade::setPos(sf::Vector2f(p.x, posEixoY + 100.f * sin(graus*angulo)));

		//Sprite
		pSprite->setPosition(sf::Vector2f(p.x /*-32.f*/, posEixoY + /*-26.f*/ +100.f * sin(graus * angulo)));
	}
}