#include <iostream>
#include <fstream>
#include "Jogador.h"
#include "json.hpp"

namespace Entidades {
	Jogador::Jogador(int i, std::string nome) : Personagem(), Nome(nome), pontos(0), ordemJogador(i), hp(*pGG->carregarTextura("assets/sprites/hp1.png")),
		tecla_cima(sf::Keyboard::Key::W), tecla_baixo(sf::Keyboard::Key::S),
		tecla_esquerda(sf::Keyboard::Key::A), tecla_direita(sf::Keyboard::Key::D) {
		std::cout << "Criando jogador " << Nome << ordemJogador << ": " << getId() << std::endl;

		//Para jogador 2
		if (ordemJogador == 2) {
			tecla_cima = sf::Keyboard::Key::Up;
			tecla_baixo = sf::Keyboard::Key::Down;
			tecla_esquerda = sf::Keyboard::Key::Left;
			tecla_direita = sf::Keyboard::Key::Right;
		}

		//ataque -> buraco_negro
		pAtaque = new Buraco_Negro({ -50.0f, -50.0f }, 120, ordemJogador);
		pAtaque->setJogador(this);

		//hitbox
		corpo.setSize(sf::Vector2f(50.0f, 80.0f));
		corpo.setOrigin({ corpo.getSize().x / 2.0f , corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		//sprite
		hp.setScale(sf::Vector2f(2.f, 2.f));
		if (ordemJogador == 1) 
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Astronaut_Idle.png"));
		else 
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Astronaut_Idle2.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 16 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });//origem -> centro do sprite
		pos.x = 100.0f;
		pos.y = 500.0f;
		pSprite->setPosition(pos);
		pSprite->setScale(sf::Vector2f(5.0f, 5.0f));
	}

