#include "Menu_Intermediario.h"
#include <iostream>

namespace Menus {

	Menu_Intermediario::Menu_Intermediario(int n)
		: Menu(), falta(-1), nomes(2, std::string("")), nFase(n), modoJogadores(1),
		cursorNome(-1), aguardandoLiberarEnter(false),
		textoTitulo(*pGG->getFonte()), textoNomeInput(*pGG->getFonte())
	{
		criarBotoes();
		seletor = lbotoes.begin();

		textoTitulo.setCharacterSize(36);
		textoTitulo.setFillColor(sf::Color::Yellow);
		textoTitulo.setPosition(sf::Vector2f(400.f, 200.f));

		textoNomeInput.setCharacterSize(40);
		textoNomeInput.setFillColor(sf::Color::White);
		textoNomeInput.setPosition(sf::Vector2f(400.f, 300.f));
	}

	Menu_Intermediario::~Menu_Intermediario() {
	}

	void Menu_Intermediario::criarBotoes() {
		adicionaBotao("1 Jogador", 11);
		adicionaBotao("2 Jogadores", 12);
		adicionaBotao("Voltar", -1);
	}

	void Menu_Intermediario::executar() {
		if (!falta) return;
		if (Selecionado == -1) falta = 0;
		else if (Selecionado == 0) {
			Menu::executar();

			if (Selecionado == 11) {
				modoJogadores = 1;
				cursorNome = 0;
				nomes[0].clear();
				nomes[1].clear();
				textoTitulo.setString("Digite o nome do Jogador 1:");
				falta = 1;
				aguardandoLiberarEnter = true; 
			}
			else if (Selecionado == 12) {
				modoJogadores = 2;
				cursorNome = 0;
				nomes[0].clear();
				nomes[1].clear();
				textoTitulo.setString("Digite o nome do Jogador 1:");
				falta = 2;
				aguardandoLiberarEnter = true; 
			}
		}
		else
		{
			sf::Event::KeyPressed* key = evento.getIf<sf::Event::KeyPressed>();
			if (key) {
				if (key->code == sf::Keyboard::Key::Enter) {

					if (cursorNome == 0 && modoJogadores == 2) {
						cursorNome = 1;
						textoTitulo.setString("Digite o nome do Jogador 2:");
						falta--;
						Selecionado = nFase + 10;
						aguardandoLiberarEnter = true; 
					}
					else {
						std::cout << "Nomes confirmados: "
							<< nomes[0] << " e "
							<< nomes[1] << std::endl;
						Selecionado = nFase + 20;
						falta--;
					}
				}
				else if (key->code == sf::Keyboard::Key::Backspace) {
					if (!nomes[cursorNome].empty()) {
						nomes[cursorNome].pop_back();
					}
				}
			}

			const sf::Event::TextEntered* texto = evento.getIf<sf::Event::TextEntered>();
			if (texto) {
				char32_t c = texto->unicode;
				if (c >= 32 && c < 127) {
					if (nomes[cursorNome].size() < 10) {
						nomes[cursorNome] += static_cast<char>(c);
					}
				}
			}
		}
	}

	void Menu_Intermediario::desenhar() {
		if (Selecionado == 0) {
			Menu::desenhar();
		}
		else {
			textoNomeInput.setString(nomes[cursorNome] + "_");
			pGG->desenhar(&textoTitulo);
			pGG->desenhar(&textoNomeInput);
		}
	}

	const bool Menu_Intermediario::estaPronto() const {
		return (!falta);
	}

	std::string Menu_Intermediario::getNome(int i) {
		if (i == 1) return nomes[0];
		else return nomes[1];
	}
}