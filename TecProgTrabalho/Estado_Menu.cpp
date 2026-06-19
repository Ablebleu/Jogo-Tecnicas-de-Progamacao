#include <iostream>
#include "Gerenciador_Estados.h"
#include "Menu_Intermediario.h"
#include "Menu_Pontos.h"
#include "Estado_Menu.h"
#include "Estado_Fase.h"

namespace Estados {
	Estado_Menu::Estado_Menu(Menus::Menu* pM) : Estado(), pMenu(pM) {
	}
	Estado_Menu::~Estado_Menu() {
		std::cout << "Deletando Menu" << std::endl;
		if (pMenu) delete pMenu;
		pMenu = NULL;
	}

	void Estado_Menu::executar() {
		if (pMenu) {
			int S = pMenu->getSelecionado();
			if (S < 0) pGEs->removerEstado(-S);
			else if (S > 0 && S < 3) {
				pMenu->setAtivo(false);
				new Estados::Estado_Menu(new Menus::Menu_Intermediario(S));
				pMenu->setAtivo(true);
				if (pMenu) pMenu->zeraSelecionado();
			}
			else if (S == 3) new Estados::Estado_Fase(3);
			else if (S == 4) new Estados::Estado_Menu(new Menus::Menu_Pontos());
			else if (S > 10 && S < 13) {
				Menus::Menu_Intermediario* mi = static_cast<Menus::Menu_Intermediario*>(pMenu);
				if (mi->estaPronto())
				{
					pMenu->setAtivo(false);
					S -= 10;
					new Estados::Estado_Fase(S, 1, { mi->getNome(1), "" });
					pMenu->setAtivo(true);
					if (pMenu) pMenu->zeraSelecionado();
				}
			}
			else if (S > 20 && S < 23) {
				Menus::Menu_Intermediario* mi = static_cast<Menus::Menu_Intermediario*>(pMenu);
				if(mi->estaPronto())
				{
					pMenu->setAtivo(false);
					S -= 20;
					new Estados::Estado_Fase(S, 2, { mi->getNome(1), mi->getNome(2) });
					pMenu->setAtivo(true);
					if (pMenu) pMenu->zeraSelecionado();
				}
			}
			S = 0;
		}
		else std::cerr << "Menu nulo" << std::endl;
	}
	void Estado_Menu::desenhar() {
		if (pGG) {
			pGG->atualizarView(sf::Vector2f(pGG->getTamJanela().x * 0.5f, pGG->getTamJanela().y * 0.5f));
		}
		if (pMenu) pMenu->desenhar();
		else std::cerr << "Menu nulo" << std::endl;
	}
}
