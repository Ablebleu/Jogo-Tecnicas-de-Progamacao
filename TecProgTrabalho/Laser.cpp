#include "Laser.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos
	{
		Laser::Laser(sf::Vector2f p, float h, float l) : Obstaculo(), altura(h), largura(l) {
			std::cout << "Criando laser: " << getId() << std::endl;
			//hitbox
			corpo.setSize(sf::Vector2f(18.0f, 88.0f));
			corpo.setScale({ 5.0f,5.0f });

			//sprite
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/LaserCompleto.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
			pSprite->setPosition(p);
			pSprite->setScale({ 5.0f, 5.0f });
		}

		Laser::~Laser() {
			std::cout << "Deletando laser: " << getId() << std::endl;
		}

		const sf::FloatRect Laser::getCorpo() {
			return pSprite->getGlobalBounds();
		}


		void Laser::executar() {
			forcar();
			mover();
		}

		void Laser::salvar() {
		}

		void Laser::obstaculizar(Jogador* p) {
			
		}
	}
}