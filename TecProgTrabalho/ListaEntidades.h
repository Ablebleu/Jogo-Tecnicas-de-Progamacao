#ifndef _LISTAENTIDADES_H
#define _LISTAENTIDADES_H


class ListaEntidades : public Conhecer {
public:
	ListaEntidades();
	~ListaEntidades();
	void incluir(*Entidade pE);
	void percorrer();
	void ...();
private:
	Lista<Entidade> LEs;
	int ...;
};

#endif  
