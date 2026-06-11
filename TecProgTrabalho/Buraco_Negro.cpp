#include "Buraco_Negro.h"

namespace Entidades {
	Buraco_Negro::Buraco_Negro(sf::Vector2f p, int dur, int i) : Entidade(p, { 0, 0 }), duracao(dur), ativo(false), tam(7.0f) {
		std::cout << "Criando Buraco Negro: " << getId() << std::endl;

		//hitbox
		corpo.setSize(sf::Vector2f(16.0f, 16.0f));
		corpo.setScale({ 7.0f,7.0f });
		corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		if(i==1)
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Buraco_Negro.png"));
		else pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Buraco_Negro.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 16 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pSprite->setPosition(p);
		pSprite->setScale({ 7.0f, 7.0f });
	}

	Buraco_Negro::~Buraco_Negro() {

	}

	void Buraco_Negro::salvar() {

	}

	void Buraco_Negro::executar() {
		if (ativo) sumir();
		forcar();
		mover();
	}

	void Buraco_Negro::desenhar() {
		pGG->desenhar(pSprite);
		Entidade::desenhar();
	}

	void Buraco_Negro::forcar() {
		gravitar();
		levitar();
		arrastar();
		atritar();
	}

	void Buraco_Negro::setPos(sf::Vector2f p) {
		//Hitbox
		Entidade::setPos(p);
		//Sprite
		pSprite->setPosition(p);
	}

	void Buraco_Negro::danificar(Inimigo* pInim) {
		//std::cout << "Danificando inimigo" << std::endl;
		*pInim -= 1;
	}

	void Buraco_Negro::levitar() {
		vel.y -= 2.0f;
	}

	void Buraco_Negro::sumir() {
		if (duracao < 0)
		{
			tam -= 0.1f;
			duracao = 0;
		}
		else
			duracao--;

		if (tam < 0.0f)
		{
			setAtivo(false);
			tam = 0.0f;
		}
		corpo.setScale({ tam, tam });
		pSprite->setScale({ tam, tam });
	}

	void Buraco_Negro::setAtivo(bool a) {
		ativo = a;
		tam = 7.0f;
		duracao = 120;
	}

	bool Buraco_Negro::getAtivo() {
		return ativo;
	}
}