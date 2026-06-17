#include "Observer_Menu.h"
#include <iostream>

namespace Observadores
{
    Observer_Menu::Observer_Menu() : Observer() {
        std::cout << "Observer_Menu criado." << std::endl;
        timerTeclas.restart();
    }

    Observer_Menu::~Observer_Menu() {
        std::cout << "Observer_Menu destruído." << std::endl;
    }

    void Observer_Menu::processarEvento(const sf::Event& evento) {
        if (const sf::Event::TextEntered* texto = evento.getIf<sf::Event::TextEntered>()) {
            Observer::evento = evento;
            executar();
        }
        if (timerTeclas.getElapsedTime().asSeconds() >= 0.05f) {
            Observer::evento = evento;
            executar();
            timerTeclas.restart();
        }
    }
}