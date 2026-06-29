#include <fstream>
#include "Gerenciador_Estados.h"
#include "Menu_Inicial.h"
#include "json.hpp"
using Menus::Menu_Inicial;


Menu_Inicial::Menu_Inicial() : Menu(), continuar(false) {

	std::cout << "Carregando fase do save.json" << std::endl;
	std::ifstream file("save.json");
	nlohmann::json data;
	if (file.is_open()) {
		try {
			file >> data;
		}
		catch (const std::exception& e) {
			std::cerr << "Erro ao parsear JSON: " << e.what() << std::endl;
			data = nlohmann::json();
		}
		file.close();
	}

	std::string tipoFase = data[0]["tipo"];
	if (tipoFase == "Fase_Primeira" || tipoFase == "Fase_Segunda") continuar = true;
	std::cout << tipoFase << std::endl;
	data = nlohmann::json();

	criarBotoes();
	seletor = lbotoes.begin();

	/*Sprite modificado pelos autores, sprite original disponibilizado gratuitamente retirado de: https://ansimuz.itch.io/space-background */
	/*Sprite dos inimigos, jogador e projéteis citados em seus respectivos arquivos.*/
	pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Background-fase-1/AventuraAlienada.png"));
	pSprite->setScale(sf::Vector2f(5.f, 5.f));
}

Menu_Inicial::~Menu_Inicial() {

}

void Menu_Inicial::criarBotoes() {
	adicionaBotao("Nova Fase 1", 1);
	adicionaBotao("Nova Fase 2", 2);
	if(continuar) adicionaBotao("Continuar", 3);
	adicionaBotao("Ranking", 4);
}
