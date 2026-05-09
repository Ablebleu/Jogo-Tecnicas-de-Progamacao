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

void Fase::executar() {
	lista_ents.desenhar();
}

