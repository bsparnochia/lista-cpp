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

	/*
	 * Crea un nodo a partir de la información a almacenar
	 * sin un enlace aún no establecido
	 */
	Nodo( int datoNuevo){

		this->dato = datoNuevo;
		this->siguiente = nullptr;
	}

	/*
	 * Obtiene el dato del nodo
	 */
	int getDato() const {
		return dato;
	}

	/*
	 * Configura el dato del nodo
	 */
	void setDato(int dato) {
		this->dato = dato;
	}

	/*
	 * Obtiene el siguiente nodo
	 */
	Nodo* getSiguiente() const {
		return siguiente;
	}

	/*
	 * Configura el nodo para enlazarlo con otro nodo que le sucede
	 */
	void setSiguiente( Nodo *siguiente) {
		this->siguiente = siguiente;
	}

private:
	int dato;
	Nodo* siguiente;

};




#endif /* NODO_H_ */
