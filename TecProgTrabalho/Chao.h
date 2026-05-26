#ifndef _CHAO_H
#define _CHAO_H

#include "Entidade.h"
#include "Gerenciador_Grafico.h"

class Chao {
private:
	sf::Sprite Sprite;
public:
	Chao();
	~Chao();
	const sf::FloatRect getCorpo();
	void desenhar();
	void obstaculizar(Entidade* p);
};
#endif