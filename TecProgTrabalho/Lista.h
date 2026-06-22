#ifndef _LISTA_H
#define _LISTA_H

#include <iostream>

namespace Lista
{
	template <class TL>
	class Lista {
	public:

		template <class TE>
		class Elemento {
		private:
			Elemento<TE>* pProx;
			TE pinfo;
		public:
			Elemento();
			~Elemento();
			void incluir(TE p);
			void setProx(Elemento<TE>* pE);
			TE getInfo() const;
			Elemento<TE>* getProximo() const;
		};

	private:

		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;

	public:

		Lista();
		~Lista();
		void incluir(TL p);
		void limpar();
		Elemento<TL>* getPrimeiro() const;
		//void ...();

	};

	template <class TL>
	Lista<TL>::Lista() : pPrimeiro(NULL), pUltimo(NULL) {
		limpar();
	}

	template <class TL>
	Lista<TL>::~Lista() {
		limpar();
	}

	template <class TL>
	void Lista<TL>::limpar() {
		while (pPrimeiro) {
			Elemento<TL>* pAux = pPrimeiro;
			pPrimeiro = pPrimeiro->getProximo();
			delete pAux;
		}
		pUltimo = nullptr;
	}

	template <class TL>
	void Lista<TL>::incluir(TL p) {
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

template <class TL>
template <class TE>
Lista<TL>::Elemento<TE>::Elemento() : pProx(nullptr), pinfo() { }

template <class TL>
template <class TE>
Lista<TL>::Elemento<TE>::~Elemento() { pProx = nullptr; }

	template <class TL>
	template <class TE>
	void Lista<TL>::Elemento<TE>::incluir(TE p) { pinfo = p; }

	template <class TL>
	template <class TE>
	void Lista<TL>::Elemento<TE>::setProx(typename Lista<TL>::template Elemento<TE>* pE) { pProx = pE; }

	template <class TL>
	template <class TE>
	TE Lista<TL>::Elemento<TE>::getInfo() const { return pinfo; }

	template <class TL>
	template <class TE>
	typename Lista<TL>::template Elemento<TE>* Lista<TL>::Elemento<TE>::getProximo() const { return pProx; }
}

#endif