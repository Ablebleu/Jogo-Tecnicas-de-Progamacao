#ifndef _ALIEN_H
#define _ALIEN_H

#include "Inimigo.h"

class Alien : public Inimigo {
private:
	float tamanho;
public:
	Alien(sf::Vector2f p, int n = 0, float raio = 1.f);
	~Alien();
	void salvar();
	void executar();
	void desenhar();
	void danificar(Jogador* p);
	void mover();
	void setPos(sf::Vector2f p);
};

#endif 