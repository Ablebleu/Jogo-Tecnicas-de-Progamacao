#include "Projetil.h"
#include "Chefao.h"
#include "Jogador.h"

namespace Entidades {
	Projetil::Projetil(sf::Vector2f p) : Entidade(), ativo(false), pChef(NULL) {
		std::cout << "Criando Projetil: " << getId() << std::endl;
		pGC->incluirProjetil(this);

		//hitbox
		corpo.setSize(sf::Vector2f(16.0f, 12.0f));
		corpo.setScale({ 5.0f,5.0f });
		corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/projetil.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 12 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pSprite->setPosition(p);
		pSprite->setScale({ 5.0f, 5.0f });
	}

	Projetil::Projetil(const nlohmann::json& dados): Entidade(dados),
		ativo(dados["ativo"]), pChef(NULL) {
		std::cout << "Recriando Projetil: " << getId() << std::endl;
		pGC->incluirProjetil(this);

		corpo.setSize(sf::Vector2f(16.0f, 12.0f));
		corpo.setScale({ 5.0f,5.0f });
		corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });

		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/projetil.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 12 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pSprite->setPosition(pos);
		pSprite->setScale({ 5.0f, 5.0f });
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
		vel.y -= 1.98f;
	}

	void Projetil::salvar() {
		Entidade::salvarDataBuffer();
		dadosSalvos["tipo"] = "Projetil";
		dadosSalvos["ativo"] = ativo;
	}

	void Projetil::mover() {
		Entidade::mover();
	}

	void Projetil::danificar(Jogador* p) {
		if (p) {
			(*p) -= (int)pChef->getForca();
			setAtivo(false);
		}
	}

	void Projetil::setAtivo(bool a) {
		ativo = a;
		if (a) {
			corpo.setScale({ 5.0f,5.0f });
			pSprite->setScale({ 5.0f, 5.0f });
		}
		else {
			corpo.setScale({ 0.0f,0.0f });
			pSprite->setScale({ 0.0f, 0.0f });
		}
	}

	bool Projetil::getAtivo() const {
		return ativo;
	}
}