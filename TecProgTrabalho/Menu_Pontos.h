#ifndef _MENU_PONTOS_H
#define _MENU_PONTOS_H

#include "Menu.h"

namespace Menus {
	class Menu_Pontos : public Menu {
	private:
		std::vector <std::pair<int, std::string >> ranking;
		std::vector<sf::Text> rank;
	public:
		Menu_Pontos();
		~Menu_Pontos();

		void executar();
		void desenhar();

		void criarBotoes();
	};
}

#endif