#include <iostream>
#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() {

}

ListaEntidades::~ListaEntidades() {

}

void ListaEntidades::incluir(Entidade *pE) {
	if(pE) LEs.incluir(pE);
}

void ListaEntidades::desenhar() {
	Lista<Entidade*>::Elemento<Entidade*> *it = LEs.getPrimeiro();
	while(it!=NULL) {
		if(it->getInfo()) it->getInfo()->desenhar();
		it = it->getProximo();
	}
}
void ListaEntidades::mover() {
	Lista<Entidade*>::Elemento<Entidade*>* it = LEs.getPrimeiro();
	while (it != NULL) {
		if (it->getInfo()) it->getInfo()->executar();
		it = it->getProximo();
	}
}

void ListaEntidades::remover(int id) {
	Lista<Entidade*>::Elemento<Entidade*>* it = LEs.getPrimeiro();
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
