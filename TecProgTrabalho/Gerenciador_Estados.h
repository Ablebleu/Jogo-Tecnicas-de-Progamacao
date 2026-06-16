#ifndef _GERENCIADOR_ESTADOS_H
#define _GERENCIADOR_ESTADOS_H

#include <stack>
using std::stack;

namespace Estados {
	class Estado;
}
namespace Gerenciador {
	class Gerenciador_Estados {
	private:
		stack<Estados::Estado*> pilhaEstados;
	public:
		Gerenciador_Estados();
		~Gerenciador_Estados();
		void incluirEstado(Estados::Estado* pE);
		void removerEstado(int qtd);
		void removerEstado();
		void criarMenuInicial();
		void executar();
		void desenhar();
	};

}

#endif