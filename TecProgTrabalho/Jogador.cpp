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
	vel.y = -5.0f;
	vel.x = -5.0f;
	pSprite = new sf::Sprite(textura);
	pSprite->setScale(sf::Vector2f(1.0f,1.0f));
	pSprite->setPosition(pos);
	pSprite->setScale(sf::Vector2f(6.0f, 6.0f));
	std::cout << "Criando jogador: " << getId() << std::endl;

}

Jogador::~Jogador() {
	std::cout << "Deletando jogador: " << getId() << std::endl;

}

void Jogador::colidir(Inimigo* pIn) {
}

void Jogador::executar() {
	//std::cout << "ID: " << getId() << " Pos: (" << pos.x << ", " << pos.y << ")" << std::endl;
	mover();
}

void Jogador::desenhar() {
	pGG->desenhar(pSprite);
	Entidade::desenhar();
}

void Jogador::salvar() {

}

void Jogador::mover() {
	if (sf::Keyboard::isKeyPressed(tecla_cima)) {
		pos.y += vel.y;
	}
	if (sf::Keyboard::isKeyPressed(tecla_baixo)) {
		pos.y -= vel.y;
	}
	if (sf::Keyboard::isKeyPressed(tecla_esquerda)) {
		pos.x += vel.x;
	}
	if (sf::Keyboard::isKeyPressed(tecla_direita)) {
		pos.x -= vel.x;
	}
	setPos(pos);
}

void Jogador::setPos(sf::Vector2f p) {
	Entidade::setPos(p);
	pSprite->setPosition(pos);
}

void Jogador::setTeclas(sf::Keyboard::Key cima, sf::Keyboard::Key baixo, sf::Keyboard::Key esq, sf::Keyboard::Key dir) {
	tecla_cima = cima;
	tecla_baixo = baixo;
	tecla_esquerda = esq;
	tecla_direita = dir;
}