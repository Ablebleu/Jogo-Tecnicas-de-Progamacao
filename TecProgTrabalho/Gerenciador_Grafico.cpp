#include "Gerenciador_Grafico.h"
#include "Ente.h"
using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico(): janela(sf::VideoMode({400, 400}), "Jogo") {}

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
bool Gerenciador_Grafico::pollEvento(sf::Event& evento) {
	return janela.pollEvent(evento);
}
/*void Gerenciador_Grafico::...() {

}*/