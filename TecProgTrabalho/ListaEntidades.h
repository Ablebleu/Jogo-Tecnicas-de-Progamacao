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
		void salvarEntidades(nlohmann::json& arquivoJson);
		void incluir(Entidades::Entidade* pE);
		void desenhar();
		void percorrer();
		void remover(int id);
		void deletarEntidades();
	};
}

#endif  
