#ifndef _FASE_H
#define _FASE_H

#include "Ente.h"
#include "Chao.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisões.h"

namespace Fases
{
	class Fase : public Ente {
	private: 
		const int maxAliens;
		const int maxPlat;
	protected:

		Lista::ListaEntidades lista_ents;
		Chao chao;

		Entidades::Jogador* pJog1;

		static Gerenciador::Gerenciador_Colisoes* pGC;

		void moverCamera();

		void criarAliens();
		void criarPlataformas();
		virtual void criarInimigos() = 0;
		virtual void criarObstaculo() = 0;
		virtual void criarCenario() = 0;
	public:
		//int ...;
		Fase();
		virtual ~Fase();
		//void ...();
		virtual void executar();
		void incluirJogador(Entidades::Jogador* pE);
		void desenhar();
		void removerEntidade(int id);
		static void setGC(Gerenciador::Gerenciador_Colisoes* pG);
	};
}
#endif  