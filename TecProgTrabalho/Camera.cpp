#include "Gerenciador_Grafico.h"
#include "Camera.h"

namespace Gerenciador {

    Camera::Camera(const sf::Vector2f tamJanela) {
    
    }

    Camera::~Camera() {

    }

    void Camera::setLimiteCamera(const sf::IntRect limiteCamera) {
        this->limiteCamera = limiteCamera;
        ajustarLimite();
    }

    void Camera::ajustarLimite() {

    }

    sf::View Camera::getCamera() {
        return camera;
    }

    void Camera::resetar(const sf::Vector2f posCenter) {
        camera.setCenter(posCenter);
    }
}