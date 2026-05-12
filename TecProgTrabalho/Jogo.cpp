#include "Jogo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Jogo::Jogo() : fps(120), pJog1(NULL), pJog2(NULL), fase1(NULL), faseAtual(NULL), GG(NULL), GE(NULL) {

	GG = new Gerenciadores::Gerenciador_Grafico;
	if (!GG) {
		std::cerr << "Erro ao criar Gerenciador Grafico" << std::endl;
		return;
	}

	GE = new Gerenciadores::Gerenciador_Eventos(GG);
	if (!GE) {
		std::cerr << "Erro ao criar Gerenciador Eventos" << std::endl;
		return;
	}
	
	pJog1 = new Jogador;
	if (!pJog1) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		return;
	}

	pJog2 = new Jogador;
	if (!pJog1) {
		std::cerr << "Erro ao criar Jogador" << std::endl;
		return;
	}
	pJog2->setTeclas(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right);

	fase1 = new Fase_Primeira;
	if (!fase1) {
		std::cerr << "Erro ao criar Fase" << std::endl;
		return;
	}

	fase1->incluirEntidade(static_cast<Entidade*>(pJog1));
	fase1->incluirEntidade(static_cast<Entidade*>(pJog2));

	faseAtual = static_cast<Fase*>(fase1);

	/*Adicionar Menu depois*/ 
	executar(); 
}
Jogo::~Jogo() {
	if (GG) delete GG;
	if (GE) delete GE;
	if (pJog1) {
		faseAtual->removerEntidade(pJog1->getId());
		delete pJog1;
	}
	if (fase1) delete fase1;
}

/*Loop principal do jogo.
* Eventos são tratados em Gerenciador_Eventos
* O jogo é atualizado em Gerenciador_Grafico.
*/
void Jogo::executar() {
	float tempo_acumulado = 0.0f;
	float dt = 1.0f / fps;
	while(GG->janelaAberta()) {
		float tempoFrame = GG->atualizarTempo();
		tempo_acumulado += tempoFrame;
		while (tempo_acumulado >= dt) {
			GE->executar();

			/*Essa função vai ser mudada no futuro,
			fazendo a classe perder essa responsabilidade
			mas por enquanto estará para testes */
			faseAtual->executar(dt);
			tempo_acumulado -= dt;
		}
		//std::cout << "Tempo acumulado: " << tempo_acumulado << " segundos" << std::endl;
		GG->limparTela();
		faseAtual->desenhar();
		GG->mostrarTela();
	}
}

/*void Jogo::...() {

}*/

