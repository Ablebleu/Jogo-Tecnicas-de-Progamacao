#include "Personagem.h"

Personagem::Personagem(): num_vidas(10), Entidade() {

}

Personagem::~Personagem() {

}

void Personagem::salvarDataBuffer() {

}

void Personagem::pular() {
	vel.y = -20.0f;
}

void Personagem::mover() {
	pos.x += vel.x;
	pos.y += vel.y;
	setPos(pos);
}