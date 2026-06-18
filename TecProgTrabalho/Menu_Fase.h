#ifndef _MENU_FASE_H
#define _MENU_FASE_H
#include "Menu.h"

namespace Menus {
	class Menu_Fase : public Menu {
	public:
		Menu_Fase();
		~Menu_Fase();

		void executar();
		void desenhar();

		void criarBotoes();
	};
}
#endif 