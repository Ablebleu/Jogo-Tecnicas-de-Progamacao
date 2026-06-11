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

    public:
        Gerenciador_Camera(const sf::Vector2f tamJanela = { 1200.0f, 875.0f });
        ~Gerenciador_Camera();
        sf::View getCamera() const;
        void resetar();
        void atualizar(sf::Vector2f pos);
        void setLimiteCamera(sf::FloatRect limiteCamera);
		const sf::Vector2f getTamJanela() const;
        const sf::Vector2f getCenter() const;
    };
}
#endif