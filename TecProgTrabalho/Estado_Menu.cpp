#include "Estado_Menu.h"
#include <iostream>

Estado_Menu::Estado_Menu() : pMenu(NULL) {}
Estado_Menu::~Estado_Menu() {}

void Estado_Menu::executar(){
	if (pMenu) pMenu->executar();
	else std::cerr << "Menu nulo" << std::endl;
}
void Estado_Menu::desenhar() {
	if (pMenu) pMenu->desenhar();
	else std::cerr << "Menu nulo" << std::endl;
}