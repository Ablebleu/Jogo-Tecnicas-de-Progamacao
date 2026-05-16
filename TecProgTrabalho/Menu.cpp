#include <iostream>
#include "Menu.h"

namespace Menus {
	static sf::Font s_menuFont;

	Menu::Menu() : Ente(), lbotoes(), seletor(lbotoes.begin()) {
		if (s_menuFont.getInfo().family.empty()) {
			if (!s_menuFont.loadFromFile("assets/fonts/arialCE.ttf")) {
				std::cerr << "Aviso: falha ao carregar fonte assets/arial.ttf. Texto pode não aparecer." << std::endl;
			}
		}
		lbotoes.clear();
		seletor = lbotoes.begin();
	}

	Menu::~Menu() {
		list<Botao*>::const_iterator it;
		for (it = lbotoes.begin(); it != lbotoes.end(); it++) {
			if (*it) delete* it;
		}
		lbotoes.clear();
	}

	Menu::Botao::Botao(std::string t, int i) : texto(t), numBotao(i), txt(), bg() {
		txt.setString(texto);
		txt.setFont(s_menuFont);
		txt.setCharacterSize(36);
		txt.setFillColor(sf::Color::White);
		// tamanho provisório; será ajustado quando setPosition for chamado
		bg.setSize(sf::Vector2f(200.f, 48.f));
		bg.setFillColor(sf::Color::Transparent);
		bg.setOutlineThickness(0.f);
	}

	void Menu::Botao::setPosition(const sf::Vector2f& pos) {
		// ajusta texto e fundo
		txt.setPosition(pos.x + 10.f, pos.y + 6.f);
		// bg width deve cobrir o texto
		auto bounds = txt.getLocalBounds();
		bg.setSize(sf::Vector2f(bounds.width + 20.f, bounds.height + 12.f));
		bg.setPosition(pos);
	}

	void Menu::Botao::setSelected(bool s) {
		if (s) {
			bg.setFillColor(sf::Color(40, 40, 120, 200));
			txt.setFillColor(sf::Color::Yellow);
		}
		else {
			bg.setFillColor(sf::Color::Transparent);
			txt.setFillColor(sf::Color::White);
		}
	}

	void Menu::executar() {
		if (!lbotoes.empty()) {
			// navegação simples por teclas (melhor usar eventos e debounce)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				// avança seletor (wrap)
				if (seletor == lbotoes.end()) seletor = lbotoes.begin();
				++seletor;
				if (seletor == lbotoes.end()) seletor = lbotoes.begin();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				// recua seletor (wrap)
				if (seletor == lbotoes.begin()) {
					seletor = lbotoes.end();
					--seletor;
				}
				else {
					--seletor;
				}
			}
			if (seletor != lbotoes.end())
				std::cout << "Selecionando " << (*seletor)->getNum() << std::endl;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
				if (seletor != lbotoes.end())
					selecionarAcao((*seletor)->getNum());
			}
		}
	}

	void Menu::desenhar() {
		// desenhar botões através do Gerenciador_Grafico
		if (lbotoes.empty()) return;
		// definir seleção visual
		for (auto it = lbotoes.begin(); it != lbotoes.end(); ++it) {
			(*it)->setSelected(false);
		}
		if (seletor != lbotoes.end()) (*seletor)->setSelected(true);

		// desenhar em pilha (menu centralizado)
		float startX = 600.f;
		float startY = 200.f;
		float offsetY = 64.f;
		int idx = 0;
		for (auto it = lbotoes.begin(); it != lbotoes.end(); ++it, ++idx) {
			auto pos = sf::Vector2f(startX, startY + idx * offsetY);
			(*it)->setPosition(pos);
			Ente::pGG->desenharDrawable((*it)->getBg());
			Ente::pGG->desenharDrawable((*it)->getText());
		}
	}

	void Menu::adicionaBotao(std::string t, int i) {
		Botao* b = NULL;
		b = new Botao(t, i);
		if (b) lbotoes.push_back(b);
		else std::cerr << "Erro ao criar botao" << std::endl;
	}
}