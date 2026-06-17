#ifndef _OBSERVER_H
#define _OBSERVER_H

#include <SFML/Window/Event.hpp>
namespace Gerenciador { class Gerenciador_Evento; }

namespace Observadores
{
    class Observer {
    protected:
        bool ativo;
        sf::Event evento;
        static Gerenciador::Gerenciador_Evento *pGE;
    public:
        Observer();
        virtual ~Observer();
        virtual void executar() = 0;
        virtual void processarEvento(const sf::Event& evento) = 0;
        static void setGE(Gerenciador::Gerenciador_Evento* p);
        void setAtivo(bool a);
        const bool getAtivo() const;
    };
}

#endif