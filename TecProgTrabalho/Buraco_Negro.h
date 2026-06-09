#ifndef _BURACO_NEGRO_H
#define _BURACO_NEGRO_H

#include "Entidade.h"
#include "Inimigo.h"

namespace Entidades
{
	class Buraco_Negro : public Entidade {
	private:
		int duracao;//frames
		bool ativo;
		float tam;
	public:
		Buraco_Negro(sf::Vector2f p, int dur);
		~Buraco_Negro();
		void salvar();
		void executar();
		void desenhar();
		void forcar();
		void setPos(sf::Vector2f p);
		void danificar(Inimigo* pInim);
		void levitar();
		void sumir();
		void setAtivo(bool a);
		bool getAtivo();
	};
}
#endif