#ifndef _ESTADO_FASE_H
#define _ESTADO_FASE_H

#include "Estado.h"

class Fase;
class Estado_Fase : public Estado {
private:
    Fase* pFase;
public:
    Estado_Fase(int n);
    ~Estado_Fase();

    void criarFase1();
    void criarFase2();

    void executar();
    void desenhar();
};
#endif
