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
class Chao;

namespace Gerenciador {
	class Gerenciador_Colisoes{
	private:

		vector<Inimigo*> LIs;
		list<Obstaculo*> LOs;
		set<Projetil*> LPs;
		//Checar depois como fazer para ter mais outro jogador sem ficar estranho
		Jogador* pJog1;

		const bool verificarColisao(Entidade* pe1, Entidade* pe2) const;
		void tratarColisoesJogsObstacs();
		void tratarColisoesJogsInimgs();
		void tratarColisoesAtqInimgs();
		void tratarColisoesJogsProjeteis();
		void forcarEntidades();
		void AplicarForca(Entidade* pE);

		static Gerenciador_Colisoes* pColisoes;
		Gerenciador_Colisoes();
	public:

		~Gerenciador_Colisoes();
		void incluirInimigo(Inimigo *pi);
		void incluirObstaculo(Obstaculo *po);
		void incluirProjetil(Projetil *pj);
		void executar();
		void tratarColisoesChaoEntidades(class Chao &c);

		//Mudar o setJogadores e getJogadores depois
		void setJogadores(Jogador *p1);
		Jogador* getJogadores(int i) const;

		static Gerenciador_Colisoes* getGerenciador_Colisoes();
		static void deletar();
	};
}
#endif 
