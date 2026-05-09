#include "Jogo.h"
#include <iostream>

Jogo::Jogo() : GG(NULL), GE(NULL) { 

	GG = new Gerenciadores::Gerenciador_Grafico;
	if (!GG) std::cerr << "Erro ao criar Gerenciador Grafico" << std::endl;

	GE = new Gerenciadores::Gerenciador_Eventos(GG);
	if (!GE) std::cerr << "Erro ao criar Gerenciador Eventos" << std::endl;

	/*Adicionar Menu depois*/ 
	executar(); 
}

Jogo::~Jogo() {
	if (GG) delete GG;
	if (GE) delete GE;
}

/*Loop principal do jogo.
* Eventos são tratados em Gerenciador_Eventos
* O jogo é atualizado em Gerenciador_Grafico.
*/
void Jogo::executar() {
	while(GG->janelaAberta()) {
		GE->executar();
	}
}

/*void Jogo::...() {

}*/

