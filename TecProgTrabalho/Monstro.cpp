#include "Monstro.h"
#include "Projetil.h"
#include "Jogador.h"

namespace Entidades {
	Monstro::Monstro(sf::Vector2f p, int n, short int f) : Inimigo(p, n), forca(f), cadencia(180), pProj(NULL) {
		std::cout << "Criando Monstro: " << getId() << std::endl;

		//Incluir Projetil
		pProj = pGC->getProjetilUnico();
		if (!pProj) {
			std::cout << "Erro ao receber projetil em: "<< getId() << std::endl;
			exit(1);
		}
		std::cout << "Recebendo projetil de: " << pProj->getId() << std::endl;
		pProj->relacionarMonstro(this);

		//hitbox
		corpo.setSize(sf::Vector2f(32.0f, 32.0f));
		corpo.setScale(sf::Vector2f(6.0f, 6.0f));
		corpo.setOrigin({ corpo.getSize().x / 2.0f , corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Beholder.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 32,32 }));
		pSprite->setPosition(pos);
		pSprite->setScale(sf::Vector2f(6.0f, 6.0f));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
	}

	Monstro::Monstro(const nlohmann::json& dados) : Inimigo(dados), forca(dados["forca"]), cadencia(180), pProj(NULL){
		std::cout << "Criando Monstro: " << getId() << std::endl;

		//Incluir Projetil
		pProj = pGC->getProjetil(dados["id_projetil"]);
		if (!pProj) {
			std::cout << "Erro ao receber projetil em: " << getId() << std::endl;
			exit(1);
		}
		std::cout << "Recebendo projetil de: " << pProj->getId() << std::endl;
		pProj->relacionarMonstro(this);

		//hitbox
		corpo.setSize(sf::Vector2f(32.0f, 32.0f));
		corpo.setScale(sf::Vector2f(6.0f, 6.0f));
		corpo.setOrigin({ corpo.getSize().x / 2.0f , corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Beholder.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 32,32 }));
		pSprite->setPosition(pos);
		pSprite->setScale(sf::Vector2f(6.0f, 6.0f));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
	}

	Monstro::~Monstro() {

	}

	void Monstro::salvar() {
		Inimigo::salvarDataBuffer();
		dadosSalvos["tipo"] = "Monstro";
		dadosSalvos["forca"] = forca;
		if (pProj) dadosSalvos["id_projetil"] = pProj->getId();
	}

	void Monstro::executar() {
		if(vivo)
		{
			forcar();
			mover();
			atirar();
		}
	}

	void Monstro::danificar(Jogador* p) {
		num_vidas--;
		if (num_vidas <= 0)
			setVivo(false);
		(*p) -= 1;
	}

	void Monstro::mover() {
		if (framesPosAprox > 0) {
			framesPosAprox--;
		}
		else {
			sf::Vector2f posJog;
			Jogador* pJog1 = pGC->getJogadores(1);
			Jogador* pJog2 = pGC->getJogadores(2);
			if (!pJog1)
				return;
			if (pJog2) {
				if (!pJog1->getVivo() || (std::abs(pJog2->getPos().x - pos.x) < std::abs(pJog1->getPos().x - pos.x) && pJog2->getVivo()))
					posJog = pJog2->getPos();
				else
					posJog = pJog1->getPos();
			}
			if (std::abs(posJog.x - pos.x) < 400) {
				if (std::abs(posJog.x - pos.x) < 10) {
					framesPosAprox = 30;
				}
				if (posJog.x < pos.x) {
					vel.x += 0.28f;
				}
				else if (posJog.x > pos.x) {
					vel.x += -0.28f;
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
		//std::cout << "Movendo Monstro " << getId() << " Vel: (" << vel.x << ", " << vel.y << ")" << std::endl;
		Personagem::mover();
	}

	void Monstro::atirar() {
		if (cadencia > 0) {
			cadencia--;
		}
		else {
			for (int i = 1; i < 3; i++) {
				Jogador* pJog = pGC->getJogadores(i);
				if (pJog && !pProj->getAtivo() && std::abs(pJog->getPos().x - pos.x) < 400.0f) {
					pProj->setPos(pos + sf::Vector2f(-30.0f, -10.0f));
					pProj->setVel({ -8.0f, 0.0f });
					pProj->setAtivo(true);
					cadencia = 180;
				}
			}
		}
	}

	void Monstro::setPos(sf::Vector2f p) {
		//Hitbox
		Entidade::setPos(p);

		//Sprite
		pSprite->setPosition(pos + sf::Vector2f(0.0f, 0.0f));
	}

	short int Monstro::getForca() const {
		return forca;
	}
}