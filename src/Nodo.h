/*
 * Nodo.h
 *
 *  Created on: 22 may. 2020
 *      Author: brian
 */

#ifndef NODO_H_
#define NODO_H_

class Nodo{

public:

	Nodo( int datoNuevo){

		this->dato = datoNuevo;
		this->siguiente = nullptr;
	}

	int getDato() const {
		return dato;
	}

	void setDato(int dato) {
		this->dato = dato;
	}

	const Nodo* getSiguiente() const {
		return siguiente;
	}

	void setSiguiente(const Nodo *siguiente) {
		this->siguiente = siguiente;
	}

private:
	int dato;
	Nodo* siguiente;

};




#endif /* NODO_H_ */
