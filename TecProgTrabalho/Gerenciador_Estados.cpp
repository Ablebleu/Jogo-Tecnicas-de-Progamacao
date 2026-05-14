#include <iostream>
#include "Gerenciador_Estados.h"
#include "Estado_Menu.h"
#include "Menu_Inicial.h"
#include "Gerenciador_Estados.h"
using Gerenciadores::Gerenciador_Estados;

Gerenciador_Estados::Gerenciador_Estados() : pilhaEstados() {
	while (!pilhaEstados.empty()) {
		pilhaEstados.pop();
	}
	Estado::setGE(this);
	criarMenu();
}

Gerenciador_Estados::~Gerenciador_Estados() {
	while (!pilhaEstados.empty()) {
		if (pilhaEstados.top()) delete pilhaEstados.top();
		pilhaEstados.pop();
	}
}

void Gerenciador_Estados::incluirEstado(Estado* pE) {
	if (pE) pilhaEstados.push(pE);
	else std::cout << "Estado Nulo" << std::endl;
}

void Gerenciador_Estados::removerEstado(int qtd) {
	for (int i = 0; i < qtd; i++) {
		if (!pilhaEstados.empty()) {
			removerEstado();
		}
		else break;
	}
}
void Gerenciador_Estados::removerEstado() {
	if (pilhaEstados.top()) 
		delete pilhaEstados.top();
	pilhaEstados.pop();
}

void Gerenciador_Estados::criarMenu() {
	Menus::Menu_Inicial* pMenu = new Menus::Menu_Inicial;
	if (!pMenu){
		std::cout << "Erro ao criar pMenu" << std::endl;
		exit(1);
	}
	Estado_Menu* eMenu = new Estado_Menu(pMenu);
	if (!pMenu) {
		std::cout << "Erro ao criar eMenu" << std::endl;
		exit(1);
	}
	incluirEstado(static_cast<Estado *>(eMenu));
}

void Gerenciador_Estados::executar() {
	if (!pilhaEstados.empty())
		pilhaEstados.top()->executar();
	else {
		std::cerr << "Pilha de estados vazia" << std::endl;
		exit(1);
	}
}

void Gerenciador_Estados::desenhar() {
	if (!pilhaEstados.empty())
		pilhaEstados.top()->executar();
	else {
		std::cerr << "Pilha de estados vazia" << std::endl;
		exit(1);
	}
}