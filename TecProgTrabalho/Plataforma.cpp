#include "Plataforma.h"
#include "Jogador.h"
#include <iostream>

Plataforma::Plataforma(sf::Vector2f p, sf::Vector2f prop) : Obstaculo(), proporcao(prop) {
    std::cout << "Criando plataforma: " << getId() << std::endl;
    pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/tiles/Plat_Tileset_1.png"));
    pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 64,32 }));
    pos = p;
    pSprite->setPosition(pos);
    pSprite->setScale(proporcao*2.5f);
}

Plataforma::~Plataforma() {
    std::cout << "Deletando plataforma: " << getId() << std::endl;
}

const sf::FloatRect Plataforma::getCorpo() {
    return pSprite->getGlobalBounds();
}

void Plataforma::executar() {

}

void Plataforma::mover() {

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
