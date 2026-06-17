#include <iostream>
#include "Gerenciador_Estados.h"
#include "Estado_Menu.h"
#include "Menu_Inicial.h"
#include "Menu_Intermediario.h"
#include "Gerenciador_Estados.h"

namespace Gerenciador {
	Gerenciador_Estados::Gerenciador_Estados() : pilhaEstados() {
		std::cout << "Criando Gerenciador de Estados" << std::endl;
		while (!pilhaEstados.empty()) {
			pilhaEstados.pop();
		}
		Estados::Estado::setGEs(this);
		criarMenuInicial();
	}

	Gerenciador_Estados::~Gerenciador_Estados() {
		std::cout << "Deletando Gerenciador de Estados" << std::endl;
		while (!pilhaEstados.empty()) {
			if (pilhaEstados.top()) {
				std::cout << "Deletando: " << pilhaEstados.top()->getId() << std::endl;
				delete pilhaEstados.top();
			}
			pilhaEstados.pop();
		}
	}

	void Gerenciador_Estados::incluirEstado(Estados::Estado* pE) {
		if (pE) {
			std::cout << "Incluindo estado: " << pE->getId() << std::endl;
			pilhaEstados.push(pE);
		}
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

	void Gerenciador_Estados::criarMenuInicial() {
		Menus::Menu* pMenu = new Menus::Menu_Inicial;
		if (!pMenu) {
			std::cout << "Erro ao criar pMenu" << std::endl;
			exit(1);
		}
		Estados::Estado_Menu* eMenu = new Estados::Estado_Menu(pMenu);
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
		// CORREÇÃO: chamar desenhar() do estado no topo
		if (!pilhaEstados.empty())
			pilhaEstados.top()->desenhar();
		else {
			std::cerr << "Pilha de estados vazia" << std::endl;
			exit(1);
		}
	}
}