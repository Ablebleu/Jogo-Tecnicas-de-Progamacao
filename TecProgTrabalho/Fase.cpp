#include "Fase.h"
#include "Jogador.h"

Fase::Fase(Gerenciadores::Gerenciador_Colisoes* pG): Ente(), GC(NULL), ltext() {
	incluirGerenciador(pG);
	ltext.clear();
}

Fase::~Fase() {
	list<sf::Texture*>::iterator it;
	for (it = ltext.begin(); it != ltext.end(); ++it) {
		if (*it) { 
			delete *it; 
			*it = NULL; 
		}
	}
	ltext.clear();
}

/*void Fase::...() {

}*/

void Fase::criarInimFaceis() {

}

void Fase::criarPlataformas() {

}

void Fase::criarCenario() {

}

void Fase::executar() {
	lista_ents.mover();
	if(GC) GC->executar();
	else cerr << "Nenhuma GC para ser executada" << endl;
}

void Fase::incluirJogador(Jogador* pE) {
	if (pE) lista_ents.incluir(static_cast<Entidade*>(pE));
}

void Fase::desenhar() {
	lista_ents.desenhar();
}

void Fase::removerEntidade(int id) {
	lista_ents.remover(id);
}

void Fase::incluirGerenciador(Gerenciadores::Gerenciador_Colisoes *pG) {
	if(pG) GC = pG;
	else cerr << "GC não incluido na fase." << endl;
}

