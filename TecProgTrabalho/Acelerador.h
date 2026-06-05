#ifndef _ACELERADOR_H
#define _ACELERADOR_H

#include "Obstaculo.h"

class Acelerador : public Obstaculo {
private:
	int altura;
	int largura;
public:
	Acelerador(sf::Vector2f p, float h, float l);
	~Acelerador();
	const sf::FloatRect getCorpo();
	void executar();
	void mover();
	virtual void salvar();
	void obstaculizar(Jogador* p);
};

#endif 