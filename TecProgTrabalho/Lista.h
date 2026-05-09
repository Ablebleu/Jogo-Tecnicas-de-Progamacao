#ifndef _LISTA_H
#define _LISTA_H

#include <iostream>

template <class TL> 
class Lista {
public:

	template <class TE>
	class Elemento {
	private:
		Elemento<TE>* pProx;
		TE* pinfo;
	public:
		Elemento() { pProx = nullptr; pinfo = nullptr; }
		~Elemento() {
			pProx = nullptr;
			if (pinfo) delete pinfo;
			pinfo = nullptr;
		}
		void incluir(TE* p) { pinfo = p; }
		void setProx(Elemento<TE>* pE) { pProx = pE; }
		TE *getInfo() const { return pinfo; }
		Elemento<TE>* getProximo() const { return pProx; }
	};

private:

	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;

public:

	Lista();
	~Lista();
	void incluir(TL *p);
	void limpar();
	Elemento<TL> *getPrimeiro() const;
	//void ...();

};

template <class TL>
Lista<TL>::Lista(): pPrimeiro(NULL), pUltimo(NULL) {

}

template <class TL>
Lista<TL>::~Lista() {
	while(pPrimeiro) {
		Elemento<TL>* pAux = pPrimeiro;
		pPrimeiro = pPrimeiro->getProximo();
		delete pAux;
	}
}

template <class TL>
void Lista<TL>::limpar() {
	
}

template <class TL>
void Lista<TL>::incluir(TL *p) {
	if (p) {
		//std::cout << "z";
		Elemento<TL>* pNovo = new Elemento<TL>;
		pNovo->incluir(p);
		if (!pPrimeiro) pPrimeiro = pNovo;
		else pUltimo->setProx(pNovo);
		pUltimo = pNovo;
	}
}

template <class TL>
Lista<TL>::Elemento<TL>* Lista<TL>::getPrimeiro() const {
	return pPrimeiro;
}

#endif