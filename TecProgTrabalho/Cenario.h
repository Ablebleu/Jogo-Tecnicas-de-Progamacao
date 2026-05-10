#ifndef _CENARIO_H
#define _CENARIO_H

#include "Entidade.h"

class Cenario : public Entidade {
private:
public:
	Cenario(const char* caminho, sf::Vector2f p = sf::Vector2f(0, 0), sf::Vector2f v = sf::Vector2f(0, 0), sf::Vector2f t = sf::Vector2f(1, 1));
	~Cenario();
	void executar(float dt);
	void salvar();
	void mover(float dt);
	//void ...();
};
#endif
