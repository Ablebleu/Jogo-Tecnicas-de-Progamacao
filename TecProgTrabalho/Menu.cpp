#include "Menu.h"
using namespace Menus;

Menu::Menu(): lbotoes() {
	lbotoes.clear();
}

Menu::~Menu() {
	list<Botao*>::const_iterator it;
	for (it = lbotoes.begin(); it != lbotoes.end(); it++) {
		if (*it) delete* it;
		it++;
	}
	lbotoes.clear();
}