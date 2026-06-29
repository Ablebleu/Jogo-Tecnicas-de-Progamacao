#include "Laser.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos
	{
		Laser::Laser(sf::Vector2f p, float h, int t) : Obstaculo(), altura(h), tempoAtivo(t){
			std::cout << "Criando laser: " << getId() << std::endl;
			danoso = true;
			//hitbox
			corpo.setSize(sf::Vector2f(18.0f, 88.0f));
			corpo.setScale({ 5.0f*h, 7.5f });

			//sprite
			/*Sprite modificado pelos autores, sprite original disponibilizado gratuitamente retirado de: https://bdragon1727.itch.io/platfrom-trap-and-weapon */
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/LaserCompleto.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
			pos = p;
			pSprite->setPosition(p);
			pSprite->setScale({ 5.0f*h, 7.5f});
		}

		Laser::Laser(const nlohmann::json& dados) : Obstaculo(dados),
			altura(dados["altura"]), tempoAtivo(dados["tempoAtivo"]) {
			std::cout << "Criando laser: " << getId() << std::endl;

			corpo.setSize(sf::Vector2f(18.0f, 88.0f));
			corpo.setScale({ 5.0f*altura, 7.5f });

			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/LaserCompleto.png"));
			pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 18, 88 }));
			pSprite->setPosition(pos);
			pSprite->setScale({ 5.0f*altura, 7.5f });
		}

		Laser::~Laser() {
			std::cout << "Deletando laser: " << getId() << std::endl;
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
			dadosSalvos["tempoAtivo"] = tempoAtivo;
			dadosSalvos["danoso"] = danoso;
		}

		void Laser::obstaculizar(Personagens::Jogador* p) {
			if (danoso) (*p) -= 2;
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