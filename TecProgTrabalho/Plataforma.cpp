#include "Plataforma.h"
#include "Jogador.h"
#include <iostream>

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(sf::Vector2f p, float l) : Obstaculo(), comprimento(l) {
            std::cout << "Criando plataforma: " << getId() << std::endl;
            pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/tiles/Plat_Tileset_1.png"));
            pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 64,32 }));
            pos = p;
            pSprite->setPosition(pos);
            pSprite->setScale(sf::Vector2f(2.5f * comprimento, 2.5f));
        }

        Plataforma::Plataforma(const nlohmann::json& dados) : Obstaculo(dados), 
            comprimento(dados["comprimento"]) {
            pSprite = new sf::Sprite(*pGG->carregarTextura("assets/sprites/tiles/Plat_Tileset_1.png"));
            pSprite->setTextureRect(sf::IntRect({ 0,0 }, { 64,32 }));
            pSprite->setPosition(pos);
            pSprite->setScale(sf::Vector2f(2.5f * comprimento, 2.5f));
        }

        Plataforma::~Plataforma() {
            std::cout << "Deletando plataforma: " << getId() << std::endl;
        }

        void Plataforma::executar() {
            forcar();
            mover();
			pSprite->setPosition(pos);
        }

        void Plataforma::salvar() {
            Obstaculo::salvarDataBuffer();
            dadosSalvos["tipo"] = "Plataforma";
            dadosSalvos["comprimento"] = comprimento;
        }

        void Plataforma::obstaculizar(Jogador* p) {
            sf::FloatRect corpoPassageiro = p->getCorpo();
            sf::FloatRect corpoObstaculo = getCorpo();
            std::optional<sf::FloatRect> intersecao = corpoPassageiro.findIntersection(corpoObstaculo);
            sf::Vector2f posAtual = p->getPos();

            if (intersecao->size.x < intersecao->size.y) {
                if (corpoPassageiro.position.x < corpoObstaculo.position.x) {
                    posAtual.x -= intersecao->size.x;
                    p->setVel(sf::Vector2f(0.f, p->getVel().y));
                }
                else {
                    posAtual.x += intersecao->size.x;
                    p->setVel(sf::Vector2f(0.f, p->getVel().y));
                }
            }
            else {
                if (corpoPassageiro.position.y < corpoObstaculo.position.y) {
                    posAtual.y -= intersecao->size.y;
                    p->setVel(sf::Vector2f(p->getVel().x, 0.f));
                    p->houveContatoBase();
                }
                else {
                    posAtual.y += intersecao->size.y;
                    p->setVel(sf::Vector2f(p->getVel().x, p->getVel().y / 2));
                }
            }

            p->setPos(posAtual);
        }
    }
}
