#include <iostream>
#include "Jogador.h"

Jogador::Jogador(): Personagem(), pontos(0), 
tecla_cima(sf::Keyboard::Key::W), tecla_baixo(sf::Keyboard::Key::S),
tecla_esquerda(sf::Keyboard::Key::A), tecla_direita(sf::Keyboard::Key::D) {
	std::cout << "Criando jogador: " << getId() << std::endl;

	/*
	Abaixo está um memory leak sutil, pois o ponteiro da textura, que é dinâmico, é perdido,
	Por isso é necessário que o Gerenciador_grafico guarde texturas num vetor e delete em
	seu fim.
	*/

	//hitbox
	corpo.setSize(sf::Vector2f(80.0f, 80.0f));
	corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });//origem -> centro da hitbox

	//sprite
	pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Astronaut_Idle.png"));
	pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 16 }));
	pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
	pos.x = 800.0f;
	pos.y = 500.0f;
	pSprite->setPosition(pos);
	pSprite->setScale(sf::Vector2f(5.0f, 5.0f));
	pGC->setJogadores(this);
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
	//pGG->desenhar(pSprite);
	Entidade::desenhar();
}

void Jogador::salvar() {

}

void Jogador::acelerar() {
	if (sf::Keyboard::isKeyPressed(tecla_direita)) {
		vel.x += 3.0f;
		if(pSprite->getScale().x < 0)
		{
			pSprite->setScale({ 5.0f, 5.0f });
		}
	}
	else if (sf::Keyboard::isKeyPressed(tecla_esquerda)) {
		vel.x += -3.0f;
		if (pSprite->getScale().x > 0)
		{
			pSprite->setScale({ -5.0f, 5.0f });
		}
	}
}

void Jogador::pular() {
	if (sf::Keyboard::isKeyPressed(tecla_cima)) {
		Personagem::pular(); 
	}
}

void Jogador::mover() {
	pular();
	acelerar();
	//std::cout << vel.y << std::endl;
	Personagem::mover();
	setPos(pos);

}

void Jogador::setPos(sf::Vector2f p) {
	//Hitbox
	Entidade::setPos(p);
	//Sprite
	pSprite->setPosition(pos);
}

void Jogador::setTeclas(sf::Keyboard::Key cima, sf::Keyboard::Key baixo, sf::Keyboard::Key esq, sf::Keyboard::Key dir) {
	tecla_cima = cima;
	tecla_baixo = baixo;
	tecla_esquerda = esq;
	tecla_direita = dir;
}