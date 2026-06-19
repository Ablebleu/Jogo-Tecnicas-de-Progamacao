#ifndef _FASE_H
#define _FASE_H

#include <fstream>
#include "Ente.h"
#include "Chao.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"
#include "Alien.h"

class Jogo;

namespace Fases
{
	class Fase : public Ente {
	protected: 
		static Jogo* pJogo;
		int faseAcabou; //0 = não acabou, _1 = acabou a fase 1, _2 = acabou a fase 2, 1_ = 1 jogador, 2_ = 2 jogadores.
		bool pausa;

		const int maxAliens;
		const int maxPlat;

		Lista::ListaEntidades lista_ents;
		Chao chao;

		Entidades::Jogador* pJog1;
		Entidades::Jogador* pJog2;

		static Gerenciador::Gerenciador_Colisoes* pGC;

		void moverCamera();

		void criarAliens();
		void criarPlataformas();
		virtual void criarInimigos() = 0;
		virtual void criarObstaculo() = 0;
		virtual void criarCenario() = 0;
	public:
		Fase(int nJog = 1, vector<string> nomes = { "", "" });
		Fase(const nlohmann::json& dados);
		virtual ~Fase();
		virtual void executar();
		void incluirJogador(Entidades::Jogador* pE);
		void desenhar();
		void removerEntidade(int id);
		virtual void salvar() = 0;
		static void setJogo(Jogo* pJ);
		static void setGC(Gerenciador::Gerenciador_Colisoes* pG);
		const int getAcabou() const;
		const bool getPause() const;
	};
}
#endif  