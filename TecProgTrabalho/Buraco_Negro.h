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
		int cor;
		float tam;
		Jogador* pJogador;
	public:
		Buraco_Negro(sf::Vector2f p = sf::Vector2f(-100.f, -100.f), int dur = 0, int i = 1);
		Buraco_Negro(const nlohmann::json& dados);
		~Buraco_Negro();
		void salvar();
		void executar();
		void desenhar();
		void forcar();
		void setPos(sf::Vector2f p);
		void setJogador(Jogador* pJog);
		void danificar(Inimigo* pInim);
		void levitar();
		void sumir();
		void setAtivo(bool a);
		bool getAtivo();
	};
}
#endif