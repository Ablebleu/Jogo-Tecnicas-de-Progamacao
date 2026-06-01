#ifndef _CHAO_H
#define _CHAO_H

#include "Ente.h"
#include "Entidade.h"
#include "Gerenciador_Grafico.h"

class Chao : public Ente {
private:
	float posX;
public:
	Chao(float x = 0);
	~Chao();
	void executar();
	const sf::FloatRect getCorpo();
	void setPos(float x);
	void desenhar();
	void obstaculizar(Entidade* p);
};
#endif