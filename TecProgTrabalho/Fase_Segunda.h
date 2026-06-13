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
		void criarLasers();
		void criarProjeteis();
		void criarInimigos();
		void criarObstaculo();
		void criarCenario();
		void salvar();
	public:
		Fase_Segunda();
		Fase_Segunda(const nlohmann::json& dados);
		~Fase_Segunda();
		void executar();
	};
}

#endif  //_FASE SEGUNDA_H
