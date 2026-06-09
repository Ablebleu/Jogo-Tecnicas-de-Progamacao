#ifndef _GERENCIADOR_COLISOES_H
#define _GERENCIADOR_COLISOES_H
#include <vector>
#include <list>
#include <set>

using namespace std;

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

		vector<Entidades::Inimigo*> LIs;
		list<Entidades::Obstaculos::Obstaculo*> LOs;
		set<Entidades::Projetil*> LPs;
		//Checar depois como fazer para ter mais outro jogador sem ficar estranho
		Entidades::Jogador* pJog1;

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
		void executar();
		void tratarColisoesChaoEntidades(Fases::Chao &c);

		//Mudar o setJogadores e getJogadores depois
		void setJogadores(Entidades::Jogador *p1);
		Entidades::Jogador* getJogadores(int i) const;

		static Gerenciador_Colisoes* getGerenciador_Colisoes();
		static void deletar();
	};
}
#endif 
