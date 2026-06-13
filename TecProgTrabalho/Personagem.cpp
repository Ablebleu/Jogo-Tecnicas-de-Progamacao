#include "Personagem.h"
#include "json.hpp"

namespace Entidades {
	Personagem::Personagem() : Entidade(), num_vidas(9), vivo(true), frameInv(0) {

	}

	Personagem::Personagem(const nlohmann::json& dados) : Entidade(dados), num_vidas(dados["num_vidas"]),
		vivo(dados["vivo"]), frameInv(dados["frameInv"]) {

	}

	Personagem::~Personagem() {

	}

	void Personagem::salvarDataBuffer() {
		Entidade::salvarDataBuffer();

		dadosSalvos["tipo_base"] = "Personagem";
		dadosSalvos["num_vidas"] = num_vidas;
		dadosSalvos["vivo"] = vivo;
		dadosSalvos["frameInv"] = frameInv;
	}

	void Personagem::pular() {
	}

	void Personagem::mover() {
		Entidade::mover();
	}

	void Personagem::forcar() {
		gravitar();
		arrastar();
		atritar();
	}

	void Personagem::operator-=(int dano) {
		num_vidas -= dano;
		if (num_vidas <= 0) {
			num_vidas = 0;
			setVivo(false);
		}
	}

	int Personagem::getVidas() const{
		return num_vidas;
	}

	bool Personagem::getVivo() const{
		return vivo;
	}

	void Personagem::setVivo(bool v) {
		vivo = v;
	}
	/*
	void Personagem::podePular() {
		pulou = false;
	}
	*/
}