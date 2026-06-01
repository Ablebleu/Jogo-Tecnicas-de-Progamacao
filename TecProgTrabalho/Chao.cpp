#include "Chao.h"

Chao::Chao() : Sprite(sf::Sprite(*Gerenciador::Gerenciador_Grafico::getGerenciador_Grafico()->carregarTextura("assets/sprites/tiles/RunnerTileSet.png"))) {
	std::cout << "Criando chao da fase" << std::endl;
	Sprite.setTextureRect(sf::IntRect({ 12,0 }, { 108,32 }));
	Sprite.setPosition(sf::Vector2f{ 0.0f, 600.0f });
	Sprite.setScale(sf::Vector2f{ 20.0f, 3.0f });
}

Chao::~Chao() {

}

const sf::FloatRect Chao::getCorpo() {
	return Sprite.getGlobalBounds();
}

void Chao::setPos(float posX) {
	Sprite.setPosition(sf::Vector2f(posX, 600.f));
}

void Chao::desenhar() {
	//std::cout << "Desenhando" << std::endl;
	Gerenciador::Gerenciador_Grafico::getGerenciador_Grafico()->desenhar(&Sprite);
}

void Chao::obstaculizar(Entidade* p) {
	sf::FloatRect corpoPassageiro = p->getCorpo();
	sf::FloatRect corpoObstaculo = getCorpo();
	std::optional<sf::FloatRect> intersecao = corpoPassageiro.findIntersection(corpoObstaculo);
	sf::Vector2f posAtual = p->getPos();
	posAtual.y -= intersecao->size.y;
	p->setPos(posAtual);
	p->setVel(sf::Vector2f(p->getVel().x, 0.f)); 
}