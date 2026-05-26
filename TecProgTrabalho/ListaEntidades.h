#ifndef _LISTAENTIDADES_H
#define _LISTAENTIDADES_H

#include "Lista.h"
#include "Entidade.h"
#include "Chao.h"

class ListaEntidades {
private:
	Lista<Entidade*> LEs;
	//int ...;
public:
	ListaEntidades();
	~ListaEntidades();
	void incluir(Entidade *pE);
	void desenhar();
	void mover();
	void remover(int id);
	void verificarChao(Chao c);
	//void percorrer();
	//void ...();
};

#endif  
