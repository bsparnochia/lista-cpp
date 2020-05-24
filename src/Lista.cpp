/*
 * Lista.cpp
 *
 *  Created on: 22 may. 2020
 *      Author: brian
 */

#include "Lista.h"
#include <iostream>
#include <string>

/* ---------- CONSTANTES ---------------- */

/* Indica que no hay elementos contabilizados en la lista */
const int NINGUNO = 0;

const int PRIMER_ELEMENTO = 1;

/* Indica si el elemento buscado se encuentra en la lista */
const bool NO_ENCONTRADO = false;
const bool HAY_COINCIDENCIA = true;

/* -------------------------------------- */


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

void Lista::altaPrincipio( int dato ){

	Nodo* nuevo = new Nodo( dato );

	/* Verifico si existe un primer elemento en al lista */
	if ( this->primero ){

		nuevo->setSiguiente( this->primero );
	}

	this->primero = nuevo;
}

void Lista::altaFinal( int dato ){

	/* Creo el registro donde se guarda el dato */
	Nodo* nuevo = new Nodo( dato );

	if ( this->listaVacia() ){

		/* Asigno el registro como el primer elemento de la lista*/
		this->primero = nuevo;

		/* Contabilizo el agregado en la lista */
		this->cantidadDeElementos++;
	}
	else{

		/* Avanzo en la lista hasta el �ltimo registro */
		Nodo* ultimaPosicion = this->recorrerLista( this->cantidadDeElementos );

		/* Agrego el nuevo registro al final de la lista */
		ultimaPosicion->setSiguiente( nuevo );

		/* Contabilizo el agregado en la lista */
		this->cantidadDeElementos++;
	}
}

bool Lista::buscarDato( int datoBuscado){

	Nodo* actual = this->primero;

	bool encontrado = NO_ENCONTRADO;

	while ( !encontrado && actual ){

		if ( actual->getDato() == datoBuscado ){

			encontrado = HAY_COINCIDENCIA;
		}

		actual = actual->getSiguiente();
	}

	return encontrado;
}

bool Lista::listaVacia(){

	return this->primero == nullptr;
}

void Lista::mostrar(){

	/* Me posiciono en el primer elemento de la lista */
	Nodo* actual = this->primero;

	std::cout << "{ ";

	/* Mientras haya elementos los muestro por pantalla */
	while ( actual ){

		std :: cout << actual->getDato() << ", ";

		/* Me posiciono en el siguiente elemento de la lista */
		actual = actual->getSiguiente();
	}

	std::cout << " }" << std::endl; ;
}

/* ----------------    PRIVADOS   --------------------  */

Nodo* Lista::recorrerLista ( int posicion ){

	/* Verifico que la posici�n ingresada exista en la lista */
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
		posicionActual++;
	}

	/* Devuelvo el elemento buscado */
	return actual;
}



bool Lista::fueraDeRango( int posicion ){

	return ( posicion > this->cantidadDeElementos ) ||
				( posicion < PRIMER_ELEMENTO );
}
