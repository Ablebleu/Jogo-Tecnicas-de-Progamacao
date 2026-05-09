#ifndef _LISTAENTIDADES_H
#define _LISTAENTIDADES_H

#include "Lista.h"
#include "Entidade.h"

class ListaEntidades {
public:
	ListaEntidades();
	~ListaEntidades();
	void incluir(Entidade *pE);
	void percorrer();
	//void ...();
private:
	Lista<Entidade> LEs;
	//int ...;
};

#endif  
