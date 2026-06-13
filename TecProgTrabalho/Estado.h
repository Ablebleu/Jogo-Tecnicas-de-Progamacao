#ifndef _ESTADO_H
#define _ESTADO_H

#include "Ente.h"

class Jogo;
namespace Gerenciador { class Gerenciador_Estados; }
namespace Estados
{
    class Estado : public Ente {
    protected:
        static Gerenciador::Gerenciador_Estados* pGE;
        static Jogo* pJogo;
    public:
        Estado();
        virtual ~Estado();

        virtual void executar() = 0;
        virtual void desenhar() = 0;

        void incluirEstado();
        static void setGE(Gerenciador::Gerenciador_Estados* p);
        static void setJogo(Jogo* p);
        static Gerenciador::Gerenciador_Estados* getGE() { return pGE; }
    };
}
#endif
