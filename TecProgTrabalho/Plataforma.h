#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include "Obstaculo.h"

class Plataforma : public Obstaculo {
private:
	//int ...;
	sf::Vector2f prop; //Proporções
public:
	Plataforma();
	~Plataforma();
	void executar();
	virtual void salvar();
	void obstaculizar(Jogador* p);
	//void ...();
};

#endif 