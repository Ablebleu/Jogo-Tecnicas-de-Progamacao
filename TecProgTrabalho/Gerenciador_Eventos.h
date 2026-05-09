#ifndef _GERENCIADOR_EVENTOS_H
#define _GERENCIADOR_EVENTOS_H

namespace Gerenciadores {
	class Gerenciador_Grafico;
	class Gerenciador_Eventos {
	private:
		Gerenciador_Grafico* pGG;
		//. . .
	public:
		Gerenciador_Eventos(Gerenciador_Grafico* GG = nullptr);
		~Gerenciador_Eventos();
		void setGG(Gerenciador_Grafico* GG);
		void executar();
	};
}

#endif
