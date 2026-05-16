#ifndef _ESTADO_H
#define _ESTADO_H

#include "Ente.h"

namespace Gerenciador { class Gerenciador_Estados; }

class Estado: public Ente {
private:
    static Gerenciador::Gerenciador_Estados* pGE;
public:
    Estado();
    virtual ~Estado();

    virtual void executar() = 0;
    virtual void desenhar() = 0;

    void incluirEstado();
    static void setGE(Gerenciador::Gerenciador_Estados* p);
    static Gerenciador::Gerenciador_Estados* getGE() { return pGE; }
};
#endif
