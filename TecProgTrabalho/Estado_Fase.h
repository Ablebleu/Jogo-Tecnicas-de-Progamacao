#ifndef _ESTADO_FASE_H
#define _ESTADO_FASE_H

#include <vector>
#include <string>
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
        Estado_Fase(int nf = 1, int nj = 1, std::vector<std::string> nomes = { "", "" });
        ~Estado_Fase();

        void executar();
        void desenhar();
    };
}
#endif
