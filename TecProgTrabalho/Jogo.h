#ifndef _JOGO_H
#define _JOGO_H

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"
#include "Jogador.h"
#include "Fase.h"
#include "json.hpp"

class Jogo {
private:
	
	Entidades::Personagens::Jogador *pJog1;
	Entidades::Personagens::Jogador *pJog2;
	Fases::Fase* fase; 
	static Gerenciador::Gerenciador_Grafico* GG;
	static Gerenciador::Gerenciador_Evento* GE;
	static Gerenciador::Gerenciador_Colisoes*GC;
	Gerenciador::Gerenciador_Estados* GEs;

public:

	Jogo();
	~Jogo();
	void executar();
	void deleteJogadores();
	void salvarJogadoresVivos();
	Entidades::Personagens::Jogador* getJogador(int i = 1, string nome = "");
	Entidades::Personagens::Jogador* getJogador(const nlohmann::json& dados);
};

#endif  
