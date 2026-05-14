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

}

void Menu_Inicial::criarBotoes() {
	adicionaBotao("Novo Jogo", 1);
	adicionaBotao("Continuar", 2);
}

void Menu_Inicial::selecionarAcao(int i) {
	switch (i) {
	case 1: 
		addFase(1);
		break;
	case 2: 
		break;
	default:
		break;
	}
}

void Menu_Inicial::addFase(int i) {
	Estado_Fase* eFase = new Estado_Fase(i);
	Estado::getGE()->incluirEstado(eFase);
}