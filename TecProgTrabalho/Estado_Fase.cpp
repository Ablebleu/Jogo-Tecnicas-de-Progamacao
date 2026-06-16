#include "Jogo.h"
#include "Estado_Fase.h"
#include "Fase_Primeira.h"
#include "Fase_Segunda.h"
#include <iostream>

namespace Estados {
	Estado_Fase::Estado_Fase(int n) : Estado(), pFase(nullptr) {
		switch (n) {
		case 1:
			pFase = new Fases::Fase_Primeira();
			if (!pFase) {
				std::cerr << "Erro ao criar fase" << std::endl;
			exit(1);
			}
			break;
		case 2:
			pFase = new Fases::Fase_Segunda();
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
	}

	void Estado_Fase::executar() {
		if (pFase) pFase->executar();
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