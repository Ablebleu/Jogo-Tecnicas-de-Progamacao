#ifndef _LISTAENTIDADES_H
#define _LISTAENTIDADES_H

#include "Lista.h"
#include "Entidade.h"
#include "Personagem.h"

namespace Lista
{
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade*> LEs;
		//int ...;
	public:
		ListaEntidades();
		~ListaEntidades();
		void incluir(Entidades::Entidade* pE);
		void desenhar();
		void retiraEntidadesMortas();
		void percorrer();
		void remover(int id);
		void deletarEntidades();
	};
}

#endif  
