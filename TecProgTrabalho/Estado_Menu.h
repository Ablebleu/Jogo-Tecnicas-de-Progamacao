#ifndef _ESTADO_MENU_H
#define _ESTADO_MENU_H

#include "Estado.h"
#include "Menu.h"

class Estado_Menu : public Estado {
private:
    Menus::Menu* pMenu;
public:
    Estado_Menu(Menus::Menu* pM = NULL);
    ~Estado_Menu();

    void executar();
    void desenhar();
};
#endif