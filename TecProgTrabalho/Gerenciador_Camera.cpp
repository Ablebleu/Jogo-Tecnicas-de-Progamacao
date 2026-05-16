#include "Gerenciador_Camera.h"

namespace Gerenciador {

    Gerenciador_Camera::Gerenciador_Camera(sf::Vector2f tamJanela) :
        camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(tamJanela.x, tamJanela.y))),
        limiteCamera(sf::Vector2f(0.f, 0.f), sf::Vector2f(tamJanela.x, tamJanela.y)),
        tamJanela(tamJanela)
    {
        camera.setSize(tamJanela);
        camera.setCenter(tamJanela * 0.5f);
    }

    Gerenciador_Camera::~Gerenciador_Camera() {}

    sf::View Gerenciador_Camera::getCamera() const {
        return camera;
    }

    // Deve garantir que limiteObjeto esteja dentro de limiteCamera
    void Gerenciador_Camera::ajustarLimite() {

    }

    void Gerenciador_Camera::resetar(sf::Vector2f posCenter) {

    }

    void Gerenciador_Camera::atualizar(sf::Vector2f pos) {
        camera.setCenter(pos);
        resetar(pos);
    }

    void Gerenciador_Camera::setLimiteCamera(sf::FloatRect limite) {
        limiteCamera = limite;
        ajustarLimite();
    }
}