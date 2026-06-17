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
        if (evento.is<sf::Event::KeyPressed>()) {
            if (evento.getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Enter) {
            }
        }
        if (timerTeclas.getElapsedTime().asSeconds() >= 0.15f) {
            Observer::evento = evento;
            executar();
            timerTeclas.restart();
        }
    }
}