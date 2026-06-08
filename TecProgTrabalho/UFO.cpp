#define _USE_MATH_DEFINES
#include <cmath>
#include "UFO.h"
#include "Jogador.h"

UFO::UFO(sf::Vector2f p, int n, float r) : Inimigo(p, n), raio(r), posEixoY(p.y), graus(0.f) {
	std::cout << "Criando Alien Medio: " << getId() << std::endl;
	pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien2.png"));
	pos = p;
	pSprite->setPosition(pos);
	pSprite->setScale(raio * sf::Vector2f(3.5f, 3.5f));
}

UFO::~UFO() {

}

void UFO::salvar() {

}

void UFO::executar() {
	//std::cout << "Movendo Alien" << pos.x << " " << pos.y << std::endl;
	levitar();
	mover();
}

void UFO::desenhar() {
	pGG->desenhar(pSprite);
	//std::cout << "Desenhando Alien" << pos.x << " " << pos.y << std::endl;
	Entidade::desenhar();
}

void UFO::danificar(Jogador* p) {

}

void UFO::levitar() {
	vel.y -= 0.5f;
}

void UFO::mover() {
	if (framesPosAprox > 0) {
		framesPosAprox--;
		Personagem::mover();
	}
	else {
		for (int i = 0; i < 2; i++) {
			Jogador* pJog = pGC->getJogadores(1 + i);
			if (pJog) {
				sf::Vector2f posJog = pJog->getPos();
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
				//std::cout << "Movendo Alien " << getId() << " Vel: (" << vel.x << ", " << vel.y << ")" << std::endl;
				Personagem::mover();
			}
		}
		//else std::cout << i << std::endl;
	}
	graus = (graus + 1) % 360;
}

void UFO::setPos(sf::Vector2f p) {
	//Hitbox
	float angulo = (float) M_PI / 180;
	Entidade::setPos(sf::Vector2f(p.x, posEixoY + 100.f * sin(graus*angulo)));

	//Sprite
	pSprite->setPosition(sf::Vector2f(p.x /*-32.f*/, posEixoY + /*-26.f*/ +100.f * sin(graus * angulo)));
}