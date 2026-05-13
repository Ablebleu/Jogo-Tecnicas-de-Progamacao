#ifndef _MENU_H
#define _MENU_H

#include "Ente.h"

namespace Menus{
	class Menu : public Ente {
	private:
		//Jogo* pJog;
	public:
		Menu();
		~Menu();
		virtual void executar() = 0;
	};
}
#endif  
