#include "Gerenciador_Grafico.h"
#include "Ente.h"

Gerenciador::Gerenciador_Grafico* Gerenciador::Gerenciador_Grafico::pGrafico = nullptr;
namespace Gerenciador {
	Gerenciador_Grafico::Gerenciador_Grafico() : janela(new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Jogo++")),
		camera(sf::Vector2f(800.f, 600.f)), relogio() {
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

	void Gerenciador_Grafico::resetarRelogio() {
		relogio.restart();
	}

	float Gerenciador_Grafico::atualizarTempo() {
		return relogio.restart().asSeconds();
	}

	sf::Texture Gerenciador_Grafico::carregarTextura(const char* caminho) {
		sf::Texture textura;
		if (!textura.loadFromFile(caminho)) {
			std::cout << "Textura: " << caminho << " não carregada" << std::endl;
		}
		return textura;
	}

	void Gerenciador_Grafico::desenhaElemento(sf::RectangleShape corpo) {
		if (janela) janela->draw(corpo);
	}

	void Gerenciador_Grafico::desenharDrawable(sf::Drawable* drawable) {
		if (!drawable) return;
		if (janela) janela->draw(*drawable);
	}

	void Gerenciador_Grafico::desenharEnte(Ente* pE) {
		if (!pE) {
			std::cerr << "Erro ao desenhar Ente: ponteiro nulo" << std::endl;
			return;
		}
		//std::cout << "a";
		sf::Sprite* s = pE->getSprite();
		if (s && janela) janela->draw(*s);
	}

	void Gerenciador_Grafico::atualizarView(sf::Vector2f pos) {
		camera.atualizar(pos);
		if (janela) janela->setView(camera.getCamera());
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