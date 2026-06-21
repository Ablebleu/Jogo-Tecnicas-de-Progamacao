#include "Gerenciador_Grafico.h"
#include "Ente.h"

Gerenciador::Gerenciador_Grafico* Gerenciador::Gerenciador_Grafico::pGrafico = nullptr;
namespace Gerenciador {
	Gerenciador_Grafico::Gerenciador_Grafico() : janela(new sf::RenderWindow(sf::VideoMode({ 1200, 675 }), "Jogo++")),
		camera(sf::Vector2f(1200.f, 675.f)), relogio(), ltext() {
		std::cout << "Criando Gerenciador Grafico" << std::endl;
		ltext.clear();
		if (!janela) {
			std::cerr << "Erro na criação da janela" << std::endl;
			exit(1);
		}
		janela->setFramerateLimit(60);
		limparTela();
		if (!Fonte.openFromFile("assets/fonts/arialCE.ttf")) {
			std::cerr << "Erro ao carregar fonte assets/fonts/arialCE.ttf." << std::endl;
			exit(1);
		}

		Ente::setGG(this);
	}

	Gerenciador_Grafico::~Gerenciador_Grafico() {
		std::cout << "Deletando Gerenciador Grafico" << std::endl;
		if (janela) delete janela;

		std::list<sf::Texture*>::iterator it;
		for (it = ltext.begin(); it != ltext.end(); ++it) {
			if (*it) {
				delete* it;
				*it = nullptr;
			}
		}
		ltext.clear();
	}

	bool Gerenciador_Grafico::janelaAberta() const {
		return janela->isOpen();
	}

	void Gerenciador_Grafico::limparTela() {
		janela->clear(sf::Color::Black);
	}

	void Gerenciador_Grafico::fecharJanela() {
		janela->close();
	}

	void Gerenciador_Grafico::mostrarTela() {
		janela->display();
	}

	sf::Texture* Gerenciador_Grafico::carregarTextura(const char* caminho, bool repetir) {
		sf::Texture* textura = NULL;
		textura = new sf::Texture();
		if (!textura->loadFromFile(caminho)) {
			std::cout << "Textura: " << caminho << " não carregada" << std::endl;
		}
		else ltext.push_back(textura);
		if(repetir)textura->setRepeated(true);
		return textura;
	}

	void Gerenciador_Grafico::desenhar(sf::RectangleShape* corpo) {
		if (!corpo) return;
		if (janela) {
			//std::cout << "Desenhando corpo" << std::endl;
			janela->draw(*corpo);
		}
	}

	void Gerenciador_Grafico::desenhar(sf::Sprite* sprite) {
		if (!sprite) return;
		if (janela) {
			//std::cout << "Desenhando sprite" << std::endl;
			janela->draw(*sprite);
		}
	}

	void Gerenciador_Grafico::desenhar(sf::Drawable* drawable) {
		if (!drawable) return;
		if (janela) {
			//std::cout << "Desenhando drawable" << std::endl;
			janela->draw(*drawable);
		}
	}

	void Gerenciador_Grafico::resetarView() {
		std::cout << "Reset";
		camera.resetar();
	}

	void Gerenciador_Grafico::atualizarView(sf::Vector2f pos) {
		camera.atualizar(pos);
		if (janela) janela->setView(camera.getCamera());
	}

	void Gerenciador_Grafico::atualizarTamanho(sf::Vector2f novoTam) {
		camera.redimensionar(novoTam);
		janela->setView(camera.getCamera());
	}

	std::optional<sf::Event> Gerenciador_Grafico::atualizaEvento() {
		return janela->pollEvent();
	}

	const sf::Vector2f Gerenciador_Grafico::getTamJanela() const {
		return camera.getTamJanela();
	}

	const sf::Vector2f Gerenciador_Grafico::getPosJanela() const {
		return camera.getCenter();
	}

	const sf::Font *Gerenciador_Grafico::getFonte() const {
		return &Fonte;
	}

	Gerenciador_Grafico* Gerenciador_Grafico::getGerenciador_Grafico() {
		if (pGrafico == nullptr) {
			pGrafico = new Gerenciador_Grafico();
		}
		return pGrafico;
	}
	void Gerenciador_Grafico::deletar() {
		if (pGrafico)
			delete pGrafico;
		pGrafico = nullptr;
	}
}