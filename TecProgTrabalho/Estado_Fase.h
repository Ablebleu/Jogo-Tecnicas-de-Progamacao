#ifndef _ESTADO_FASE_H
#define _ESTADO_FASE_H

#include "Estado.h"

namespace Fases {
    class Fase;
}
namespace Estados
{
    class Estado_Fase : public Estado {
    private:
        Fases::Fase* pFase;
    public:
        Estado_Fase(int n);
        ~Estado_Fase();

        void executar();
        void desenhar();
    };
}
#endif
