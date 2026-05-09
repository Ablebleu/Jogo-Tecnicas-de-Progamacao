#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include <iostream>

using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode({1600, 900}), "Jogo++") {
	Ente::setGG(this);
}

Gerenciador_Grafico::~Gerenciador_Grafico() {

}

void Gerenciador_Grafico::desenharEnte(Ente *pE) {
	if (!pE) {
		std::cerr << "Erro ao desenhar Ente: ponteiro nulo" << std::endl;
		return;
	}
	//std::cout << "a";
	janela.draw(*(pE->getSprite()));
}

bool Gerenciador_Grafico::janelaAberta() const {
	return janela.isOpen();
}

void Gerenciador_Grafico::limparTela() {
	janela.clear();
}

void Gerenciador_Grafico::fecharJanela() {
	janela.close();
}

void Gerenciador_Grafico::mostrarTela() {
	janela.display();
}

float Gerenciador_Grafico::atualizarTempo() {
	return relogio.restart().asSeconds();
}

std::optional<sf::Event> Gerenciador_Grafico::atualizaEvento() {
	return janela.pollEvent();
}

/*void Gerenciador_Grafico::...() {

}*/