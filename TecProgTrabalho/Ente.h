#ifndef _ENTE_H
#define _ENTE_H

namespace Gerenciador { class Gerenciador_Grafico; }
class Ente {
private:
	int id;
	static int cont_id;
	static Gerenciador::Gerenciador_Grafico *pGG;
public:
	Ente();
	//Ente(int id);
	virtual ~Ente();
	const int getID() const;
	static void setGG(Gerenciador::Gerenciador_Grafico *pG);
};