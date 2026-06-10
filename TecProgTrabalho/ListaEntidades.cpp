#include <iostream>
#include "ListaEntidades.h"

namespace Lista
{
	ListaEntidades::ListaEntidades() {

	}

	ListaEntidades::~ListaEntidades() {

	}

	void ListaEntidades::incluir(Entidades::Entidade* pE) {
		if (pE) LEs.incluir(pE);
	}

	void ListaEntidades::desenhar() {
		Lista<Entidades::Entidade*>::Elemento<Entidades::Entidade*>* it = LEs.getPrimeiro();
		while (it != NULL) {
			if (it->getInfo()) it->getInfo()->desenhar();
			it = it->getProximo();
		}
	}

	void ListaEntidades::retiraEntidadesMortas() {
		Lista<Entidades::Entidade*>::Elemento<Entidades::Entidade*>* it = LEs.getPrimeiro();
		while (it != NULL) {
			Entidades::Personagem* pPersonagem = dynamic_cast<Entidades::Personagem*>(it->getInfo());
			if (it->getInfo() && pPersonagem && pPersonagem->getVidas() <= 0) {
				it->incluir(nullptr);
			}
			it = it->getProximo();
		}
	}

	void ListaEntidades::mover() {
		Lista<Entidades::Entidade*>::Elemento<Entidades::Entidade*>* it = LEs.getPrimeiro();
		while (it != NULL) {
			if (it->getInfo()) it->getInfo()->executar();
			it = it->getProximo();
		}
	}

	void ListaEntidades::deletarEntidades() {
		Lista<Entidades::Entidade*>::Elemento<Entidades::Entidade*>* it = LEs.getPrimeiro();
		while (it != NULL) {
			if (it->getInfo()) delete it->getInfo();
			it->incluir(nullptr);
			it = it->getProximo();
		}
		LEs.limpar();
	}

	// Objetivamente errado pois adiciona nulo na lista. 
	// Serve para remover o jogador antes de apagar lista.
	void ListaEntidades::remover(int id) {
		Lista<Entidades::Entidade*>::Elemento<Entidades::Entidade*>* it = LEs.getPrimeiro();
		while (it != NULL) {
			if (it->getInfo() && it->getInfo()->getId() == id) {
				it->incluir(nullptr);
				return;
			}
			it = it->getProximo();
		}
	}

	/*void ListaEntidades::percorrer() {

	}*/

	/*void ListaEntidades::...() {

	}*/
}
