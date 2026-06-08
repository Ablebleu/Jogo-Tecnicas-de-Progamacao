#ifndef _CHAO_H
#define _CHAO_H

#include "Ente.h"
#include "Entidade.h"
#include "Gerenciador_Grafico.h"

namespace Fases
{
	class Chao : public Ente {
	private:
		int comprimento;
	public:
		Chao(int l = 2000.f);
		~Chao();
		void executar();
		const sf::FloatRect getCorpo();
		void setComprimento(int l);
		void desenhar();
		void obstaculizar(Entidades::Entidade* p);
	};
}
#endif