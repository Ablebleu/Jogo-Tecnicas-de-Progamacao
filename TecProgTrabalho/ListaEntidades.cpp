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
void ListaEntidades::mover(float dt) {
	Lista<Entidade*>::Elemento<Entidade*>* it = LEs.getPrimeiro();
	while (it != NULL) {
		if (it->getInfo()) it->getInfo()->mover(dt);
		it = it->getProximo();
	}
}

/*void ListaEntidades::percorrer() {

}*/

/*void ListaEntidades::...() {

}*/
