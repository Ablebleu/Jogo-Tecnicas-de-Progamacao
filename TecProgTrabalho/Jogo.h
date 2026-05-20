#ifndef _JOGO_H
#define _JOGO_H

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"
#include "Jogador.h"

//Retirar depois
#include "Fase_Primeira.h"

class Jogo {
private:
	
	Jogador *pJog1;
	Jogador *pJog2;
	Fase_Primeira* fase1;
	Fase* faseAtual; 
	static Gerenciador::Gerenciador_Grafico* GG;
	static Gerenciador::Gerenciador_Evento* GE;
	static Gerenciador::Gerenciador_Colisoes*GC;
	Gerenciador::Gerenciador_Estados* GEs;

public:
	//int ...;
	Jogo();
	~Jogo();
	void executar();
	//void ...();
};

#endif  
