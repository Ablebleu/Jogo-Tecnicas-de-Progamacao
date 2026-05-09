#ifndef _ENTE_H
#define _ENTE_H

#include "Gerenciador_Grafico.h"

class Ente {
protected:
	int id;
	static int cont_id;
	static Gerenciadores::Gerenciador_Grafico* pGG;
	//*Figura pFig;

	//. . .

public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	void desenhar();
	void static setGG(Gerenciadores::Gerenciador_Grafico* pG);

	//. . .

};

#endif
