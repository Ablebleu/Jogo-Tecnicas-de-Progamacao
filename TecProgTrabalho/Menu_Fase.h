#ifndef _MENU_FASE_H
#define _MENU_FASE_H

#include "Menu.h"

class Fase;
namespace Menus {
	class Menu_Fase : public Menu {
	public:
		Menu_Fase();
		~Menu_Fase();

		//Fazer segunda versão depois que aceita de fora
		void criarFase1();
		void criarFase2();

		void executar();
		void desenhar();

		void criarBotoes();
		void selecionarAcao(int i = -1);
	};
}
#endif 
