#ifndef _GERENCIADOR_CAMERA_H
#define _GERENCIADOR_CAMERA_H

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Gerenciador {
    class Gerenciador_Camera {
    private:
        sf::View camera;
        sf::FloatRect limiteCamera;
        sf::Vector2f tamJanela;

        void ajustarLimite(); // aplica limites à view
    public:
        Gerenciador_Camera(const sf::Vector2f tamJanela = sf::Vector2f(800.f, 600.f));
        ~Gerenciador_Camera();
        sf::View getCamera() const;
        void resetar(sf::Vector2f posCenter);
        void atualizar(sf::Vector2f pos);
        void setLimiteCamera(sf::FloatRect limiteCamera);
    };
}
#endif