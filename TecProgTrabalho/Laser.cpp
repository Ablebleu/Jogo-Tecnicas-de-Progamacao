#include "Laser.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos
	{
		Laser::Laser(sf::Vector2f p, float h, float l, int t) : Obstaculo(), altura(h), largura(l), tempoAtivo(t){
			std::cout << "Criando laser: " << getId() << std::endl;
			danoso = true;
			//hitbox
			corpo.setSize(sf::Vector2f(18.0f, 88.0f));
			corpo.setScale({ 5.0f*h, 5.0f*l });

			//sprite
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/LaserCompleto.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
			pSprite->setPosition(p);
			pSprite->setScale({ 5.0f*h, 5.0f*l });
		}

		Laser::Laser(const nlohmann::json& dados) : Obstaculo(dados),
			altura(dados["altura"]), largura(dados["largura"]), tempoAtivo(dados["tempoAtivo"]) {
			std::cout << "Criando laser: " << getId() << std::endl;

			corpo.setSize(sf::Vector2f(18.0f, 88.0f));
			corpo.setScale({ 5.0f*altura, 5.0f*largura });

			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/LaserCompleto.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
			pSprite->setPosition(pos);
			pSprite->setScale({ 5.0f*altura, 5.0f*largura });
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
			pSprite->setPosition(pos);
		}

		void Laser::salvar() {
			Obstaculo::salvarDataBuffer();
			dadosSalvos["tipo"] = "Laser";
			dadosSalvos["altura"] = altura;
			dadosSalvos["largura"] = largura;
			dadosSalvos["tempoAtivo"] = tempoAtivo;
			dadosSalvos["danoso"] = danoso;
		}

		void Laser::obstaculizar(Jogador* p) {
			if (danoso) *p -= 2;
		}

		void Laser::cicloOnOff() {
			if (danoso) {
				tempoAtivo--;
				if (tempoAtivo <= 0) {
					danoso = false;
					pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 20 }));
					tempoAtivo = -120;
				}
			}
			else {
				tempoAtivo++;
				if (tempoAtivo >= 0) {
					danoso = true;
					pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
					tempoAtivo = 60;
				}
			}
		}
	}
}