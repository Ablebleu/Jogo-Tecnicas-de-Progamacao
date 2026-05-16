#ifndef _ENTIDADE_H
#define _ENTIDADE_H

#include "Ente.h"

class Entidade : public Ente {
protected:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::FloatRect corpo;
	//int ...;
	//ostream buffer;
	void salvarDataBuffer();
public:
	Entidade(sf::Vector2f p = sf::Vector2f(0, 0), sf::Vector2f v = sf::Vector2f(0, 0));
	virtual  ~Entidade();
	virtual const sf::FloatRect getCorpo(); //Faz Hitbox
	virtual void executar() = 0;
	virtual void desenhar();
	virtual void salvar() = 0;
	virtual void mover() = 0;
	const sf::Vector2f getPos() const;
	void setPos(sf::Vector2f p);
	//void ...();
};

#endif
