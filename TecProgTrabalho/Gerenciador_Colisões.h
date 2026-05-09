#ifndef _GERENCIADOR_COLISõES_H
#define _GERENCIADOR_COLISõES_H
#include <vector>
#include <list>
#include <set>

using namespace std;

/*
Na vdd esse deve ter include de todos os próximos:
*/
class Inimigo;
class Obstaculo;
class Projetil;
class Jogador;

namespace Gerenciadores {
	class Gerenciador_Colisões {
	public:
		void incluirInimigo(*Inimigo pi);
		void incluirObstcaulo(*Obstaculo po);
		void incluirProjetil(*Projetil pj);
		void executar();

		//. . .

	private:
		vector<*Inimigo> LIs;
		list<*Obstaculo> LOs;
		set<*Projetil> LPs;
		*Jogador pJog1;
		*Jogador pJog2;

		//. . .

		const bool verificarColisao(*Entidade pe1, *Entidade pe2) const;
		void tratarColisoesJogsObstacs();
		void tratarColisoesJogsInimgs();
		void tratarColisoesJogsProjeteis();
	};
}
#endif  //_GERENCIADOR_COLISõES_H
