#ifndef _ENTE_H
#define _ENTE_H

#include "Gerenciador_Grafico.h"

class Ente {
protected:
	int id;
	static int cont_id;
	static Gerenciador::Gerenciador_Grafico* pGG;
	sf::Sprite *pSprite;

	//. . .

public:
	Ente();
	Ente(int id);
	virtual ~Ente();
	virtual void executar() = 0;
	virtual void desenhar() = 0;
	sf::Sprite* getSprite();
	void static setGG(Gerenciador::Gerenciador_Grafico* pG);
	const int getId() const;

	//. . .

};

#endif
