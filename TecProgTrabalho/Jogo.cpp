#include "Jogo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Gerenciador::Gerenciador_Grafico* Jogo::GG = Gerenciador::Gerenciador_Grafico::getGerenciador_Grafico();
Gerenciador::Gerenciador_Evento* Jogo::GE = Gerenciador::Gerenciador_Evento::getGerenciador_Evento();
Gerenciador::Gerenciador_Colisoes* Jogo::GC = Gerenciador::Gerenciador_Colisoes::getGerenciador_Colisoes();

Jogo::Jogo() : pJog1(NULL), pJog2(NULL), fase1(NULL), faseAtual(NULL), GEs(NULL) {

	if (!GG) {
		std::cerr << "Erro na criação do Gerador Gráfico" << std::endl;
		exit(1);
	}
	if (!GE) {
		std::cerr << "Erro na criação do Gerador Eventos" << std::endl;
		exit(1);
	}
	if (!GC) {
		std::cerr << "Erro ao criar Gerenciador Eventos" << std::endl;
		exit(1);
	}

	GEs = new Gerenciador::Gerenciador_Estados;
	if (!GEs) {
		std::cerr << "Erro ao criar Gerenciador Estados" << std::endl;
		exit(1);
	}

	//Jogadores
	pJog1 = new Entidades::Jogador(1);
	if (!pJog1) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		exit(1);
	}
	pJog2 = new Entidades::Jogador(2);
	if (!pJog1) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		exit(1);
	}

	//Seed baseada na execução normal do programa
	srand((unsigned int)time(NULL));

	/*Adicionar Menu depois*/ 
	executar(); 
}
Jogo::~Jogo() {
	Gerenciador::Gerenciador_Grafico::deletar();
	Gerenciador::Gerenciador_Evento::deletar();
	Gerenciador::Gerenciador_Colisoes::deletar();
	if (GEs) {
		delete GEs;
	}
}

/*Loop principal do jogo.
* Eventos são tratados em Gerenciador_Eventos
* O jogo é atualizado em Gerenciador_Grafico.
*/
void Jogo::executar() {
	while(GG->janelaAberta()) {
		GE->executar();
		GEs->executar();
		GG->limparTela();
		GEs->desenhar();
		GG->mostrarTela();
	}
}

/*void Jogo::...() {

}*/

