#include "Chao.h"

Chao::Chao(int l) : Ente(), comprimento(l) {
	std::cout << "Criando chao da fase" << std::endl;
	pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/tiles/Chao.png", true));
	setComprimento(l);
	pSprite->setPosition(sf::Vector2f{ 0.0f, 600.0f });
	pSprite->setScale(sf::Vector2f{ 20.0f, 3.0f });
	
}

Chao::~Chao() {

}

void Chao::executar() {

}

const sf::FloatRect Chao::getCorpo() {
	return pSprite->getGlobalBounds();
}

void Chao::setComprimento(int l) {
	comprimento = l;
	pSprite->setTextureRect(sf::IntRect({ 0,0 }, { l,32 }));
}

void Chao::desenhar() {
	//std::cout << "Desenhando Chao" << std::endl;
	pGG->desenhar(pSprite);
}

void Chao::obstaculizar(Entidade* p) {
	sf::FloatRect corpoPassageiro = p->getCorpo();
	sf::FloatRect corpoObstaculo = getCorpo();
	std::optional<sf::FloatRect> intersecao = corpoPassageiro.findIntersection(corpoObstaculo);
	sf::Vector2f posAtual = p->getPos();
	posAtual.y -= intersecao->size.y;
	p->setPos(posAtual);
	p->setVel(sf::Vector2f(p->getVel().x, 0.f)); 
	p->houveContatoBase();
}