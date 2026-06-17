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
		adicionaBotao("Voltar", 13);
	}

	void Menu_Intermediario::executar() {

		if (Selecionado == 0) {
			// Navegação normal do menu
			Menu::executar();

			if (Selecionado == 11) {
				modoJogadores = 1;
				cursorNome = 0;
				nomes[0].clear();
				nomes[1].clear();
				textoTitulo.setString("Digite o nome do Jogador 1:");
				falta = 1;
				aguardandoLiberarEnter = true; // o Enter que selecionou ainda esta pressionado
			}
			else if (Selecionado == 12) {
				modoJogadores = 2;
				cursorNome = 0;
				nomes[0].clear();
				nomes[1].clear();
				textoTitulo.setString("Digite o nome do Jogador 1:");
				falta = 2;
				aguardandoLiberarEnter = true; // o Enter que selecionou ainda esta pressionado
			}
		}
		if (Selecionado == 11 || Selecionado == 12) {
			if (aguardandoLiberarEnter) {
				// Drena a fila descartando todos os eventos enquanto Enter esta pressionado.
				// Sem isso, o KeyPressed(Enter) que acionou o menu fica na fila
				// e confirma os nomes vazios no mesmo frame.
				while (const std::optional<sf::Event> optEvento = pGG->atualizaEvento()) {
					if (optEvento->is<sf::Event::Closed>()) {
						pGG->fecharJanela();
						return;
					}
					// descarta tudo o mais
				}
				// So libera quando a tecla for fisicamente solta
				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
					aguardandoLiberarEnter = false;
				}
				return;
			}

			// Processa eventos normalmente, um por vez
			while (const std::optional<sf::Event> optEvento = pGG->atualizaEvento()) {
				processarEvento(*optEvento);
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

	void Menu_Intermediario::processarEvento(const sf::Event& evento) {

		if (evento.is<sf::Event::Closed>()) {
			pGG->fecharJanela();
			return;
		}

		//
		if (const sf::Event::KeyPressed *key = evento.getIf<sf::Event::KeyPressed>()) {

			if (key->code == sf::Keyboard::Key::Enter) {

				if (cursorNome == 0 && modoJogadores == 2) {
					// Confirma jogador 1, pede jogador 2
					cursorNome = 1;
					textoTitulo.setString("Digite o nome do Jogador 2:");
					falta--;
					Selecionado = nFase + 10;
					aguardandoLiberarEnter = true; // mesma protecao para a transicao entre jogadores
				}
				else {
					// Ambos os nomes confirmados
					std::cout << "Nomes confirmados: "
						<< nomes[0] << " e "
						<< nomes[1] << std::endl;
					if (falta == 2) Selecionado = nFase + 20;
					falta--;
				}
			}
			else if (key->code == sf::Keyboard::Key::Backspace) {
				if (!nomes[cursorNome].empty()) {
					nomes[cursorNome].pop_back();
				}
			}
		}

		if (const sf::Event::TextEntered *text = evento.getIf<sf::Event::TextEntered>()) {
			char32_t c = text->unicode;
			if (c >= 32 && c < 127) {
				if (nomes[cursorNome].size() < 10) {
					nomes[cursorNome] += static_cast<char>(c);
				}
			}
		}
		//
	}

	const bool Menu_Intermediario::estaPronto() const {
		return (!falta);
	}

	std::string Menu_Intermediario::getNome(int i) {
		if (i == 1) return nomes[0];
		else return nomes[1];
	}
}