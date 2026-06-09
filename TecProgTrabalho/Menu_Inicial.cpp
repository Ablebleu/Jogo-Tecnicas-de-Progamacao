#include "Gerenciador_Estados.h"
#include "Menu_Inicial.h"
#include "Estado_Fase.h"
using Menus::Menu_Inicial;


Menu_Inicial::Menu_Inicial(Menu* pM) : Menu(), pMenu(pM) {
	criarBotoes();
	seletor = lbotoes.begin();
}

Menu_Inicial::~Menu_Inicial() {

}

void Menu_Inicial::executar() {
	Menu::executar();
}

void Menu_Inicial::desenhar() {
	Menu::desenhar();
}

void Menu_Inicial::criarBotoes() {
	adicionaBotao("Nova Fase 1", 1);
	adicionaBotao("Nova Fase 2", 2);
	adicionaBotao("Continuar", 3);
}

void Menu_Inicial::selecionarAcao(int i) {
	switch (i) {
	case 1: 
		addFase(1);
		break;
	case 2: 
		addFase(2);
		break;
	case 3:
		break;
	default:
		break;
	}
}

void Menu_Inicial::addFase(int i) {
	Estados::Estado_Fase* eFase = new Estados::Estado_Fase(i);
}