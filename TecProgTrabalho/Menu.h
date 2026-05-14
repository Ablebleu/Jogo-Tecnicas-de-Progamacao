#ifndef _MENU_H
#define _MENU_H

#include "Ente.h"
#include <list>
using std::list;

namespace Menus{
	class Menu : public Ente {
	protected:

		class Botao {
		private:
			std::string texto;
			int numBotao;
		public:
			Botao(std::string t = "", int i = -1) : 
				texto(t) , numBotao(i) {}
			void executar() {}
			int getNum() { return numBotao; }
		};

		list<Botao*> lbotoes;
		list<Botao*>::const_iterator seletor;
		void adicionaBotao(std::string t = "", int i = -1);

	public:
		Menu();
		virtual ~Menu();
		virtual void executar();
		virtual void desenhar() = 0;
		virtual void criarBotoes() = 0;
		virtual void selecionarAcao(int i = -1) = 0;
	};
}

#endif  
