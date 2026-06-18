#include "Gerenciador_Estados.h"
#include "Menu_Inicial.h"
using Menus::Menu_Inicial;


Menu_Inicial::Menu_Inicial(Menu* pM) : Menu(), pMenu(pM) {
	criarBotoes();
	seletor = lbotoes.begin();

	pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Background-fase-1/blue-stars.png"));
	pSprite->setScale(sf::Vector2f(5.f, 5.f));
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
	adicionaBotao("Ranking", 4);
}
