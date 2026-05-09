#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "Personagem.h"

class Inimigo;
class Jogador : public Personagem {
protected:
	int pontos;
	//int ...;
public:
	Jogador();
	~Jogador();
	void colidir(Inimigo* pIn);
	void executar(float dt);
	void salvar();
	void mover(float dt);
	//. . .
};

#endif 