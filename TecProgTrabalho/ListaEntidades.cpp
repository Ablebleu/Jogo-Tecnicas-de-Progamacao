#include <iostream>
#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() {

}

ListaEntidades::~ListaEntidades() {

}

void ListaEntidades::incluir(Entidade *pE) {
	if(pE) LEs.incluir(&pE);
}

void ListaEntidades::desenhar() {
	Lista<Entidade*>::Elemento<Entidade*> *it = LEs.getPrimeiro();
	//std::cout << "d";
	if (it == NULL) return;
	//std::cout << "e";
	while(it->getInfo()!=NULL) {
		(*it->getInfo())->desenhar();
		it = it->getProximo();
		std::cout << "c";
	}
}

/*void ListaEntidades::percorrer() {

}*/

/*void ListaEntidades::...() {

}*/
