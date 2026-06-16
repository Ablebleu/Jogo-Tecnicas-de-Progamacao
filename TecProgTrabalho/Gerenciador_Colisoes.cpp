#include <iostream>
#include <cmath>
#include "Jogo.h"
#include "Gerenciador_Colisoes.h"
#include "Fase.h"
#include "Entidade.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Jogador.h"
#include "Inimigo.h"

Gerenciador::Gerenciador_Colisoes* Gerenciador::Gerenciador_Colisoes::pColisoes = nullptr;
namespace Gerenciador {
	Gerenciador_Colisoes::Gerenciador_Colisoes() : pJogo(NULL), LIs(), LOs(), LPs(), pJog1(NULL), pJog2(NULL) {
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

	Entidades::Projetil* Gerenciador_Colisoes::getProjetil(int id) {
		set<Entidades::Projetil*>::iterator it;
		for (it = LPs.begin(); it != LPs.end(); ++it) {
			if ((*it)->getId() == id) return *it;
		}
		return NULL;
	}

	Entidades::Projetil *Gerenciador_Colisoes::getProjetilUnico() {
		set<Entidades::Projetil*>::iterator it;
		for (it = LPs.begin(); it != LPs.end(); ++it) {
			if (!(*it)->estaRelacionado()) return *it;
		}
		return NULL;
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
		if (pJog2) {
			//std::cout << "Indo detectar colisão" << std::endl;
			for (list<Entidades::Obstaculos::Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++) {
				//std::cout << "Detectando colisão..." << std::endl;
				if (verificarColisao(static_cast<Entidades::Entidade*>(pJog2), static_cast<Entidades::Entidade*>(*it))) {
					//std::cout << "Colisão detectada" << std::endl;
					(*it)->obstaculizar(pJog2);
				}
			}
		}
	}

	void Gerenciador_Colisoes::tratarColisoesJogsInimgs() {
		for (vector<Entidades::Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++) {
			if ((*it)->getVivo() && verificarColisao(static_cast<Entidades::Entidade*>(pJog1), static_cast<Entidades::Entidade*>(*it))) {
				//std::cout << "Colisão detectada" << std::endl;
				(*it)->danificar(pJog1);
			}
			if ((*it)->getVivo() && verificarColisao(static_cast<Entidades::Entidade*>(pJog2), static_cast<Entidades::Entidade*>(*it))) {
				//std::cout << "Colisão detectada" << std::endl;
				(*it)->danificar(pJog2);
			}
		}
	}

	void Gerenciador_Colisoes::tratarColisoesAtqInimgs() {
		for (vector<Entidades::Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++) {
			if (verificarColisao(static_cast<Entidades::Entidade*>(pJog1->getAtaque()), static_cast<Entidades::Entidade*>(*it))) {
				//std::cout << "Colisão detectada" << std::endl;
				pJog1->getAtaque()->danificar(*it);
			}
			if (verificarColisao(static_cast<Entidades::Entidade*>(pJog2->getAtaque()), static_cast<Entidades::Entidade*>(*it))) {
				//std::cout << "Colisão detectada" << std::endl;
				pJog2->getAtaque()->danificar(*it);
			}
		}
	}

	void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() {
		for (std::set<Entidades::Projetil*>::iterator it = LPs.begin(); it != LPs.end(); it++) {
			if (verificarColisao(static_cast<Entidades::Entidade*>(pJog1), static_cast<Entidades::Entidade*>(*it))) {
				(*it)->danificar(pJog1);
			}
			if (verificarColisao(static_cast<Entidades::Entidade*>(pJog2), static_cast<Entidades::Entidade*>(*it))) {
				//std::cout << "Colisão detectada" << std::endl;
				(*it)->danificar(pJog2);
			}
		}
	}

	void Gerenciador_Colisoes::tratarColisoesChaoEntidades(Fases::Chao &c) {
		if (pJog1 && (const bool)c.getCorpo().findIntersection(pJog1->getCorpo()).has_value()) {
			c.obstaculizar(static_cast<Entidades::Entidade*>(pJog1));
		}
		if (pJog2 && (const bool)c.getCorpo().findIntersection(pJog2->getCorpo()).has_value()) {
			c.obstaculizar(static_cast<Entidades::Entidade*>(pJog2));
		}
		for (vector<Entidades::Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++) {
			if ((const bool)c.getCorpo().findIntersection((*it)->getCorpo()).has_value()) {
				c.obstaculizar(static_cast<Entidades::Entidade*>(*it));
			}
		}
		for (std::set<Entidades::Projetil*>::iterator it = LPs.begin(); it != LPs.end(); it++) {
			if ((const bool)c.getCorpo().findIntersection((*it)->getCorpo()).has_value()) {
				(*it)->setAtivo(false);
			}
		}
	}

	void Gerenciador_Colisoes::setJogo(Jogo* p) {
		pJogo = p;
	}

	Entidades::Jogador* Gerenciador_Colisoes::getJogadores(int i){
		if (i == 1) pJog1 = pJogo->getJogador(1);
		else if (i == 2) pJog2 = pJogo->getJogador(2);
		return pJogo->getJogador(i);
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