#include "Chefao.h"
#include "Projetil.h"

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

		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Beholder.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 32,32 }));
		pSprite->setPosition(pos);
		pSprite->setScale(sf::Vector2f(3.5f, 3.5f));
	}

	Chefao::~Chefao() {

	}

	void Chefao::salvar() {

	}

	void Chefao::executar() {
		forcar();
		mover();
	}

	void Chefao::danificar(Jogador* p) {

	}

	void Chefao::mover() {
		Personagem::mover();
	}
}