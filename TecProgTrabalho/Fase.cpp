#include <cmath>
#include "Fase.h"
#include "Jogador.h"

Gerenciador::Gerenciador_Colisoes* Fase::pGC = nullptr;

Fase::Fase(): Ente(), chao(), pJog1(NULL) {
	for (int i = 0; i < 10; i++)
		chao[i].setPos(2000 * i);
	pJog1 = pGC->getJogadores(1);
	std::cout << "Criando fase: " << getId() << std::endl;
}

Fase::~Fase() {
	std::cout << "Deletando fase: " << getId() << std::endl;
	lista_ents.deletarEntidades();
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
	if (pGC) {
		//std::cout << "Indo executar GC" << std::endl;
		pGC->executar();
	}
	else cerr << "Nenhuma GC para ser executada" << endl;
	for (int i = 0; i < 10; i++) {
		lista_ents.verificarChao(chao[i]);
	}
	moverCamera();
}

void Fase::moverCamera() {
	if(pJog1) {
		sf::Vector2f posJog = pJog1->getPos();
		pGG->atualizarView(sf::Vector2f(std::fmax(posJog.x, pGG->getTamJanela().x * 0.5f), 
										pGG->getTamJanela().y * 0.5f));
		pSprite->setPosition(sf::Vector2f(std::fmax(posJog.x - pGG->getTamJanela().x * 0.5f, 0.0f),0.0f));
	}
}

void Fase::incluirJogador(Jogador* pE) {
	if (pE) lista_ents.incluir(static_cast<Entidade*>(pE));
}

void Fase::desenhar() {
	pGG->desenhar(pSprite);
	for (int i = 0; i < 10; i++) {
		std::cout << "Desenhando chao" << i << std::endl;
		chao[i].desenhar();
	}
	lista_ents.desenhar();
}

void Fase::removerEntidade(int id) {
	lista_ents.remover(id);
}

void Fase::setGC(Gerenciador::Gerenciador_Colisoes *pG) {
	if(pG) pGC = pG;
	else cerr << "GC não incluido na fase." << endl;
}