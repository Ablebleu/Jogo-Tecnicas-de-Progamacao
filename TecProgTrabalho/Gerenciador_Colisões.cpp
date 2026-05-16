#include <iostream>
#include "Gerenciador_Colisões.h"
#include "Entidade.h"
#include "Obstaculo.h"
#include "Jogador.h"

namespace Gerenciador {
	Gerenciador_Colisoes::Gerenciador_Colisoes() : LIs(), LOs(), LPs(), pJog1(NULL), pJog2(NULL) {
		LIs.clear();
		LOs.clear();
		LPs.clear();
	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes() {

	}

	void Gerenciador_Colisoes::incluirInimigo(Inimigo* pi) {
		if (pi) LIs.push_back(pi);
		else std::cerr << "Inimigo nulo" << endl;
	}

	void Gerenciador_Colisoes::incluirObstaculo(Obstaculo* po) {
		if (po) LOs.push_back(po);
		else std::cerr << "Obstáculo nulo" << endl;
	}

	void Gerenciador_Colisoes::incluirProjetil(Projetil* pj) {
		if (pj) LPs.insert(pj);
		else std::cerr << "Projétil nulo" << endl;
	}

	void Gerenciador_Colisoes::executar() {
		//Vou tentar implementar só colisão com parede por enquanto.
		tratarColisoesJogsObstacs();

		tratarColisoesJogsInimgs();
		tratarColisoesJogsProjeteis();
	}

	const bool Gerenciador_Colisoes::verificarColisao(Entidade* pe1, Entidade* pe2) const {
		//std::cout << "Checando se há colisão" << std::endl;
		return (const bool)pe1->getCorpo().findIntersection(pe2->getCorpo()).has_value();
	}

	void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
		//Vou tratar apenas um jogador por enquanto(Talvez faça set ou vector de Jogador depois)
		//OBS: Faz mais sentido fazer vector para obstáculos e list para inimigos pois obstáculos não variam mas inimigo sim
		if (pJog1) {
			for (list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++) {
				if (verificarColisao(static_cast<Entidade*>(pJog1), static_cast<Entidade*>(*it))) {
					//std::cout << "Colisão detectada" << std::endl;
					(*it)->obstaculizar(pJog1);
				}
			}
		}
	}

	void Gerenciador_Colisoes::tratarColisoesJogsInimgs() {

	}

	void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() {

	}

	void Gerenciador_Colisoes::setJogadores(Jogador* p1, Jogador* p2) {
		pJog1 = p1;
		pJog2 = p2;
	}
}