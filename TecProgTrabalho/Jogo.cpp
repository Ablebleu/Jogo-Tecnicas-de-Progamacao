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
	Gerenciador::Gerenciador_Colisoes::deletar();
	if (GEs) {
		delete GEs;
	}
	Gerenciador::Gerenciador_Evento::deletar();
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

void Jogo::salvarJogadoresVivos() {
	std::cout << "Carregando fase do save.json" << std::endl;
	std::ifstream file("save.json");
	if (!file.is_open()) {
		std::cerr << "Erro ao abrir save.json" << std::endl;
	}
	nlohmann::json datafase;
	file >> datafase;
	file.close();
	int j = 0;
	for (int i = 0; i < (int)datafase.size() && j < 2; i++) {
		std::string tipo = datafase[i]["tipo"];
		if (tipo == "Jogador") {
			j++;
			if (datafase[i]["Vivo"] = true) {
				nlohmann::json dadosJogador = datafase[i];
				std::cout << "Carregando pontuacao.json" << std::endl;
				std::ifstream file("pontuacao.json");

				nlohmann::json data = nlohmann::json::array(); // inicia como array vazio

				if (file.is_open()) {
					try {
						file >> data;
					}
					catch (const std::exception& e) {
						std::cerr << "Erro ao parsear JSON: " << e.what() << std::endl;
						data = nlohmann::json::array(); // reseta para array vazio
					}
					file.close();
				}
				else {
					std::cerr << "Arquivo pontuacao.json nao encontrado. Criando novo." << std::endl;
				}

				if (!data.is_array()) {
					std::cerr << "Aviso: JSON raiz nao e um array. Resetando." << std::endl;
					data = nlohmann::json::array();
				}

				std::vector<std::pair<int, std::string>> pontuacao;
				for (size_t i = 0; i < data.size(); ++i) {
					try {
						int pts = data[i].at("pontos").get<int>();
						std::string nome = data[i].at("Nome").get<std::string>();
						pontuacao.push_back({ pts, nome });
					}
					catch (const std::exception& e) {
						std::cerr << "Entrada invalida ignorada: " << e.what() << std::endl;
					}
				}

				pontuacao.push_back({ dadosJogador["pontos"], dadosJogador["Nome"]});

				std::sort(pontuacao.begin(), pontuacao.end(), greater<>());

				// Monta o novo ranking (top 5)
				nlohmann::json ranking = nlohmann::json::array();
				size_t limite = std::min((size_t)5, pontuacao.size());
				for (int i = 0; i < std::min(5, (int)pontuacao.size()); ++i) {
					nlohmann::json player;
					player["pontos"] = pontuacao[i].first;
					player["Nome"] = pontuacao[i].second;
					ranking.push_back(player);
				}

				std::ofstream file1("pontuacao.json");
				if (file1.is_open()) {
					file1 << ranking.dump(4);
					file1.close();
					std::cout << "Ranking salvo com sucesso!" << std::endl;
				}
				else {
					std::cerr << "Erro ao salvar o ranking." << std::endl;
				}
			}
		}
	}
}

Entidades::Jogador* Jogo::getJogador(int i, string nome) {
	if (i == 1) {
		if (pJog1) return pJog1;
		pJog1 = new Entidades::Jogador(1, nome);
		if (!pJog1) {
			std::cerr << "Erro ao criar Jogador" << std::endl;
			exit(1);
		}
		return pJog1;
	}
	if (i == 2) {
		if (pJog2) return pJog2;
		pJog2 = new Entidades::Jogador(2, nome);
		if (!pJog2) {
			std::cerr << "Erro ao criar Jogador" << std::endl;
			exit(1);
		}
		return pJog2;
	}
	return NULL;
}

Entidades::Jogador* Jogo::getJogador(const nlohmann::json& dados) {
	if (dados["ordemJogador"] == 1) {
		if (pJog1) delete pJog1;
		pJog1 = new Entidades::Jogador(dados);
		if (!pJog1) {
			std::cerr << "Erro ao dar load no Jogador" << std::endl;
			exit(1);
		}
		return pJog1;
	}
	if (dados["ordemJogador"] == 2) {
		if (pJog2) delete pJog2;
		pJog2 = new Entidades::Jogador(dados);
		if (!pJog2) {
			std::cerr << "Erro ao dar load no Jogador" << std::endl;
			exit(1);
		}
		return pJog2;
	}
	return NULL;
}
