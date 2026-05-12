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

void Fase_Primeira::executar(float dt) {
	Fase::executar(dt);
}

void Fase_Primeira::criarInimMedios() {

}

void Fase_Primeira::criarObstMedios() {

}

void Fase_Primeira::criarInimigos() {

}

void Fase_Primeira::criarObstaculo() {

}

void Fase_Primeira::criarCenario() {
	Cenario* pBackground = new Cenario("assets/sprites/Background-fase-1/blue-with-stars.png", 
		sf::Vector2f(0, 0), sf::Vector2f(0.0f, 0.0f), 6.0f);
	if (pBackground)lista_ents.incluir(static_cast<Entidade*>(pBackground));
	Cenario* pPlanetaG = new Cenario("assets/sprites/Background-fase-1/prop-planet-big.png",
		sf::Vector2f(400, 610), sf::Vector2f(0.3f, -0.3f), 6.0f);
	if (pPlanetaG)lista_ents.incluir(static_cast<Entidade*>(pPlanetaG));
	Cenario* pPlanetaP = new Cenario("assets/sprites/Background-fase-1/prop-planet-small.png",
		sf::Vector2f(800, 250), sf::Vector2f(-0.5f, -0.2f), 6.0f);
	if (pPlanetaP)lista_ents.incluir(static_cast<Entidade*>(pPlanetaP));
	Cenario* Astro1 = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
		sf::Vector2f(1200, 500), sf::Vector2f(0.10f, -0.15f), 6.0f);
	if (Astro1)lista_ents.incluir(static_cast<Entidade*>(Astro1));
	Cenario* Astro1b = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
		sf::Vector2f(250, 270), sf::Vector2f(-0.8f, -0.13f), 6.0f);
	if (Astro1b)lista_ents.incluir(static_cast<Entidade*>(Astro1b));
	Cenario* Astro2 = new Cenario("assets/sprites/Background-fase-1/asteroid-2.png",
		sf::Vector2f(400, 650), sf::Vector2f(-10.0f, -0.1f), 6.0f);
	if (Astro2)lista_ents.incluir(static_cast<Entidade*>(Astro2));
}