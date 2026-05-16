#include "Jogo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Gerenciador::Gerenciador_Grafico* Jogo::GG = Gerenciador::Gerenciador_Grafico::getGerenciador_Grafico();
Gerenciador::Gerenciador_Evento* Jogo::GE = Gerenciador::Gerenciador_Evento::getGerenciador_Evento();

Jogo::Jogo() : pJog1(NULL), pJog2(NULL), fase1(NULL), faseAtual(NULL), GC(NULL), GEs(NULL) {

	if (!GG) {
		std::cerr << "Erro na criação do Gerador Gráfico" << std::endl;
		exit(1);
	}
	if (!GE) {
		std::cerr << "Erro na criação do Gerador Eventos" << std::endl;
		exit(1);
	}

	GC = new Gerenciador::Gerenciador_Colisoes;
	if (!GC) {
		std::cerr << "Erro ao criar Gerenciador Eventos" << std::endl;
		exit(1);
	}

	GEs = new Gerenciador::Gerenciador_Estados;
	if (!GEs) {
		std::cerr << "Erro ao criar Gerenciador Estados" << std::endl;
		exit(1);
	}
	
	/*pJog1 = new Jogador;
	if (!pJog1) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		return;
	}

	pJog2 = new Jogador;
	if (!pJog1) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		exit(1);
	}
	pJog2->setTeclas(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right);

	fase1 = new Fase_Primeira(GC);
	if (!fase1) {
		std::cerr << "Erro ao criar Fase" << std::endl;
		exit(1);
	}

	fase1->incluirJogador(pJog1);
	fase1->incluirJogador(pJog2);
	GC->setJogadores(pJog1, pJog2 );*/

	faseAtual = static_cast<Fase*>(fase1);

	/*Adicionar Menu depois*/ 
	executar(); 
}
Jogo::~Jogo() {
	Gerenciador::Gerenciador_Grafico::deletar();
	Gerenciador::Gerenciador_Evento::deletar();
	if (GC) delete GC;
	if (pJog1) {
		faseAtual->removerEntidade(pJog1->getId());
		delete pJog1;
	}
	if (pJog2) {
		faseAtual->removerEntidade(pJog2->getId());
		delete pJog2;
	}
	if (fase1) delete fase1;
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

