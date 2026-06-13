#include "Chefao.h"
#include "Projetil.h"
#include "Jogador.h"

namespace Entidades {
	Chefao::Chefao(sf::Vector2f p, int n, int f) : Inimigo(p, n), forca(), pProj(NULL) {
		std::cout << "Criando Chefao: " << getId() << std::endl;

		//Incluir Projetil
		pProj = pGC->getProjetilUnico();
		if (!pProj) {
			std::cout << "Erro ao receber projetil em: "<< getId() << std::endl;
			exit(1);
		}
		std::cout << "Recebendo projetil de: " << pProj->getId() << std::endl;
		pProj->relacionarChefe(this);

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

	Chefao::Chefao(const nlohmann::json& dados) : Inimigo(dados), forca(dados["forca"]), pProj(NULL){
		std::cout << "Criando Chefao: " << getId() << std::endl;

		//Incluir Projetil
		pProj = pGC->getProjetil(dados["id_projetil"]);
		if (!pProj) {
			std::cout << "Erro ao receber projetil em: " << getId() << std::endl;
			exit(1);
		}
		std::cout << "Recebendo projetil de: " << pProj->getId() << std::endl;
		pProj->relacionarChefe(this);

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

	Chefao::~Chefao() {

	}

	void Chefao::salvar() {
		Inimigo::salvarDataBuffer();
		dadosSalvos["tipo"] = "Chefao";
		dadosSalvos["forca"] = forca;
		if (pProj) dadosSalvos["id_projetil"] = pProj->getId();
	}

	void Chefao::executar() {
		forcar();
		mover();
	}

	void Chefao::danificar(Jogador* p) {

	}

	void Chefao::mover() {
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
		//std::cout << "Movendo Chefao " << getId() << " Vel: (" << vel.x << ", " << vel.y << ")" << std::endl;
		Personagem::mover();
	}

	void Chefao::setPos(sf::Vector2f p) {
		//Hitbox
		Entidade::setPos(p);

		//Sprite
		pSprite->setPosition(pos + sf::Vector2f(0.0f, 0.0f));
	}
}