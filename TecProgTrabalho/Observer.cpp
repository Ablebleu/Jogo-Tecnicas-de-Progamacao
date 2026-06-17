#include <iostream>
#include "Observer.h"
#include "Gerenciador_Eventos.h"

namespace Observadores {
    Gerenciador::Gerenciador_Evento* Observer::pGE = NULL;
    Observer::Observer() : ativo(true), evento(sf::Event::Closed{}) {
        std::cout << "Incluindo observador" << std::endl;
        pGE->incluirObservador(this);
    }
    Observer::~Observer() {
        pGE->removerObservador(this);
    }
    void Observer::setAtivo(bool a) {
        ativo = a;
        sf::Event event(sf::Event::Closed{});
    }
    void Observer::setGE(Gerenciador::Gerenciador_Evento* p) {
        pGE = p;
    }
    const bool Observer::getAtivo() const {
        return ativo;
    }
}
