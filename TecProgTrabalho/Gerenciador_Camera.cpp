#include "Gerenciador_Camera.h"

namespace Gerenciador {

    Gerenciador_Camera::Gerenciador_Camera(sf::Vector2f tamJanela) :
        camera(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(tamJanela.x, tamJanela.y))),
        limiteCamera(sf::Vector2f(0.f, 0.f), sf::Vector2f(tamJanela.x, tamJanela.y)),
        tamJanela(tamJanela)
    {
		std::cout << "Criando Gerenciador de Camera" << std::endl;
        camera.setSize(tamJanela);
        camera.setCenter(tamJanela * 0.5f);
    }

    Gerenciador_Camera::~Gerenciador_Camera() {
        std::cout << "Deletando Gerenciador de Camera" << std::endl;
    }

    sf::View Gerenciador_Camera::getCamera() const {
        return camera;
    }

    void Gerenciador_Camera::resetar() {
		tamJanela = sf::Vector2f(1200.f, 875.f);
        camera = sf::View(sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(tamJanela.x, tamJanela.y)));
		limiteCamera = sf::FloatRect(sf::Vector2f(0.f, 0.f), sf::Vector2f(tamJanela.x, tamJanela.y));
    }

    void Gerenciador_Camera::atualizar(sf::Vector2f pos) {
        camera.setCenter(pos);
		camera = sf::View(sf::FloatRect(pos - tamJanela * 0.5f, tamJanela));
    }

    void Gerenciador_Camera::setLimiteCamera(sf::FloatRect limite) {
        limiteCamera = limite;
    }
}