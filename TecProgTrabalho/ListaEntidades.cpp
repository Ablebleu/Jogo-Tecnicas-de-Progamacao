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
	//std::cout << "d";
	//std::cout << "e"
	while(it!=NULL) {
		if(it->getInfo()) it->getInfo()->desenhar();
		it = it->getProximo();
		//std::cout << "c";
	}
}

/*void ListaEntidades::percorrer() {

}*/

/*void ListaEntidades::...() {

}*/
