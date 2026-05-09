#ifndef _LISTAENTIDADES_H
#define _LISTAENTIDADES_H

#include "Lista.h"
#include "Entidade.h"

class ListaEntidades {
private:
	Lista<Entidade*> LEs;
	//int ...;
public:
	ListaEntidades();
	~ListaEntidades();
	void incluir(Entidade *pE);
	void desenhar();
	void mover(float dt);
	//void percorrer();
	//void ...();
};

#endif  
