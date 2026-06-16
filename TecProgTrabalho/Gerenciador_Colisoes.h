#ifndef _GERENCIADOR_COLISOES_H
#define _GERENCIADOR_COLISOES_H
#include <vector>
#include <list>
#include <set>

using namespace std;

class Jogo;
namespace Entidades
{
	class Inimigo;
	namespace Obstaculos {
		class Obstaculo;
	}
	class Projetil;
	class Jogador;
	class Entidade;
}
namespace Fases {
	class Chao;
}

namespace Gerenciador {
	class Gerenciador_Colisoes{
	private:
		Jogo* pJogo;

		vector<Entidades::Inimigo*> LIs;
		list<Entidades::Obstaculos::Obstaculo*> LOs;
		set<Entidades::Projetil*> LPs;

		Entidades::Jogador* pJog1;
		Entidades::Jogador* pJog2;

		const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2) const;
		void tratarColisoesJogsObstacs();
		void tratarColisoesJogsInimgs();
		void tratarColisoesAtqInimgs();
		void tratarColisoesJogsProjeteis();

		static Gerenciador_Colisoes* pColisoes;
		Gerenciador_Colisoes();
	public:

		~Gerenciador_Colisoes();
		void incluirInimigo(Entidades::Inimigo *pi);
		void incluirObstaculo(Entidades::Obstaculos::Obstaculo *po);
		void incluirProjetil(Entidades::Projetil *pj);
		Entidades::Projetil *getProjetil(int id);
		Entidades::Projetil *getProjetilUnico();
		void executar();
		void tratarColisoesChaoEntidades(Fases::Chao &c);

		void setJogo(Jogo *p);
		Entidades::Jogador* getJogadores(int i);

		static Gerenciador_Colisoes* getGerenciador_Colisoes();
		static void deletar();
	};
}
#endif 
