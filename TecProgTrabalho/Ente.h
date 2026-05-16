#ifndef _ENTE_H
#define _ENTE_H

#include "Gerenciador_Grafico.h"

class Ente {
protected:
	int id;
	static int cont_id;
	static Gerenciador::Gerenciador_Grafico* pGG;
	sf::Sprite *pSprite;
	sf::Texture textura;

	//. . .

public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	sf::Sprite* getSprite();
	void static setGG(Gerenciador::Gerenciador_Grafico* pG);
	const int getId() const;

	//. . .

};

#endif
