#include "Gerenciador_Grafico.h"
#include "Ente.h"

Gerenciador::Gerenciador_Grafico* Gerenciador::Gerenciador_Grafico::pGrafico = nullptr;
namespace Gerenciador {
	Gerenciador_Grafico::Gerenciador_Grafico() : janela(new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Jogo++")), 
		camera(sf::Vector2f(800, 600)), relogio() {
		if (!janela) {
			std::cerr << "Erro na criação da janela" << std::endl;
			exit(1);
		}
		janela->setFramerateLimit(60);
		limparTela();

		Ente::setGG(this);
	}

	Gerenciador_Grafico::~Gerenciador_Grafico() {
		if (janela) delete janela;
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

	float Gerenciador_Grafico::atualizarTempo() {
		return relogio.restart().asSeconds();
	}

	sf::Texture Gerenciador_Grafico::carregarTextura(const char* caminho) {
		sf::Texture textura;
		if (!textura.loadFromFile(caminho)) {
			std::cout << "textura não carregada" << caminho << std::endl;
			exit(1);
		}
		return textura;
	}
	void Gerenciador_Grafico::desenhaElemento(sf::RectangleShape corpo) {
	}

	void Gerenciador_Grafico::atualizarView(const sf::Vector2f pos) {
		//camera.atualizar(pos);
		//janela.setView(camera.getCamera());
	}
	void Gerenciador_Grafico::atualizarView(const sf::Vector2f pos, sf::Vector2f tam) {
		//view.atualizar(pos, tam);
		//janela->setView(camera.getCamera());
	}

	std::optional<sf::Event> Gerenciador_Grafico::atualizaEvento() {
		return janela->pollEvent();
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