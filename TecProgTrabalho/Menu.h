#ifndef _MENU_H
#define _MENU_H

#include "Ente.h"
#include <list>
using std::list;

namespace Menus{
	class Menu : public Ente {
	protected:

		class Botao : public Ente {
		private:
			std::string texto;
			// ...
		public:
			Botao(std::string t = "") : texto(t) {}
			void executar() {}
		};

		list<Botao*> lbotoes;
	public:
		Menu();
		virtual ~Menu();
		virtual void desenhar() = 0;
		virtual void executar() = 0;
	};
}

#endif  
