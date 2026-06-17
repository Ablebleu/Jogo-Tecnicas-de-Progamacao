#include "Acelerador.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos
	{
		Acelerador::Acelerador(sf::Vector2f p, float acel) : Obstaculo(), aceleracao(acel) {
			std::cout << "Criando acelerador: " << getId() << std::endl;
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Acelerador.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16,16 }));
			pos = p;
			pSprite->setPosition(pos);
			pSprite->setScale({ 7.f, 7.f });
			//ajustando centro de rotação e posição para o centro do sprite
			sf::FloatRect bounds = pSprite->getLocalBounds();
			sf::Vector2f centro = { bounds.size.x / 2.0f, bounds.size.y / 2.0f };
			pSprite->setOrigin(centro);
			pSprite->setPosition({ p + centro });
			pSprite->setRotation(sf::degrees(270));
		}


		Acelerador::Acelerador(const nlohmann::json& dados) : Obstaculo(dados), 
			aceleracao(dados["aceleracao"]) {
			std::cout << "Criando acelerador: " << getId() << std::endl;

			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Acelerador.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16,16 }));
			pSprite->setPosition(pos);
			pSprite->setScale({ 7.f, 7.f });

			sf::FloatRect bounds = pSprite->getLocalBounds();
			sf::Vector2f centro = { bounds.size.x / 2.0f, bounds.size.y / 2.0f };
			pSprite->setOrigin(centro);
			pSprite->setPosition({ pos + centro });
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
			pSprite->setPosition(pos);
		}

		void Acelerador::salvar() {
			Obstaculo::salvarDataBuffer();
			dadosSalvos["tipo"] = "Acelerador";
			dadosSalvos["aceleracao"] = aceleracao;
		}

		void Acelerador::obstaculizar(Jogador* p) {
			p->setVel(p->getVel() + sf::Vector2f(-5.f, 0.f) * aceleracao);
		}
	}
}