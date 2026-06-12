#include "Laser.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos
	{
		Laser::Laser(sf::Vector2f p, float h, float l, int t) : Obstaculo(), altura(h), largura(l), tempoAtivo(t), ativo(true) {
			std::cout << "Criando laser: " << getId() << std::endl;
			//hitbox
			corpo.setSize(sf::Vector2f(18.0f, 88.0f));
			corpo.setScale({ 5.0f*h, 5.0f*l });

			//sprite
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/LaserCompleto.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
			pSprite->setPosition(p);
			pSprite->setScale({ 5.0f*h, 5.0f*l });
		}

		Laser::~Laser() {
			std::cout << "Deletando laser: " << getId() << std::endl;
		}

		const sf::FloatRect Laser::getCorpo() {
			return pSprite->getGlobalBounds();
		}


		void Laser::executar() {
			cicloOnOff();
			forcar();
			mover();
		}

		void Laser::salvar() {
		}

		void Laser::obstaculizar(Jogador* p) {
			if (ativo) *p -= 2;
		}

		void Laser::cicloOnOff() {
			if (ativo) {
				tempoAtivo--;
				if (tempoAtivo <= 0) {
					ativo = false;
					pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 20 }));
					tempoAtivo = -120;
				}
			}
			else {
				tempoAtivo++;
				if (tempoAtivo >= 0) {
					ativo = true;
					pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
					tempoAtivo = 60;
				}
			}
		}
	}
}