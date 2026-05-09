#include "Fase Primeira.h"
#include "Cenario.h"
/*void Fase Primeira::...() {

}*/
Fase_Primeira::Fase_Primeira(): Fase() {
	criarCenario();
	//criarInimMedios();
	//criarObstMedios();
	//criarInimgos();
	//criarObstaculo();
}

Fase_Primeira::~Fase_Primeira() {

}

void Fase_Primeira::executar() {
	Fase::executar();
}

void Fase_Primeira::criarInimMedios() {

}

void Fase_Primeira::criarObstMedios() {

}

void Fase_Primeira::criarInimgos() {

}

void Fase_Primeira::criarObstaculo() {

}

void Fase_Primeira::criarCenario() {
	Cenario* pBackground = new Cenario("assets/sprites/Background-fase-1/blue-with-stars.png", 800, 450);
	if (pBackground)lista_ents.incluir(static_cast<Entidade*>(pBackground));
	std::cout << "y";
}