#include <iostream>
#include "Menu_Fase.h"
#include "Fase_Primeira.h"
//#include "Fase_Segunda.h"
using Menus::Menu_Fase;

Menu_Fase::Menu_Fase(int n) {
	switch (n) {
	case(1):criarFase1();
	case(2):criarFase2();
	}
}
Menu_Fase::~Menu_Fase() {}

//Fazer segunda versão depois que aceita de fora
void Menu_Fase::criarFase1() {
	Fase_Primeira* nFase = new Fase_Primeira;
	if (nFase) pFase = nFase;
	else {
		std::cerr << "Criação nula de fasnão alocada" << endl;
		exit(1);
	}
}
void Menu_Fase::criarFase2() {}

void Menu_Fase::executar() {
	if (pFase) pFase->executar();
	else {
		std::cerr << "Fase nula" << std::endl;
		exit(1);
	}
}
void Menu_Fase::desenhar() {
	if (pFase) pFase->desenhar();
	else {
		std::cerr << "Fase nula" << std::endl;
		exit(1);
	}
}