#ifndef _OBSERVER_H
#define _OBSERVER_H

#include <SFML/Window/Event.hpp>

namespace Observadores
{
    class Observer {
    protected:
        bool ativo;
        sf::Event evento;
    public:
        Observer();
        virtual ~Observer();
        virtual void executar() = 0;
        virtual void processarEvento(const sf::Event& evento) = 0;
        void setAtivo(bool a);
        const bool getAtivo() const;
    };
}

#endif