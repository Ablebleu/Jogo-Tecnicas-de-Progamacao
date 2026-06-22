#ifndef _ESTADO_H
#define _ESTADO_H

#include "Ente.h"

class Jogo;
namespace Gerenciador {
    class Gerenciador_Estados;
    class Gerenciador_Evento;
}
namespace Estados
{
    class Estado : public Ente {
    protected:
        static Gerenciador::Gerenciador_Grafico* pGG;
        static Gerenciador::Gerenciador_Estados* pGEs;
        static Gerenciador::Gerenciador_Evento* pGE;
        static Jogo* pJogo;
    public:
        Estado();
        virtual ~Estado();

        virtual void executar() = 0;
        virtual void desenhar() = 0;

        void incluirEstado();
        static void setGEs(Gerenciador::Gerenciador_Estados* p);
        static void setGE(Gerenciador::Gerenciador_Evento* p);
        static void setJogo(Jogo* p);
    };
}
#endif
