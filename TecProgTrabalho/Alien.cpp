#include <cmath>
#include "Alien.h"
#include "Jogador.h"

Alien::Alien(sf::Vector2f p, int n, float tam): Inimigo(p, n), tamanho(tam) {
	std::cout << "Criando Alien: " << getId() << std::endl;
	pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien_idle.png"));
	pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 32,32 }));
	pos = p;
	pSprite->setPosition(pos);
	pSprite->setScale(tam*sf::Vector2f(3.5f, 3.5f));
}

Alien::~Alien() {
}

void Alien::salvar() {

}

void Alien::executar() {
	//std::cout << "Movendo Alien" << pos.x << " " << pos.y << std::endl;
	mover();
}

void Alien::desenhar() {
	pGG->desenhar(pSprite);
	//std::cout << "Desenhando Alien" << pos.x << " " << pos.y << std::endl;
	Entidade::desenhar();
}

void Alien::danificar(Jogador *p) {	

}

void Alien::mover() {
	if (framesPosAprox > 0) {
		framesPosAprox--;
		Personagem::mover();
	}
	else {
		for (int i = 0; i < 2; i++) {
			Jogador* pJog = pGC->getJogadores(1 + i);
			if (pJog) {
				sf::Vector2f posJog = pJog->getPos();
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
				//std::cout << "Movendo Alien " << getId() << " Vel: (" << vel.x << ", " << vel.y << ")" << std::endl;
				Personagem::mover();
			}
		}
		//else std::cout << i << std::endl;
	}
}

void Alien::setPos(sf::Vector2f p) {
	//Hitbox
	Entidade::setPos(p);

	//Sprite
	pSprite->setPosition(pos + sf::Vector2f(-32.f, -26.f));
}