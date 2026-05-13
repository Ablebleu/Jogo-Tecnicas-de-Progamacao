#ifndef _ENTIDADE_H
#define _ENTIDADE_H

#include "Ente.h"

class Entidade : public Ente {
protected:
	sf::Vector2f pos;
	sf::Vector2f vel;
	float tam;
	//int ...;
	//ostream buffer;
	void salvarDataBuffer();
public:
	Entidade(sf::Vector2f p = sf::Vector2f(0, 0), sf::Vector2f v = sf::Vector2f(0, 0));
	virtual  ~Entidade();
	virtual const sf::FloatRect getCorpo(); //Faz Hitbox
	virtual void executar(float dt) = 0;
	virtual void salvar() = 0;
	virtual void mover(float dt) = 0;
	const sf::Vector2f getPos() const;
	void setPos(sf::Vector2f p);
	//void ...();
};

#endif
