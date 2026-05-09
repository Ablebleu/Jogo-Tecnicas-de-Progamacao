#include "Gerenciador_Grafico.h"
#include "Ente.h"
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode({1600, 900}), "Jogo++") {
	Ente::setGG(this);
}

Gerenciador_Grafico::~Gerenciador_Grafico() {

}

void Gerenciador_Grafico::desenharEnte(Ente *pE) {

}

bool Gerenciador_Grafico::janelaAberta() const {
	return janela.isOpen();
}
void Gerenciador_Grafico::fecharJanela() {
	janela.close();
}

std::optional<sf::Event> Gerenciador_Grafico::atualizaEvento() {
	return janela.pollEvent();
}

/*void Gerenciador_Grafico::...() {

}*/