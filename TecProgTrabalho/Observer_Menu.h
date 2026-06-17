#ifndef _OBSERVER_MENU_H
#define _OBSERVER_MENU_H

#include "Observer.h"
#include <SFML/Graphics.hpp>

namespace Observadores
{
    class Observer_Menu : public Observer {
    private:
        sf::Clock timerTeclas;
    public:
        Observer_Menu();
        virtual ~Observer_Menu();
        virtual void executar() = 0;

        virtual void processarEvento(const sf::Event& evento);
    };
}

#endif