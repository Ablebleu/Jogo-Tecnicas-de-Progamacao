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

void Fase::desenhar() {
	lista_ents.desenhar();
}

