#ifndef _MENU_INICIAL_H
#define _MENU_INICIAL_H

#include "Menu.h"

namespace Menus {
	class Menu_Inicial : public Menu {
	private:
		Menu* pMenu;
	public:
		Menu_Inicial(Menu* pM = nullptr);
		~Menu_Inicial();

		void executar();
		void desenhar();
	};
}
#endif 