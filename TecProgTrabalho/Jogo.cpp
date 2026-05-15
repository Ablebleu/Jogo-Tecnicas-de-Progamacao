#include "Jogo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Gerenciador::Gerenciador_Grafico* Jogo::GG = Gerenciador::Gerenciador_Grafico::getGerenciador_Grafico();
Gerenciador::Gerenciador_Evento* Jogo::GE = Gerenciador::Gerenciador_Evento::getGerenciador_Evento();

Jogo::Jogo() {
	if (!GG) {
		std::cerr << "Erro na criação do Gerador Gráfico" << std::endl;
	}
	if (!GE) {
		std::cerr << "Erro na criação do Gerador Eventos" << std::endl;
	}
	executar();
}
Jogo::~Jogo() {
	Gerenciador::Gerenciador_Grafico::deletar();
}

void Jogo::executar() {
	while (GG->janelaAberta()) {
		//GE->executar();
		//GEs->executar();
		GG->limparTela();
		//GEs->desenhar();
		GG->mostrarTela();
	}
}
