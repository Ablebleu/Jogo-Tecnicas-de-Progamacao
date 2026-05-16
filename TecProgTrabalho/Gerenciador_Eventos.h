#ifndef _GERENCIADOR_EVENTO_H
#define _GERENCIADOR_EVENTO_H

namespace Gerenciador {
	class Gerenciador_Grafico;
	class Gerenciador_Evento {
	private:
		Gerenciador_Grafico* pGG;

		static Gerenciador_Evento* pEvento;
		Gerenciador_Evento();
	public:
		void executar();
		~Gerenciador_Evento();
		static Gerenciador_Evento* getGerenciador_Evento();
		static void deletar();
	};
}

#endif