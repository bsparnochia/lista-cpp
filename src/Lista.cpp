/*
 * Lista.cpp
 *
 *  Created on: 22 may. 2020
 *      Author: brian
 */

#include "Lista.h"
#include <iostream>
#include <string>

const int NINGUNO = 0;
const int PRIMER_ELEMENTO = 1;

Lista::Lista() {

	this->cantidadDeElementos = NINGUNO;
	this->primero = nullptr;
}

Lista::~Lista(){

	/* Me posiciono en el primer elemento de la lista */
	Nodo* actual = this->primero;

	/* recorre la lista si contiene registros */
	while ( actual ){

		/* guardo el registro siguiente */
		Nodo* siguiente = actual->getSiguiente();

		/* elimino el registro actual */
		delete actual;

		/* el registro siguiente ahora es el actual a eliminar */
		actual = siguiente;
	}

}

void Lista::altaFinal( int dato ){

	/* Creo el registro donde se guarda el dato */
	Nodo* nuevo = new Nodo( dato );

	if ( this->listaVacia() ){

		/* Asigno el registro como el primer elemento de la lista*/
		this->primero = nuevo;
	}
	else{

		/* Avanzo en la lista hasta el último registro */
		Nodo* ultimaPosicion = this->recorrerLista( this->cantidadDeElementos );

		/* Agrego el nuevo registro al final de la lista */
		ultimaPosicion->setSiguiente( nuevo );
	}
}

bool Lista::listaVacia(){

	return this->primero == nullptr;
}

void Lista::mostrar(){

	/* Me posiciono en el primer elemento de la lista */
	Nodo* actual = this->primero;

	std:: cout << "{ ";

	/* Mientras haya elementos los muestro por pantalla */
	while ( actual ){

		std :: cout << actual->getDato() << ", ";
	}

	std:: cout << " }";
}

Nodo* Lista::recorrerLista ( int posicion ){

	/* Verifico que la posición ingresada exista en la lista */
	if ( this->fueraDeRango ( posicion ) ){

		throw std::string ( " posicion ingresada fuera de rango ");
	}

	/* Me posiciono en el primer elemento de la lista */
	Nodo* actual = this->primero;
	int posicionActual = PRIMER_ELEMENTO;

	/* Avanzo hasta llegar a la posicion deseada */
	while ( posicionActual < posicion ){

		/* Me posiciono en el elemento siguiente */
		actual = actual->getSiguiente();
	}

	/* Devuelvo el elemento buscado */
	return actual;
}

bool Lista::fueraDeRango( int posicion ){

	return ( posicion > this->cantidadDeElementos ) ||
				( posicion < PRIMER_ELEMENTO );
}
