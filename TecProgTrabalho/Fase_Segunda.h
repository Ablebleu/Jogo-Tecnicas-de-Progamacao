#ifndef _FASE_SEGUNDA_H
#define _FASE_SEGUNDA_H

#include "Fase.h"

namespace Fases
{
	class Fase_Segunda : public Fase {
	private:
		const int maxChefoes;
		const int maxLasers;
	protected:
		void criarChefoes();
		void criarObstMedios();
		void criarProjeteis();
		void criarInimgos();
		void criarObstaculo();
	public:
		void executar();
	};
}

#endif  //_FASE SEGUNDA_H
