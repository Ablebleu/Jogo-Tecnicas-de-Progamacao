#ifndef _ENTE_H
#define _ENTE_H

#include "Gerenciador_Grafico.h"

class Ente {
protected:
	int id;
	static int cont_id;
	static Gerenciadores::Gerenciador_Grafico* pGG;
	sf::Sprite *pSprite;
	sf::Texture textura;

	//. . .

public:
	Ente();
	virtual ~Ente();
	virtual void executar(float dt) = 0;
	void desenhar();
	sf::Sprite* getSprite() const;
	void static setGG(Gerenciadores::Gerenciador_Grafico* pG);
	const int getId() const;

	//. . .

};

#endif
