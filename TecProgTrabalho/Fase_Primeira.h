#ifndef _FASE_PRIMEIRA_H
#define _FASE_PRIMEIRA_H

#include "Jogador.h"
#include "Fase.h"
#include <list>

namespace Fases
{
	class Fase_Primeira : public Fase {
	private:
		const int maxUFOs;
		const int maxAcel;
	protected:
		void criarUFOs();
		void criarAceleradores();
		void criarInimigos();
		void criarObstaculo();
		void criarCenario();
	public:
		//void ...();
		Fase_Primeira();
		~Fase_Primeira();
		void executar();
	};
}

#endif 
