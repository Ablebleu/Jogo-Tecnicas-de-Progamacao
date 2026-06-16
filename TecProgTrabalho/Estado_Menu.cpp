#include <iostream>
#include "Gerenciador_Estados.h"
#include "Estado_Menu.h"
#include "Estado_Fase.h"

namespace Estados {
	Estado_Menu::Estado_Menu(Menus::Menu* pM) : Estado(), pMenu(pM) {
	}
	Estado_Menu::~Estado_Menu() {
		std::cout << "Deletando Menu" << std::endl;
		if (pMenu) delete pMenu;
	}

	void Estado_Menu::executar() {
		if (pMenu) {
			pMenu->executar();
			int S = pMenu->getSelecionado();
			if (S > 0 && S < 4) new Estados::Estado_Fase(S);
		}
		else std::cerr << "Menu nulo" << std::endl;
	}
	void Estado_Menu::desenhar() {
		if (pMenu) pMenu->desenhar();
		else std::cerr << "Menu nulo" << std::endl;
	}
}
