#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include "Gerenciador_Camera.h"

class Ente;

namespace Gerenciador {
	class Gerenciador_Grafico {
	private:
		sf::RenderWindow* janela;
		sf::Clock relogio;
		Gerenciador_Camera camera;

		static Gerenciador_Grafico* pGrafico;
		Gerenciador_Grafico();
	public:
		~Gerenciador_Grafico();
		bool janelaAberta() const;
		void limparTela();
		void fecharJanela();
		void resetarRelogio();
		void mostrarTela();
		float atualizarTempo();
		sf::Texture carregarTextura(const char* caminho);
		void desenhar(sf::RectangleShape* corpo);
		void desenhar(sf::Sprite* sprite);
		void desenhar(sf::Drawable* drawable);
		void atualizarView(const sf::Vector2f pos);
		std::optional<sf::Event> atualizaEvento();
		static Gerenciador_Grafico* getGerenciador_Grafico();
		static void deletar();
	};
}
#endif
