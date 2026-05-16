#ifndef _GERENCIADOR_ESTADOS_H
#define _GERENCIADOR_ESTADOS_H

#include <stack>
using std::stack;

class Estado;
namespace Gerenciador {
	class Gerenciador_Estados {
	private:
		stack<Estado*> pilhaEstados;
	public:
		Gerenciador_Estados();
		~Gerenciador_Estados();
		void incluirEstado(Estado* pE);
		void removerEstado(int qtd);
		void removerEstado();
		void criarMenu();
		void executar();
		void desenhar();
	};

}

#endif