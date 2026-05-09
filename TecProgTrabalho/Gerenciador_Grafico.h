#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include <SFML/Graphics.hpp>

class Ente;
namespace Gerenciadores {
	class Gerenciador_Grafico {
	private:
		sf::RenderWindow janela;
		sf::Clock relogio;
		//BiblioGrafica obj;
		//. . .

	public:
		Gerenciador_Grafico();
		~Gerenciador_Grafico();
		void desenharEnte(Ente *pE);
		//void criarPlanoFundo();
		bool janelaAberta() const;
		void limparTela();
		void fecharJanela();
		void mostrarTela();
		float atualizarTempo();
		std::optional<sf::Event> atualizaEvento();

		//. . .

	};
}
#endif
