#ifndef _LISTA_H
#define _LISTA_H

template <class TL> 
class Lista {
private:

	template <class TE> 
	class Elemento {
	private:
		Elemento<TE>* pProx;
		TE* pinfo;
	public:
		Elemento() { pProx = nullptr; pinfo = nullptr; }
		~Elemento() { pProx = nullptr; pinfo = nullptr; }
		void incluir(TE *p) { pinfo = p; }
		void setProx(Elemento<TE> *pE) { pProx = pE; }
		Elemento<TE>* getProximo() const { return pProx; }
	};

	Elemento<TL> *pPrimeiro;
	Elemento<TL> *pUltimo;

public:

	Lista();
	~Lista();
	void incluir(TL *p);
	void limpar();
	//void ...();

};

template <class TL>
Lista<TL>::Lista() {

}

template <class TL>
Lista<TL>::~Lista() {

}

template <class TL>
void Lista<TL>::limpar() {

}

template <class TL>
void Lista<TL>::incluir(TL *p) {

}

#endif