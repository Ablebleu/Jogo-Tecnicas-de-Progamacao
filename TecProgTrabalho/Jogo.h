#ifndef _JOGO_H
#define _JOGO_H

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Evento.h"
//#include "Gerenciador_Colisoes.h"
//#include "Gerenciador_Estados.h"

class Jogo {
private:

	static Gerenciador::Gerenciador_Grafico* GG;
	static Gerenciador::Gerenciador_Evento* GE;
	//static Gerenciador::Gerenciador_Estados* GEs;
	//static Gerenciador::Gerenciador_Colisoes* GC;

public:
	Jogo();
	~Jogo();
	void executar();
};

#endif  