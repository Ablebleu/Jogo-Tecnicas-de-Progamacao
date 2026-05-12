#ifndef _JOGO_H
#define _JOGO_H

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Jogador.h"

//Retirar depois
#include "Fase Primeira.h"

class Jogo {
private:

	int fps;
	Jogador *pJog1;
	Jogador* pJog2;
	Fase_Primeira* fase1;
	Fase* faseAtual;
	Gerenciadores::Gerenciador_Grafico* GG;
	Gerenciadores::Gerenciador_Eventos* GE;
	Gerenciadores::Gerenciador_Colisoes*GC;

public:
	//int ...;
	Jogo();
	~Jogo();
	void executar();
	//void ...();
};

#endif  
