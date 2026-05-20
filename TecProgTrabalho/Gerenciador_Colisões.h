#ifndef _GERENCIADOR_COLISOES_H
#define _GERENCIADOR_COLISOES_H
#include <vector>
#include <list>
#include <set>

using namespace std;

class Inimigo;
class Obstaculo;
class Projetil;
class Jogador;
class Entidade;

namespace Gerenciador {
	class Gerenciador_Colisoes{
	private:

		vector<Inimigo*> LIs;
		list<Obstaculo*> LOs;
		set<Projetil*> LPs;
		Jogador* pJog1;
		Jogador* pJog2;

		const bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
		void tratarColisoesJogsObstacs();
		void tratarColisoesJogsInimgs();
		void tratarColisoesJogsProjeteis();

		static Gerenciador_Colisoes* pColisoes;
		Gerenciador_Colisoes();
	public:

		~Gerenciador_Colisoes();
		void incluirInimigo(Inimigo *pi);
		void incluirObstaculo(Obstaculo *po);
		void incluirProjetil(Projetil *pj);
		void executar();
		void setJogadores(Jogador *p1, Jogador *p2);

		static Gerenciador_Colisoes* getGerenciador_Colisoes();
		static void deletar();
	};
}
#endif 
