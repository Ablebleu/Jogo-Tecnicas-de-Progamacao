#ifndef _MENU_INICIAL_H
#define _MENU_INICIAL_H

#include "Menu.h"

namespace Menus {
	class Menu_Inicial : public Menu {
	private:
		bool continuar;
	public:
		Menu_Inicial();
		~Menu_Inicial();

		void criarBotoes();
	};
}
#endif 