#include <iostream>
#include "Menu_Fase.h"
#include "Fase.h"

namespace Menus 
{
	Menu_Fase::Menu_Fase(bool fa) : Menu(), faseAcabou(fa) {
		criarBotoes();
		seletor = lbotoes.begin();
		if(fa)
		{
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Background-fase-1/telaVitoria.png"));
			pSprite->setScale(sf::Vector2f(5.f, 5.f));
		}
	}

	Menu_Fase::~Menu_Fase() {}

	void Menu_Fase::executar() {
		Menu::executar();
	}

	void Menu_Fase::desenhar() {
		Menu::desenhar();
	}

	void Menu_Fase::setFaseAcabou(bool fa) {
		faseAcabou = fa;
	}

	void Menu_Fase::criarBotoes() {
		if(!faseAcabou)
			adicionaBotao("Voltar a jogar", -1);
		adicionaBotao("Voltar ao Menu", -10);
	}
}