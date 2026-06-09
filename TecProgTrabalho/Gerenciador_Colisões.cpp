#include <iostream>
#include <cmath>
#include "Gerenciador_Colisões.h"
#include "Fase.h"
#include "Entidade.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "Inimigo.h"

Gerenciador::Gerenciador_Colisoes* Gerenciador::Gerenciador_Colisoes::pColisoes = nullptr;
namespace Gerenciador {
	Gerenciador_Colisoes::Gerenciador_Colisoes() : LIs(), LOs(), LPs(), pJog1(NULL) {
		std::cout << "Criando Gerenciador de Colisões" << std::endl;
		LIs.clear();
		LOs.clear();
		LPs.clear();
		Fases::Fase::setGC(this);
		Entidades::Entidade::setGC(this);
	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes() {
		std::cout << "Deletando Gerenciador de Colisões" << std::endl;
	}

	void Gerenciador_Colisoes::incluirInimigo(Entidades::Inimigo* pi) {
		if (pi) LIs.push_back(pi);
		else std::cerr << "Inimigo nulo" << endl;
	}

	void Gerenciador_Colisoes::incluirObstaculo(Entidades::Obstaculos::Obstaculo* po) {
		if (po) {
			std::cout << "Incluindo obstáculo: " << po->getId() << std::endl;
			LOs.push_back(po);
		}
		else std::cerr << "Obstáculo nulo" << endl;
	}

	void Gerenciador_Colisoes::incluirProjetil(Entidades::Projetil* pj) {
		if (pj) LPs.insert(pj);
		else std::cerr << "Projétil nulo" << endl;
	}

	void Gerenciador_Colisoes::executar() {
		//Vou tentar implementar só colisão com parede por enquanto.
		tratarColisoesJogsObstacs();
		tratarColisoesJogsInimgs();
		tratarColisoesAtqInimgs();
		tratarColisoesJogsProjeteis();
	}

	const bool Gerenciador_Colisoes::verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2) const {
		//std::cout << "Checando se há colisão" << std::endl;
		return (const bool)pe1->getCorpo().findIntersection(pe2->getCorpo()).has_value();
	}

	void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
		//Vou tratar apenas um jogador por enquanto(Talvez faça set ou vector de Jogador depois)
		//OBS: Faz mais sentido fazer vector para obstáculos e list para inimigos pois obstáculos não variam mas inimigo sim
		//std::cout << "Indo detectar colisão" << std::endl;
		if (pJog1) {
			//std::cout << "Indo detectar colisão" << std::endl;
			for (list<Entidades::Obstaculos::Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++) {
				//std::cout << "Detectando colisão..." << std::endl;
				if (verificarColisao(static_cast<Entidades::Entidade*>(pJog1), static_cast<Entidades::Entidade*>(*it))) {
					//std::cout << "Colisão detectada" << std::endl;
					(*it)->obstaculizar(pJog1);
				}
			}
		}
	}

	void Gerenciador_Colisoes::tratarColisoesJogsInimgs() {

	}

	void Gerenciador_Colisoes::tratarColisoesAtqInimgs() {
		for (vector<Entidades::Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++) {
			if (verificarColisao(static_cast<Entidades::Entidade*>(pJog1->getAtaque()), static_cast<Entidades::Entidade*>(*it))) {
				//std::cout << "Colisão detectada" << std::endl;
				pJog1->getAtaque()->danificar(*it);
			}
		}
	}

	void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() {

	}

	void Gerenciador_Colisoes::tratarColisoesChaoEntidades(Fases::Chao &c) {
		if (pJog1 && (const bool)c.getCorpo().findIntersection(pJog1->getCorpo()).has_value()) {
			c.obstaculizar(static_cast<Entidades::Entidade*>(pJog1));
		}
		for (vector<Entidades::Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++) {
			if ((const bool)c.getCorpo().findIntersection((*it)->getCorpo()).has_value()) {
				c.obstaculizar(static_cast<Entidades::Entidade*>(*it));
			}
		}
	}

	void Gerenciador_Colisoes::setJogadores(Entidades::Jogador* p1) {
		std::cout << "Setando jogador de id "<< p1->getId() << " em colisões" << std::endl;
		if(p1) pJog1 = p1;
		else std::cerr << "Jogador nulo" << std::endl;
	}

	Entidades::Jogador* Gerenciador_Colisoes::getJogadores(int i) const{
		if (i == 1) return pJog1;
		else return NULL;
	}

	Gerenciador_Colisoes* Gerenciador_Colisoes::getGerenciador_Colisoes() {
		if(pColisoes == nullptr) {
			pColisoes = new Gerenciador_Colisoes();
		}
		return pColisoes;
	}

	void Gerenciador_Colisoes::deletar() {
		if (pColisoes) {
			delete pColisoes;
			pColisoes = nullptr;
		}
	}
}