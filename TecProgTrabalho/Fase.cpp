#include "Fase.h"

Fase::Fase(): Ente(), GC(NULL) {

}

Fase::~Fase() {

}

/*void Fase::...() {

}*/

void Fase::criarInimFaceis() {

}

void Fase::criarPlataformas() {

}

void Fase::criarCenario() {

}

void Fase::executar(float dt) {
	lista_ents.mover(dt);
}

void Fase::incluirEntidade(Entidade* pE) {
	if (pE) lista_ents.incluir(pE);
}

void Fase::desenhar() {
	lista_ents.desenhar();
}

void Fase::removerEntidade(int id) {
	lista_ents.remover(id);
}

