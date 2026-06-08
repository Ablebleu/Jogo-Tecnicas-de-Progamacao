#ifndef _ENTIDADE_H
#define _ENTIDADE_H

#include "Ente.h"
#include "Gerenciador_Colisões.h"

class Entidade : public Ente {
protected:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::RectangleShape corpo;
	//Contato dos pés do sprite com o chão ou plataforma.
	bool contatoBase;
	//int ...;
	//ostream buffer;
	void salvarDataBuffer();
	static Gerenciador::Gerenciador_Colisoes* pGC;
public:
	Entidade(sf::Vector2f p = sf::Vector2f(0, 0), sf::Vector2f v = sf::Vector2f(0, 0));
	virtual  ~Entidade();
	virtual const sf::FloatRect getCorpo(); //Faz Hitbox
	virtual void executar() = 0;
	virtual void desenhar();
	virtual void salvar() = 0;
	virtual void mover() = 0;
	virtual void forcar(sf::Vector2f F);
	virtual void setPos(sf::Vector2f p);
	virtual void setVel(sf::Vector2f v);
	const sf::Vector2f getPos() const;
	const sf::Vector2f getVel() const;
	void houveContatoBase();
	static void setGC(Gerenciador::Gerenciador_Colisoes* pG);
	//void ...();
};

#endif
