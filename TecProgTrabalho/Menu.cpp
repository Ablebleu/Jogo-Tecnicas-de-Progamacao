#include <iostream>
#include "Menu.h"

namespace Menus {
	static sf::Font Fonte_Menu;

	Menu::Menu() : Ente(), lbotoes(), seletor(lbotoes.begin()) {
		std::cout << "Criando menu: " << getId() << std::endl;
		lbotoes.clear();
		seletor = lbotoes.begin();
	}

	Menu::~Menu() {
		std::cout << "Deletando menu " << getId() << std::endl;
		list<Botao*>::const_iterator it;
		for (it = lbotoes.begin(); it != lbotoes.end(); it++) {
			if (*it) delete* it;
		}
		lbotoes.clear();
	}

	Menu::Botao::Botao(std::string t, const sf::Font *fonte, int i) : texto(t), numBotao(i), text(*fonte), bg() {
		text.setString(texto);
		text.setCharacterSize(36);
		text.setFillColor(sf::Color::White);
		bg.setSize(sf::Vector2f(200.f, 48.f));
		bg.setFillColor(sf::Color::Transparent);
		bg.setOutlineThickness(0.f);
	}

	void Menu::Botao::setPosition(sf::Vector2f pos) {
		text.setPosition(sf::Vector2f(pos.x + 10.f, pos.y));

		sf::FloatRect limites = text.getLocalBounds();
		bg.setSize(sf::Vector2f(limites.size.x  + 20.f, limites.size.y + 12.f));
		bg.setPosition(pos);
	}

	void Menu::Botao::setSelected(bool s) {
		if (s) {
			bg.setFillColor(sf::Color(40, 40, 120, 200));
			text.setFillColor(sf::Color::Yellow);
		}
		else {
			bg.setFillColor(sf::Color::Transparent);
			text.setFillColor(sf::Color::White);
		}
	}

	void Menu::executar() {
		if (!lbotoes.empty()) {
			//Navegaação simples para depois mudar no gerenciador de eventos
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				if (seletor == lbotoes.end()) seletor = lbotoes.begin();
				++seletor;
				if (seletor == lbotoes.end()) seletor = lbotoes.begin();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				if (seletor == lbotoes.begin()) {
					seletor = lbotoes.end();
					--seletor;
				}
				else {
					--seletor;
				}
			}
			/*if (seletor != lbotoes.end())
				std::cout << "Selecionando " << (*seletor)->getNum() << std::endl;*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
				if (seletor != lbotoes.end())
					selecionarAcao((*seletor)->getNum());
			}
		}
	}

	void Menu::desenhar() {
		if (lbotoes.empty()) {
			std::cerr << "Erro: Nenhum botão" << std::endl;
			exit(1);
		}
		if (pSprite) pGG->desenhar(pSprite);
		for (std::list<Menus::Menu::Botao*>::iterator it = lbotoes.begin(); it != lbotoes.end(); it++) {
			(*it)->setSelected(false);
		}
		if (seletor != lbotoes.end()) (*seletor)->setSelected(true);

		sf::Vector2f posInicial = sf::Vector2f(1000.f, 200.f);
		float deltaY = 64.f;
		int i = 0;
		for (list<Menus::Menu::Botao*>::iterator it = lbotoes.begin(); it != lbotoes.end(); it++, i++) {
			sf::Vector2f pos = sf::Vector2f(posInicial.x, posInicial.y + i*deltaY);
			(*it)->setPosition(pos);
			pGG->desenhar(&(*it)->getBg());
			pGG->desenhar(&(*it)->getText());
		}
	}

	void Menu::adicionaBotao(std::string t, int i) {
		Botao* b = NULL;
		b = new Botao(t, pGG->getFonte(), i);
		if (b) lbotoes.push_back(b);
		else std::cerr << "Erro ao criar botao" << std::endl;
	}
}