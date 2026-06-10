#include <iostream>
#include "Jogador.h"

namespace Entidades {
	Jogador::Jogador() : Personagem(), pontos(0), hp(*pGG->carregarTextura("assets/sprites/hp1.png")),
		tecla_cima(sf::Keyboard::Key::W), tecla_baixo(sf::Keyboard::Key::S),
		tecla_esquerda(sf::Keyboard::Key::A), tecla_direita(sf::Keyboard::Key::D) {
		std::cout << "Criando jogador: " << getId() << std::endl;

		//ataque -> buraco_negro
		pAtaque = new Buraco_Negro({ -50.0f, -50.0f }, 120);

		//hitbox
		corpo.setSize(sf::Vector2f(50.0f, 80.0f));
		corpo.setOrigin({ corpo.getSize().x / 2.0f , corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		hp.setScale(sf::Vector2f(2.f, 2.f));
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
		if (frameInv > 0) frameInv--;
		//std::cout << "ID: " << getId() << " Pos: (" << pos.x << ", " << pos.y << ")" << std::endl;
		forcar();
		mover();
		atacar();
	}

	void Jogador::desenhar() {
		//Vida
		hp.setTextureRect(sf::IntRect({ 64*(num_vidas+1)/**/,16}, {64 /**/, 48}));
		hp.setPosition(sf::Vector2f(std::fmax(pos.x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f) + sf::Vector2f(10.f, 10.f));
		pGG->desenhar(&hp);
		//Pontuação
		sf::Text texto(*pGG->getFonte());
		texto.setString(std::to_string(pontos));
		texto.setCharacterSize(18);
		texto.setFillColor(sf::Color::White);
		texto.setPosition(sf::Vector2f(std::fmax(pos.x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f) + sf::Vector2f(180.f, 29.f));
		//pontos += 100;
		pGG->desenhar(&texto);
		//Sprite e corpo
		Entidade::desenhar();
	}

	void Jogador::salvar() {

	}

	void Jogador::acelerar() {
		if (sf::Keyboard::isKeyPressed(tecla_direita)) {
			vel.x += 0.5f;
			if (pSprite->getScale().x < 0)
			{
				pSprite->setScale({ 5.0f, 5.0f });
			}
		}
		else if (sf::Keyboard::isKeyPressed(tecla_esquerda)) {
			vel.x += -0.5f;
			if (pSprite->getScale().x > 0)
			{
				pSprite->setScale({ -5.0f, 5.0f });
			}
		}
	}

	void Jogador::pular() {
		if (sf::Keyboard::isKeyPressed(tecla_cima)) {
			if (contatoBase) {
				vel.y = -90.0f;
				contatoBase = false;
			}
		}
	}

	void Jogador::mover() {
		pular();
		acelerar();
		//std::cout << vel.y << std::endl;
		Personagem::mover();
		setPos(pos);
	}

	void Jogador::operator-=(int dano) {
		if (!frameInv) {
			Personagem::operator-=(dano);
			frameInv = 60;
		}
	}

	void Jogador::atacar() {
		if (sf::Keyboard::isKeyPressed(tecla_baixo) && pAtaque->getAtivo() == false)
		{
			pAtaque->setAtivo(true);
			pAtaque->setPos(pos + sf::Vector2f(100.0f, -10.0f));
		}
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

	Buraco_Negro* Jogador::getAtaque() {
		return pAtaque;
	}
}