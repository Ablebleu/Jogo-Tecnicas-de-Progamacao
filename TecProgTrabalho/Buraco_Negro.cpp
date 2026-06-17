#include "Buraco_Negro.h"
#include "Jogador.h"

namespace Entidades {
	Buraco_Negro::Buraco_Negro(sf::Vector2f p, int dur, int i) : Entidade(p, { 0, 0 }), 
		pJogador(NULL), duracao(dur), ativo(false), cor(i), tam(7.0f) {
		std::cout << "Criando Buraco Negro: " << getId() << std::endl;

		//hitbox
		corpo.setSize(sf::Vector2f(16.0f, 16.0f));
		corpo.setScale({ 7.0f,7.0f });
		corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		if(cor==1)
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Buraco_Negro.png"));
		else pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Buraco_Negro2.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 16 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pSprite->setPosition(p);
		pSprite->setScale({ 7.0f, 7.0f });
	}

	Buraco_Negro::Buraco_Negro(const nlohmann::json& dados) : Entidade(dados),
		pJogador(NULL), duracao(dados["duracao"]), ativo(dados["ativo"]), cor(dados["cor"]), tam(dados["tam"]) {
		std::cout << "Criando Buraco Negro: " << getId() << std::endl;

		corpo.setSize(sf::Vector2f(16.0f, 16.0f));
		corpo.setScale({ 7.0f,7.0f });
		corpo.setOrigin({ corpo.getSize().x / 2.0f, corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		if (cor == 1)
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Buraco_Negro.png"));
		else pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Buraco_Negro2.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 16 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pSprite->setPosition(pos);
		pSprite->setScale({ 7.0f, 7.0f });

		if (tam < 0.0f)
		{
			setAtivo(false);
			tam = 0.0f;
		}
		corpo.setScale({ tam, tam });
		pSprite->setScale({ tam, tam });
	}

	Buraco_Negro::~Buraco_Negro() {

	}

	void Buraco_Negro::salvar() {
		Entidade::salvarDataBuffer();
		dadosSalvos["tipo"] = "Buraco_Negro";
		dadosSalvos["duracao"] = duracao;
		dadosSalvos["ativo"] = ativo;
		dadosSalvos["cor"] = cor;
		dadosSalvos["tam"] = tam;
	}

	void Buraco_Negro::executar() {
		if (ativo) sumir();
		forcar();
		mover();
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

	void Buraco_Negro::setJogador(Jogador* pJog) {
		pJogador = pJog;
	}

	void Buraco_Negro::danificar(Inimigo* pInim) {
		//std::cout << "Danificando inimigo" << std::endl;
		if (pInim->getVivo())
		{
			*pInim -= 1;
			if (!pInim->getVivo())
				pJogador->addPontos(100);
		}
	
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