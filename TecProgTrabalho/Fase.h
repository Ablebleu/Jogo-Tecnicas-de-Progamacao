#ifndef _FASE_H
#define _FASE_H

#include "Ente.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisões.h"

class Fase : public Ente {
protected:
	ListaEntidades lista_ents;
	list<sf::Texture*> ltext;

	static Gerenciador::Gerenciador_Colisoes* GC;

	void criarInimFaceis();
	void criarPlataformas();
	virtual void criar() = 0;
	virtual void criarInimigos() = 0;
	virtual void criarObstaculo() = 0;
	virtual void criarCenario() = 0;
public:
	//int ...;
	Fase();
	virtual ~Fase();
	//void ...();
	virtual void executar();
	void incluirJogador(Jogador* pE);
	void desenhar();
	void removerEntidade(int id);
	static void setGC(Gerenciador::Gerenciador_Colisoes *pG);
};
#endif  