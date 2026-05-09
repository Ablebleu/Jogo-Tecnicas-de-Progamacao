#ifndef _JOGO_H
#define _JOGO_H

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Jogador.h"

class Jogo {
private:
	Jogador pJog1;
	Gerenciadores::Gerenciador_Grafico* GG;
	Gerenciadores::Gerenciador_Eventos* GE;
public:
	//int ...;
	Jogo();
	~Jogo();
	void executar();
	//void ...();
};

#endif  
