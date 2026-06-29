#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include <list>
#include "Gerenciador_Camera.h"

class Ente;

/* Gerenciador Gráfico desenvolvido com inspiração nos códigos do então monitor
Giovane Limas Salvi de técnicas de programação. Github: https://github.com/Giovanenero */

namespace Gerenciador {
	class Gerenciador_Grafico {
	private:
		sf::RenderWindow* janela;
		sf::Clock relogio;
		Gerenciador_Camera camera;
		sf::Font Fonte;

		std::list<sf::Texture*> ltext;

		static Gerenciador_Grafico* pGrafico;
		Gerenciador_Grafico();
	public:
		~Gerenciador_Grafico();
		bool janelaAberta() const;
		void limparTela();
		void fecharJanela();
		void mostrarTela();
		sf::Texture* carregarTextura(const char* caminho, bool repetir = false);
		void desenhar(sf::RectangleShape* corpo);
		void desenhar(sf::Sprite* sprite);
		void desenhar(sf::Drawable* drawable);
		void resetarView();
		void atualizarView(const sf::Vector2f pos);
		void atualizarTamanho(sf::Vector2f novoTam);
		std::optional<sf::Event> atualizaEvento();
		const sf::Vector2f getTamJanela() const;
		const sf::Vector2f getPosJanela() const;
		const sf::Font *getFonte() const;
		static Gerenciador_Grafico* getGerenciador_Grafico();
		static void deletar();
	};
}
#endif
