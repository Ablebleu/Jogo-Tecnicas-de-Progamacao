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
		sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(6, 5.8));
	if (pBackground)lista_ents.incluir(static_cast<Entidade*>(pBackground));
	Cenario* pPlanetaG = new Cenario("assets/sprites/Background-fase-1/prop-planet-big.png",
		sf::Vector2f(400, 610), sf::Vector2f(0.3, -0.3), sf::Vector2f(6, 6));
	if (pPlanetaG)lista_ents.incluir(static_cast<Entidade*>(pPlanetaG));
	Cenario* pPlanetaP = new Cenario("assets/sprites/Background-fase-1/prop-planet-small.png",
		sf::Vector2f(800, 250), sf::Vector2f(-0.5, -0.2), sf::Vector2f(6, 6));
	if (pPlanetaP)lista_ents.incluir(static_cast<Entidade*>(pPlanetaP));
	Cenario* Astro1 = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
		sf::Vector2f(1200, 500), sf::Vector2f(0.10, -0.15), sf::Vector2f(6, 6));
	if (Astro1)lista_ents.incluir(static_cast<Entidade*>(Astro1));
	Cenario* Astro1b = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
		sf::Vector2f(250, 270), sf::Vector2f(-0.8, -0.13), sf::Vector2f(6, 6));
	if (Astro1b)lista_ents.incluir(static_cast<Entidade*>(Astro1b));
	Cenario* Astro2 = new Cenario("assets/sprites/Background-fase-1/asteroid-2.png",
		sf::Vector2f(400, 650), sf::Vector2f(-10, -0.1), sf::Vector2f(6, 6));
	if (Astro2)lista_ents.incluir(static_cast<Entidade*>(Astro2));
}