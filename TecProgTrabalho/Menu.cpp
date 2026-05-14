#include <iostream>
#include "Menu.h"
using namespace Menus;

Menu::Menu(): Ente(), lbotoes(), seletor(lbotoes.begin()) {
	lbotoes.clear();
}

Menu::~Menu() {
	list<Botao*>::const_iterator it;
	for (it = lbotoes.begin(); it != lbotoes.end(); it++) {
		if (*it) delete* it;
	}
	lbotoes.clear();
}

void Menu::executar() {
    if(!lbotoes.empty()){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            if (seletor == lbotoes.begin()) {
                seletor = lbotoes.end();
                seletor--;
            }
            else seletor--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            ++seletor;
            if (++seletor == lbotoes.end()) {
                seletor = lbotoes.begin();
            }
        }
        std::cout << "Selecionando" << (*seletor)->getNum() << std::endl;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
            selecionarAcao((*seletor)->getNum());
        }
    }
}

void Menu::adicionaBotao(std::string t, int i) { 
	Botao* b = NULL;
	b = new Botao(t, i);
	if (b) lbotoes.push_back(b);
	else std::cerr << "Erro ao criar botao" << std::endl;
}

