#include <fstream>
#include "Menu_Pontos.h"
#include "json.hpp"

class Fase;
namespace Menus {
	Menu_Pontos::Menu_Pontos() : ranking(), rank(5, (*pGG->getFonte())) {
		ranking.clear();
		criarBotoes();
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

		for (size_t i = 0; i < data.size(); ++i) {
			try {
				int pts = data[i].at("pontos").get<int>();
				std::string nome = data[i].at("Nome").get<std::string>();
				ranking.push_back({ pts, nome });
			}
			catch (const std::exception& e) {
				std::cerr << "Entrada invalida ignorada: " << e.what() << std::endl;
			}
		}
		for (int i = 5; ranking.size(); i++) {
			rank[i].setString(std::to_string(i) + ": " + ranking[i].second + "; Pontuação: " + std::to_string(ranking[i].first));
			rank[i].setCharacterSize(36);
			rank[i].setFillColor(sf::Color::Yellow);
			rank[i].setPosition(sf::Vector2f(200.f, 100.f + 50.f));
		}
	}

	Menu_Pontos::~Menu_Pontos() {

	}

	void Menu_Pontos::executar() {
		Menu::executar();
	}

	void Menu_Pontos::desenhar() {
		Menu::desenhar();
		for (int i = 5; ranking.size(); i++) {
			pGG->desenhar(&rank[i]);
		}
	}

	void Menu_Pontos::criarBotoes() {
		adicionaBotao("Voltar", -1);
	}
}