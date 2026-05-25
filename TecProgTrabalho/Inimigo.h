#ifndef _INIMIGO_H
#define _INIMIGO_H

#include "Personagem.h"

class Jogador;
class Inimigo : public Personagem {
protected:
	int nivel_maldade;
	const sf::Vector2f posInicial;
public:
	Inimigo(sf::Vector2f p, int n = 0);
	~Inimigo();
	void salvarDataBuffer();
	virtual void executar() = 0;
	virtual void danificar(Jogador *p) = 0;
	virtual void salvar() = 0;
	virtual void mover() = 0;
};

#endif  
