#include "Jogo.h"
#include "Estado_Fase.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include "Estado_Menu.h"
#include "Menu_Fase.h"
#include <iostream>

namespace Estados {
	Estado_Fase::Estado_Fase(int nf, int nj, vector<string> nomes) : Estado(), pFase(nullptr) {
		switch (nf) {
		case 1:
			pJogo->salvarJogadoresVivos();
			pFase = new Fases::Fase_Primeira(nj, nomes);
			if (!pFase) {
				std::cerr << "Erro ao criar fase" << std::endl;
			exit(1);
			}
			break;
		case 2:
			pJogo->salvarJogadoresVivos();
			pFase = new Fases::Fase_Segunda(nj, nomes);
			if (!pFase) {
				std::cerr << "Erro ao criar fase" << std::endl;
				exit(1);
			}
			break;
		case 3: {
			std::cout << "Carregando fase do save.json" << std::endl;
			std::ifstream file("save.json");
			if (!file.is_open()) {
				std::cerr << "Erro ao abrir save.json" << std::endl;
			}
			nlohmann::json data;
			file >> data;
			file.close();
			std::string tipoFase = data[0]["tipo"];
			if (tipoFase == "Fase_Primeira") pFase = new Fases::Fase_Primeira(data);
			if (tipoFase == "Fase_Segunda") pFase = new Fases::Fase_Segunda(data);
		}
			break;
		default:
			std::cout << "Fase inválida" << std::endl;
		}
	}
	Estado_Fase::~Estado_Fase() {
		cout << "Deletando Estado Fase" << endl;
		if (pFase) delete pFase;
		pFase = NULL;
		pJogo->deleteJogadores();
	}

	void Estado_Fase::executar() {
		if (pFase)
		{
			pFase->executar();
			int faseAcabou = pFase->getAcabou();
			if (faseAcabou) {
				if (faseAcabou%10 == 1) {
					delete pFase;
					Gerenciador::Gerenciador_Colisoes::getGerenciador_Colisoes()->limpar();
					pFase = new Fases::Fase_Segunda(faseAcabou/10);
				}
				else if (faseAcabou%10 == 2) {
					cout << "Parabens, voce venceu!" << endl;
				}
			}
			bool pausa = pFase->getPause();
			if (pausa) {
				Menus::Menu_Fase *pMenu = new Menus::Menu_Fase;
				if (pMenu) new Estados::Estado_Menu(pMenu);
			}
		}
		else {
			std::cerr << "Sem fase" << std::endl;
			exit(1);
		}
	}
	void Estado_Fase::desenhar() {
		if (pFase) pFase->desenhar();
		else {
			std::cerr << "Sem fase" << std::endl;
			exit(1);
		}
	}
}