#include "Projetil.h"
#include "Chefao.h"

namespace Entidades {
	Projetil::Projetil(sf::Vector2f p) : Entidade(), ativo(false), pChef(NULL) {
		std::cout << "Criando Projetil: " << getId() << std::endl;
		pGC->incluirProjetil(this);

		//hitbox
		corpo.setSize(sf::Vector2f(16.0f, 12.0f));
		corpo.setScale({ 7.0f,7.0f });
		corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/projetil.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 12 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pSprite->setPosition(p);
		pSprite->setScale({ 7.0f, 7.0f });
	}

	Projetil::~Projetil() {

	}

	const bool Projetil::estaRelacionado() const {
		if (!pChef) return false;
		return true;
	}

	void Projetil::relacionarChefe(Chefao* pC) {
		pChef = pC;
	}

	void Projetil::executar() {
		if (ativo) {
			forcar();
			mover();
		}
	}

	void Projetil::forcar() {
		gravitar();
		levitar();
		arrastar();
		atritar();
	}

	void Projetil::levitar() {
		vel.y -= 2.0f;
	}

	void Projetil::salvar() {

	}

	void Projetil::mover() {
		Entidade::mover();
	}
}