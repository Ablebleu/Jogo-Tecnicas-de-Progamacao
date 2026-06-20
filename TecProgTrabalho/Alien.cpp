#include <cmath>
#include "Alien.h"
#include "Jogador.h"

namespace Entidades {
	Alien::Alien(sf::Vector2f p, int n, int tam) : Inimigo(p, n), tamanho(tam) {
		std::cout << "Criando Alien: " << getId() << std::endl;
		//hitbox
		corpo.setSize(sf::Vector2f(12.0f, 18.0f));
		corpo.setScale((float)tamanho * sf::Vector2f(3.5f, 3.5f));
		corpo.setOrigin({ corpo.getSize().x / 2.0f , corpo.getSize().y / 2.0f });
		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien_idle.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 12,18 }));
		pSprite->setPosition(pos);
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });
		pSprite->setScale((float)tamanho * sf::Vector2f(3.5f, 3.5f));
	}

	Alien::Alien(const nlohmann::json& dados) : Inimigo(dados), tamanho(dados["tamanho"]) {
		std::cout << "Criando Alien: " << getId() << std::endl;
		//hitbox
		corpo.setSize(sf::Vector2f(12.0f, 18.0f));
		corpo.setScale((float)tamanho * sf::Vector2f(3.5f, 3.5f));
		corpo.setOrigin({ corpo.getSize().x / 2.0f , corpo.getSize().y / 2.0f });
		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Alien_idle.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 12,18 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });
		pSprite->setPosition(pos);
		pSprite->setScale((float)tamanho * sf::Vector2f(3.5f, 3.5f));
		pSprite->setScale(sf::Vector2f(-pSprite->getScale().x * virado * 2 + pSprite->getScale().x, pSprite->getScale().y));
	}

	Alien::~Alien() {
	}

	void Alien::salvar() {
		Inimigo::salvarDataBuffer();
		dadosSalvos["tipo"] = "Alien";
		dadosSalvos["tamanho"] = tamanho;
	}

	void Alien::executar() {
		if(vivo)
		{
			//std::cout << "Movendo Alien" << pos.x << " " << pos.y << std::endl;
			forcar();
			mover();
		}
	}

	void Alien::danificar(Jogador* p) {
		int dano = (int)(p->getVidas()/9.f * (tamanho + nivel_maldade));
		if (dano <= 0) dano = 1;
		*p -= dano;
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
					if (pSprite->getScale().x > 0)
					{
						virado = true;
						pSprite->setScale(sf::Vector2f((float)tamanho * sf::Vector2f(-7.f*virado+3.5f, 3.5f)));
					}
				}
				else if (posJog.x > pos.x) {
					vel.x += 0.25f;

					if (pSprite->getScale().x < 0)
					{
						virado = false;
						pSprite->setScale(sf::Vector2f((float)tamanho * sf::Vector2f(-7.f * virado + 3.5f, 3.5f)));
					}
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
		pSprite->setPosition(pos);
	}
}