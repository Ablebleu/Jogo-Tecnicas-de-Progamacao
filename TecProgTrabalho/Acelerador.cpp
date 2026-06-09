#include "Acelerador.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos
	{
		Acelerador::Acelerador(sf::Vector2f p, float h, float l) : Obstaculo(), altura(h), largura(l) {
			std::cout << "Criando acelerador: " << getId() << std::endl;
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Acelerador.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16,16 }));
			pos = p;
			pSprite->setPosition(pos);
			pSprite->setScale({ h, l });
			//ajustando centro de rotação e posição para o centro do sprite
			sf::FloatRect bounds = pSprite->getLocalBounds();
			sf::Vector2f centro = { bounds.size.x / 2.0f, bounds.size.y / 2.0f };
			pSprite->setOrigin(centro);
			pSprite->setPosition({ p + centro });
			pSprite->setRotation(sf::degrees(270));
		}

		Acelerador::~Acelerador() {
			std::cout << "Deletando acelerador: " << getId() << std::endl;
		}

		const sf::FloatRect Acelerador::getCorpo() {
			return pSprite->getGlobalBounds();
		}


		void Acelerador::executar() {
			forcar();
			mover();
		}

		void Acelerador::salvar() {
		}

		void Acelerador::obstaculizar(Jogador* p) {
			static_cast<Entidade*>(p)->forcar({ -10.0f, 0.0f });
		}
	}
}