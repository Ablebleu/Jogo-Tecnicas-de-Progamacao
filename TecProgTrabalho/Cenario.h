#ifndef _CENARIO_H
#define _CENARIO_H

#include "Entidade.h"

class Cenario : public Entidade {
private:
	sf::Texture textura;
public:
	Cenario(const char* caminho, float px, float py, float vx = 0, float vy = 0);
	~Cenario();
	void executar();
	void salvar();
	void mover();
	//void ...();
};
#endif
