#include "Observer.h"

namespace Observadores {

    Observer::Observer() : ativo(true), evento(sf::Event::Closed{}) {

    }
    Observer::~Observer() {
    }
    void Observer::setAtivo(bool a) {
        ativo = a;
    }
    const bool Observer::getAtivo() const {
        return ativo;
    }
}
