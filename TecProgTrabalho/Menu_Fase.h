#ifndef _MENU_FASE_H
#define _MENU_FASE_H

#include "Menu.h"
#include "Gerenciador_Grafico.h"

namespace Menus {
	class Menu_Fase : public Menu {
	private:
		bool faseAcabou;
	public:
		Menu_Fase(bool fa = false);
		~Menu_Fase();

		void executar();
		void desenhar();
		void setFaseAcabou(bool fa);

		void criarBotoes();
	};
}
#endif 