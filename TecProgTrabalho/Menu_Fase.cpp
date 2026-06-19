#include <iostream>
#include "Menu_Fase.h"
#include "Fase.h"

namespace Menus 
{
	Menu_Fase::Menu_Fase() : Menu() {
		criarBotoes();
		seletor = lbotoes.begin();
	}

	Menu_Fase::~Menu_Fase() {}

	void Menu_Fase::executar() {
		Menu::executar();
	}

	void Menu_Fase::desenhar() {
		Menu::desenhar();
	}

	void Menu_Fase::criarBotoes() {
		adicionaBotao("Voltar a jogar", -1);
		adicionaBotao("Voltar ao Menu", -10);
	}
}