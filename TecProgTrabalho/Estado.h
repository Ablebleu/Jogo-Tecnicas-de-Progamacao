#ifndef _ESTADO_H
#define _ESTADO_H

#include "Ente.h"

class Gerenciador_Estados;
class Estado: public Ente {
    static Gerenciador_Estados* pGE;
public:
    Estado() {}
    virtual ~Estado() {}

    virtual void executar() = 0;
    virtual void desenhar() = 0;

    static void setGE(Gerenciador_Estados* p);
};
#endif
