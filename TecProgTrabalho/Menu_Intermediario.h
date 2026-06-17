#ifndef _MENU_INTERMEDIARIO_H
#define _MENU_INTERMEDIARIO_H

#include "Menu.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace Menus {
	class Menu_Intermediario : public Menu {
	private:
		std::vector<std::string> nomes;
		int falta;
		int modoJogadores;
		int cursorNome;
		int nFase;
		bool aguardandoLiberarEnter; 

		sf::Text textoTitulo;
		sf::Text textoNomeInput;

		void processarEvento(const sf::Event& evento);

	public:
		Menu_Intermediario(int n = 1);
		~Menu_Intermediario();

		void executar();
		void desenhar();
		void criarBotoes();

		const bool estaPronto() const;
		std::string getNome(int i = 1);
	};
}

#endif