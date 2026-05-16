cpp Menu.h
#ifndef _MENU_H
#define _MENU_H

#include "Ente.h"
#include <list>
#include <SFML/Graphics.hpp>
using std::list;

namespace Menus {
	class Menu : public Ente {
	protected:

		class Botao {
		private:
			std::string texto;
			int numBotao;
			sf::Text txt;
			sf::RectangleShape bg;
		public:
			Botao(std::string t = "", int i = -1);
			void executar() {}
			int getNum() const { return numBotao; }
			void setPosition(sf::Vector2f pos);
			void setSelected(bool s);
			const sf::Text& getText() const { return txt; }
			const sf::RectangleShape& getBg() const { return bg; }
		};

		list<Botao*> lbotoes;
		list<Botao*>::iterator seletor;
		void adicionaBotao(std::string t = "", int i = -1);

	public:
		Menu();
		virtual ~Menu();
		virtual void executar();
		virtual void desenhar();
		virtual void criarBotoes() = 0;
		virtual void selecionarAcao(int i = -1) = 0;
	};
}
#endif