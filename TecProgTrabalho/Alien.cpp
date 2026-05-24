#include "Alien.h"
#include "Jogador.h"

Alien::Alien(sf::Vector2f p, int n, float tam): Inimigo(p, n), tamanho(tam) {
	//pSprite = new sf::Sprite(*pGG->carregarTextura(""));
	pos = p;
	vel.x = 3.f;
	//pSprite->setPosition(pos);
	//pSprite->setScale(tam*sf::Vector2f(6.0f, 6.0f));
}

Alien::~Alien() {
	delete pSprite;
}

void Alien::salvar() {

}

void Alien::executar() {
	//std::cout << "Movendo Alien" << pos.x << " " << pos.y << std::endl;
	mover();
}

void Alien::desenhar() {
	//pGG->desenhar(pSprite);
	//std::cout << "Desenhando Alien" << pos.x << " " << pos.y << std::endl;
	Entidade::desenhar();
}

void Alien::danificar(Jogador *p) {	

}

void Alien::mover() {
	for (int i = 0; i < 2; i++) {
		Jogador* pJog = pGC->getJogadores(1+i);
		if (pJog) {
			sf::Vector2f posJog = pJog->getPos();
			if (posJog.x < pos.x) {
				pos.x += -vel.x;
			}
			else if (posJog.x > pos.x) {
				pos.x += vel.x;
			}
			setPos(pos);
		}
		//else std::cout << i << std::endl;
	}
}