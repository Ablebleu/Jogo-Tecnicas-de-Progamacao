#include "Gerenciador_Estados.h"
using namespace Gerenciadores;

Gerenciador_Estados::Gerenciador_Estados() : pilhaEstados() {
	while (!pilhaEstados.empty()) {
		pilhaEstados.pop();
	}
}

Gerenciador_Estados::~Gerenciador_Estados() {

}

void Gerenciador_Estados::incluirEstado(Estado* pE) {

}

void Gerenciador_Estados::removerEstado(int qtd) {
	for (int i = 0; i < qtd; i++) {
		if (!pilhaEstados.empty()) {
			removerEstado();
		}
		else break;
	}
}
void Gerenciador_Estados::removerEstado() {

}

void Gerenciador_Estados::desenhar() {

}