	Jogador::Jogador(const nlohmann::json& dados) : Personagem(dados), Nome(dados["Nome"]), pontos(dados["pontos"]),
		ordemJogador(dados["ordemJogador"]), hp(*pGG->carregarTextura("assets/sprites/hp1.png")),
		tecla_cima(sf::Keyboard::Key::W), tecla_baixo(sf::Keyboard::Key::S),
		tecla_esquerda(sf::Keyboard::Key::A), tecla_direita(sf::Keyboard::Key::D) {
		std::cout << "Criando jogador " << ordemJogador << ": " << getId() << std::endl;

		if (ordemJogador == 2) {
			tecla_cima = sf::Keyboard::Key::Up;
			tecla_baixo = sf::Keyboard::Key::Down;
			tecla_esquerda = sf::Keyboard::Key::Left;
			tecla_direita = sf::Keyboard::Key::Right;
		}

		pAtaque = new Buraco_Negro(dados["ataque"]);
		pAtaque->setJogador(this);

		corpo.setSize(sf::Vector2f(50.0f, 80.0f));
		corpo.setOrigin({ corpo.getSize().x / 2.0f , corpo.getSize().y / 2.0f });//origem -> centro da hitbox

		hp.setScale(sf::Vector2f(2.f, 2.f));
		if (ordemJogador == 1)
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Astronaut_Idle.png"));
		else
			pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/Astronaut_Idle2.png"));
		pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 16, 16 }));
		pSprite->setOrigin({ pSprite->getLocalBounds().size.x / 2.0f, pSprite->getLocalBounds().size.y / 2.0f });
		pSprite->setPosition(pos);
		pSprite->setScale(sf::Vector2f(5.0f, 5.0f));
	}

	Jogador::~Jogador() {
		std::cout << "Deletando jogador: " << getId() << std::endl;

	}

	void Jogador::colidir(Inimigo* pIn) {
	}

	void Jogador::executar() {
		if(vivo)
		{
			if (frameInv > 0) frameInv--;
			//std::cout << "ID: " << getId() << " Pos: (" << pos.x << ", " << pos.y << ")" << std::endl;
			forcar();
			mover();
			atacar();
		}
	}

	void Jogador::desenhar() {
		//Vida
		pSprite->setScale({ virado * (-10.f) + 5.f, 5.f });
		hp.setTextureRect(sf::IntRect({ 64*(num_vidas+1)/**/,16}, {64 /**/, 48}));
		hp.setPosition(sf::Vector2f(std::fmax(pGG->getPosJanela().x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f) + sf::Vector2f(10.f + 30.f, 5.f + 40.f * ordemJogador));
		pGG->desenhar(&hp);
		//Pontuação
		sf::Text texto(*pGG->getFonte());
		texto.setString(std::to_string(pontos));
		texto.setCharacterSize(18);
		texto.setFillColor(sf::Color::White);
		texto.setPosition(sf::Vector2f(std::fmax(pGG->getPosJanela().x - pGG->getTamJanela().x * 0.5f, 0.0f), 0.0f) + sf::Vector2f(180.f, 24.f + 40.f * ordemJogador));
		//pontos += 100;
		pGG->desenhar(&texto);
		//Sprite e corpo
		Personagem::desenhar();
	}

	void Jogador::salvar() {
		Personagem::salvarDataBuffer();

		dadosSalvos["Nome"] = Nome;
		dadosSalvos["tipo"] = "Jogador";
		dadosSalvos["pontos"] = pontos;
		dadosSalvos["ordemJogador"] = ordemJogador;

		if (pAtaque) {
			pAtaque->salvar();                                
			dadosSalvos["ataque"] = pAtaque->getDadosSalvos();
		}
	}

	void Jogador::acelerar() {
		if (sf::Keyboard::isKeyPressed(tecla_direita)) {
			vel.x += 0.5f;
			if (pSprite->getScale().x < 0)
			{
				virado = false;
			}
		}
		else if (sf::Keyboard::isKeyPressed(tecla_esquerda)) {
			vel.x += -0.5f;
			if (pSprite->getScale().x > 0)
			{
				virado = true;
			}
		}
	}

	void Jogador::pular() {
		if (sf::Keyboard::isKeyPressed(tecla_cima)) {
			if (contatoBase) {
				vel.y = -90.0f;
				contatoBase = false;
			}
		}
	}

	void Jogador::mover() {
		pular();
		acelerar();
		//std::cout << vel.y << std::endl;
		Personagem::mover();

		float posMinx = pGG->getPosJanela().x - pGG->getTamJanela().x * 0.5f;
		if (pos.x < posMinx) pos.x = posMinx;
		float posMaxx = pGG->getPosJanela().x + pGG->getTamJanela().x * 0.5f;
		if (pos.x > posMaxx) pos.x = posMaxx;

		setPos(pos);
	}

	void Jogador::operator-=(int dano) {
		if (!frameInv) {
			Personagem::operator-=(dano);
			if (!vivo) {
				//Função criada com auxílio de IA baseado numa função falha
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

				pontuacao.push_back({ pontos, Nome });

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
			frameInv = 60;
		}
	}

	void Jogador::atacar() {
		if (sf::Keyboard::isKeyPressed(tecla_baixo) && pAtaque->getAtivo() == false)
		{
			pAtaque->setAtivo(true);
			pAtaque->setPos(pos + sf::Vector2f(100.0f, -10.0f));
		}
	}

	void Jogador::addPontos(int pont) {
		pontos += pont;
	}

	void Jogador::setPos(sf::Vector2f p) {
		//Hitbox
		Entidade::setPos(p);
		//Sprite
		pSprite->setPosition(pos);
	}

	void Jogador::setTeclas(sf::Keyboard::Key cima, sf::Keyboard::Key baixo, sf::Keyboard::Key esq, sf::Keyboard::Key dir) {
		tecla_cima = cima;
		tecla_baixo = baixo;
		tecla_esquerda = esq;
		tecla_direita = dir;
	}

	Buraco_Negro* Jogador::getAtaque() {
		return pAtaque;
	}
}