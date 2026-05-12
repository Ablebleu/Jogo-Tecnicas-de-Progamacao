#ifndef _FASE_H
#define _FASE_H

#include "Ente.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisões.h"

class Fase : public Ente {
protected:
	ListaEntidades lista_ents;
	Gerenciadores::Gerenciador_Colisoes* GC;
	void criarInimFaceis();
	void criarPlataformas();
	virtual void criarInimigos() = 0;
	virtual void criarObstaculo() = 0;
	virtual void criarCenario() = 0;
public:
	//int ...;
	Fase();
	virtual ~Fase();
	//void ...();
	virtual void executar(float dt);
	void incluirJogador(Jogador* pE);
	void desenhar();
	void removerEntidade(int id);
	void incluirGerenciador(Gerenciadores::Gerenciador_Colisoes *pG);
};
#endif  