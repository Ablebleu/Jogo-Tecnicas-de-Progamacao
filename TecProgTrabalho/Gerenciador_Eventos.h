#ifndef _GERENCIADOR_EVENTO_H
#define _GERENCIADOR_EVENTO_H

#include <vector>
#include "Observer.h"

namespace Gerenciador {
	class Gerenciador_Grafico;
	class Gerenciador_Evento {
	private:
		Gerenciador_Grafico* pGG;
		static Gerenciador_Evento* pEvento;
		std::vector<Observadores::Observer*> Observadores;
		bool enterLiberado;

		Gerenciador_Evento();
	public:
		void executar();
		void incluirObservador(Observadores::Observer *pObs);
		void removerObservador(Observadores::Observer* pObs);
		~Gerenciador_Evento();
		static Gerenciador_Evento* getGerenciador_Evento();
		static void deletar();
	};
}

#endif