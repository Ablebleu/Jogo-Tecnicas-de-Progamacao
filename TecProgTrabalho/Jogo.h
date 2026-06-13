#ifndef _JOGO_H
#define _JOGO_H

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"
#include "Jogador.h"
#include "Fase.h"

class Jogo {
private:
	
	Entidades::Jogador *pJog1;
	Entidades::Jogador *pJog2;
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
	Entidades::Jogador* getJogador(int i = 1);
	Fases::Fase* getFase(int i = 1);
};

#endif  
