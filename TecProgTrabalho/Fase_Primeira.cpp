#include "Fase_Primeira.h"
#include "Plataforma.h"
/*void Fase Primeira::...() {

}*/
Fase_Primeira::Fase_Primeira(Gerenciador::Gerenciador_Colisoes* pG): Fase(pG) {
	//No futuro esse criar não vai estar aqui ou vai estar diferente para o caso de salvamento
	criar();
}

Fase_Primeira::~Fase_Primeira() {

}

void Fase_Primeira::executar() {
	Fase::executar();
}

void Fase_Primeira::criar() {
	criarCenario();
	criarObstaculo();
	//criarInimMedios();
	//criarObstMedios();
	//criarInimgos();
}

void Fase_Primeira::criarInimMedios() {

}

void Fase_Primeira::criarObstMedios() {

}

void Fase_Primeira::criarInimigos() {

}

void Fase_Primeira::criarObstaculo() {
	sf::Texture* bloco = new sf::Texture();
	if (bloco->loadFromFile("assets/sprites/tiles/1_Industrial_Tileset_1.png")) {
		Plataforma* bloxk = new Plataforma(bloco);
		if (bloxk) {
			lista_ents.incluir(static_cast<Entidade*>(bloxk));
			if (GC) GC->incluirObstaculo(bloxk);
			else cerr << "Sem GC em fase" << endl;
		}
	}
}
void Fase_Primeira::criarCenario() {
	/*Cenario* pBackground = new Cenario("assets/sprites/Background-fase-1/blue-with-stars.png",
		sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f), 6.0f);
	if (pBackground)lista_ents.incluir(static_cast<Entidade*>(pBackground));
	Cenario* pPlanetaG = new Cenario("assets/sprites/Background-fase-1/prop-planet-big.png",
		sf::Vector2f(400.0f, 610.0f), sf::Vector2f(0.3f, -0.3f), 6.0f);
	if (pPlanetaG)lista_ents.incluir(static_cast<Entidade*>(pPlanetaG));
	Cenario* pPlanetaP = new Cenario("assets/sprites/Background-fase-1/prop-planet-small.png",
		sf::Vector2f(800.0f, 250.0f), sf::Vector2f(-0.5f, -0.2f), 6.0f);
	if (pPlanetaP)lista_ents.incluir(static_cast<Entidade*>(pPlanetaP));
	Cenario* Astro1 = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
		sf::Vector2f(1200.0f, 500.0f), sf::Vector2f(0.10f, -0.15f), 6.0f);
	if (Astro1)lista_ents.incluir(static_cast<Entidade*>(Astro1));
	Cenario* Astro1b = new Cenario("assets/sprites/Background-fase-1/asteroid-1.png",
		sf::Vector2f(250.0f, 270.0f), sf::Vector2f(-0.8f, -0.13f), 6.0f);
	if (Astro1b)lista_ents.incluir(static_cast<Entidade*>(Astro1b));
	Cenario* Astro2 = new Cenario("assets/sprites/Background-fase-1/asteroid-2.png",
		sf::Vector2f(400.0f, 650.0f), sf::Vector2f(-10.0f, -0.1f), 6.0f);
	if (Astro2)lista_ents.incluir(static_cast<Entidade*>(Astro2*/
}