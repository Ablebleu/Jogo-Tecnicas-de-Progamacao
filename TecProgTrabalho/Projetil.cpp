#include "Projetil.h"
#include "Monstro.h"
#include "Jogador.h"

namespace Entidades {
	Projetil::Projetil(sf::Vector2f p) : Entidade(), ativo(false), pMons(NULL) {
		std::cout << "Criando Projetil: " << getId() << std::endl;
		pGC->incluirProjetil(this);

		//hitbox
		corpo.setSize(sf::Vector2f(16.0f, 12.0f));
		corpo.setScale({ 5.0f,5.0f });
		corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		/*Sprite original disponibilizado gratuitamente retirado de: https://bdragon1727.itch.io/free-effect-and-bullet-16x16 */
		pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/projetil.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 12 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pSprite->setPosition(p);
		pSprite->setScale({ 5.0f, 5.0f });
	}

	Projetil::Projetil(const nlohmann::json& dados): Entidade(dados),
		ativo(dados["ativo"]), pMons(NULL) {
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
		setAtivo(ativo);
	}

	Projetil::~Projetil() {
		pGC->removerProjetil(this);
	}

	const bool Projetil::estaRelacionado() const {
		if (!pMons) return false;
		return true;
	}

	void Projetil::relacionarMonstro(Personagens::Monstro* pM) {
		pMons = pM;
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

	void Projetil::danificar(Personagens::Jogador* p) {
		if (p) {
			(*p) -= (int)pMons->getForca();
			setAtivo(false);
		}
	}

	void Projetil::setAtivo(bool a) {
		ativo = a;
		if (a) {
			corpo.setScale({ 5.0f,5.0f });
			pSprite->setScale({ 5.0f, 5.0f });
			pSprite->setPosition(pos);
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