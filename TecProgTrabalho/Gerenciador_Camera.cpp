#include "Gerenciador_Grafico.h"
#include "Gerenciador_Camera.h"

namespace Gerenciador {

    Gerenciador_Camera::Gerenciador_Camera(const sf::Vector2f tamJanela) {
    
    }

    Gerenciador_Camera::~Gerenciador_Camera() {

    }

    void Gerenciador_Camera::setLimiteCamera(const sf::IntRect limiteCamera) {
        this->limiteCamera = limiteCamera;
        ajustarLimite();
    }

    void Gerenciador_Camera::ajustarLimite() {

    }

    sf::View Gerenciador_Camera::getCamera() {
        return camera;
    }

    void Gerenciador_Camera::resetar(const sf::Vector2f posCenter) {
        camera.setCenter(posCenter);
    }
}