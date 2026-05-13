#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include "Obstaculo.h"

class Plataforma : public Obstaculo {
private:
	sf::Vector2f prop; //Proporções -> substituir altura e largura
public:
	Plataforma(sf::Texture *textura);
	~Plataforma();
	void executar(float dt);
	void mover(float dt);
	virtual void salvar();
	void obstaculizar(Jogador* p);
};

#endif 