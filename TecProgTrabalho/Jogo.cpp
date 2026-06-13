#include <iostream>
#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include "Estado.h"

Gerenciador::Gerenciador_Grafico* Jogo::GG = NULL;
Gerenciador::Gerenciador_Evento * Jogo::GE = NULL;
Gerenciador::Gerenciador_Colisoes* Jogo::GC = NULL;

Jogo::Jogo() : pJog1(NULL), pJog2(NULL), fase(NULL), GEs(NULL) {

	GG = Gerenciador::Gerenciador_Grafico::getGerenciador_Grafico();
	GE = Gerenciador::Gerenciador_Evento::getGerenciador_Evento();
	GC = Gerenciador::Gerenciador_Colisoes::getGerenciador_Colisoes();
	Fases::Fase::setJogo(this);
	Estados::Estado::setJogo(this);
	GC->setJogo(this);

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
	/*pJog1 = new Entidades::Jogador(1);
	if (!pJog1) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		exit(1);
	}
	pJog2 = new Entidades::Jogador(2);
	if (!pJog2) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		exit(1);
	}*/

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

void Jogo::deleteJogadores() {
	if (pJog1) {
		delete pJog1;
		pJog1 = NULL;
	}
	if (pJog2) {
		delete pJog2;
		pJog2 = NULL;
	}
}

Entidades::Jogador* Jogo::getJogador(int i) {
	if (i == 1) {
		if (pJog1) return pJog1;
		pJog1 = new Entidades::Jogador(1);
		if (!pJog1) {
			std::cerr << "Erro ao criar Jogador" << std::endl;
			exit(1);
		}
		return pJog1;
	}
	if (i == 2) {
		if (pJog2) return pJog2;
		pJog2 = new Entidades::Jogador(2);
		if (!pJog2) {
			std::cerr << "Erro ao criar Jogador" << std::endl;
			exit(1);
		}
		return pJog2;
	}
	return NULL;
}

Fases::Fase* Jogo::getFase(int i) {
	if (fase) {
		if (pJog1) fase->removerEntidade(pJog1->getId());
		if (pJog2) fase->removerEntidade(pJog2->getId());
		delete fase;
	}
	switch (i) {
	case 1:
		fase = new Fases::Fase_Primeira();
		if (!fase) {
			std::cerr << "Erro ao criar fase" << std::endl;
			exit(1);
		}
		return fase;
	case 2:
		fase = new Fases::Fase_Segunda();
		if (!fase) {
			std::cerr << "Erro ao criar fase" << std::endl;
			exit(1);
		}
		return fase;
	case 3: {
		std::ifstream file("save.json");
		if (!file.is_open()) {
			std::cerr << "Erro ao abrir save.json" << std::endl;
			return NULL;
		}
		nlohmann::json data;
		file >> data;
		file.close();
		std::string tipoFase = data[0]["tipo"];
		if (tipoFase == "Fase_Primeira") fase = new Fases::Fase_Primeira(data);
		if (tipoFase == "Fase_Segunda") fase = new Fases::Fase_Segunda(data);
		return fase;
	}
	default:
		std::cout << "Fase inválida" << std::endl;
		return NULL;
	}
}

