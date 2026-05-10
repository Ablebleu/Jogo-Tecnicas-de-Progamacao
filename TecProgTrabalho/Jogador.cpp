#include <iostream>
#include "Jogador.h"

Jogador::Jogador(): Personagem(), pontos(0), 
tecla_cima(sf::Keyboard::Key::W), tecla_baixo(sf::Keyboard::Key::S),
tecla_esquerda(sf::Keyboard::Key::A), tecla_direita(sf::Keyboard::Key::D) {
	if(!textura.loadFromFile("assets/sprites/Diamond.png")) {
		std::cerr << "Erro ao carregar textura do jogador!" << std::endl;
	}
	pos.x = 800.0f;
	pos.y = 500.0f;
	vel.y = -500.0f;
	vel.x = -500.0f;
	pSprite = new sf::Sprite(textura);
	pSprite->setScale(tam*7.0f);
	pSprite->setPosition(pos);
}

Jogador::~Jogador() {

}

void Jogador::colidir(Inimigo* pIn) {
}

void Jogador::executar(float dt) {
	if (sf::Keyboard::isKeyPressed(tecla_cima)) {
		pos.y += vel.y * dt;
	}
	if (sf::Keyboard::isKeyPressed(tecla_baixo)) {
		pos.y -= vel.y * dt;
	}
	if (sf::Keyboard::isKeyPressed(tecla_esquerda)) {
		pos.x += vel.x * dt;
	}
	if (sf::Keyboard::isKeyPressed(tecla_direita)) {
		pos.x -= vel.x * dt;
	}
	pSprite->setPosition(pos);
}

void Jogador::salvar() {

}

void Jogador::mover(float dt) {
}