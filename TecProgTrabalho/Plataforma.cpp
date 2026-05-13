#include "Plataforma.h"
#include "Jogador.h"
#include <iostream>

Plataforma::Plataforma(sf::Texture *textura): prop(sf::Vector2(2.0f, 2.0f)) {
	pSprite = new sf::Sprite(*textura);
	pSprite->setScale(sf::Vector2f(1.0f, 1.0f) * tam);
	pSprite->setPosition(pos);
}

Plataforma::~Plataforma() {

}

void Plataforma::executar(float dt) {

}

void Plataforma::mover(float dt) {

}

void Plataforma::salvar() {

}

void Plataforma::obstaculizar(Jogador* p) {
    sf::FloatRect corpoPassageiro = p->getCorpo();
    sf::FloatRect corpoObstaculo = getCorpo();
    std::optional<sf::FloatRect> intersecao = corpoPassageiro.findIntersection(corpoObstaculo);
    sf::Vector2f posAtual = p->getPos(); 

    if (intersecao->size.x < intersecao->size.y) { 
        if (corpoPassageiro.position.x < corpoObstaculo.position.x)
            posAtual.x -= intersecao->size.x;
        else posAtual.x += intersecao->size.x; 
    }
    else {
        if (corpoPassageiro.position.y < corpoObstaculo.position.y)
            posAtual.y -= intersecao->size.y;
        else posAtual.y += intersecao->size.y;
    }
    p->setPos(posAtual);
}
