#include "Chefao.h"

namespace Entidades {
	Chefao::Chefao(sf::Vector2f p, int n, int f) : Inimigo(p, n), forca() {
		std::cout << "Criando Chefao: " << getId() << std::endl;
		//pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien_idle.png"));
		//pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 32,32 }));
		pSprite->setPosition(pos);
		pSprite->setScale(sf::Vector2f(3.5f, 3.5f));
	}

	Chefao::~Chefao() {

	}

	void Chefao::salvar() {

	}

	void Chefao::executar() {

	}

	void Chefao::danificar(Jogador* p) {

	}

	void Chefao::mover() {

	}
}