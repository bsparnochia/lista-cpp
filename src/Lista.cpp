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

	/* recorre la lista si contiene registros */
	while ( !this->listaVacia() ){

		/* guardo el registro siguiente */
		Nodo* siguiente = this->primero->getSiguiente();

		/* elimino el registro actual */
		delete this->primero;
		this->cantidadDeElementos--;

		/* el registro siguiente ahora es el actual a eliminar */
		this->primero = siguiente;
	}

}

void Lista::altaPrincipio( int dato ){

	Nodo* nuevo = new Nodo( dato );

	/* Verifico si existe un primer elemento en al lista */
	if ( this->primero ){

		nuevo->setSiguiente( this->primero );
	}

	this->primero = nuevo;
	this->cantidadDeElementos++;
}

void Lista::altaFinal( int dato ){

	/* Creo el registro donde se guarda el dato */
	Nodo* nuevo = new Nodo( dato );

	if ( this->listaVacia() ){

		/* Asigno el registro como el primer elemento de la lista*/
		this->primero = nuevo;
	}
	else{

		/* Avanzo en la lista hasta el �ltimo registro */
		Nodo* ultimaPosicion = this->recorrerLista( this->cantidadDeElementos );

		/* Agrego el nuevo registro al final de la lista */
		ultimaPosicion->setSiguiente( nuevo );

	}

	/* Contabilizo el agregado en la lista */
	this->cantidadDeElementos++;
}

void Lista::altaEnPosicion( int dato, int posicionBuscada ){

	if ( agregadoFueraDeRango(posicionBuscada) ){

		throw std::string (" Posicion inexistente en la lista ");
	}

	Nodo* nuevo = new Nodo(dato);

	int posicionActual = PRIMER_ELEMENTO;

	Nodo* actual = this->primero;
	Nodo* anterior = this->primero;

	while ( posicionActual < posicionBuscada ){

		anterior = actual;
		actual = actual->getSiguiente();
		posicionActual++;
	}

	/* corro el elemento actual de la posicion buscada a la siguiente */
	nuevo->setSiguiente( actual);

	if( actual == this->primero ){

		this->primero = nuevo;
	}
	/* si no es la primera posición, su siguiente sera el nuevo elemento */
	else{

		anterior->setSiguiente(nuevo);
	}

	this->cantidadDeElementos++;

}

void Lista::eliminarDato( int datoBuscado ){

	Nodo* actual = this->primero;
	Nodo* anterior = this->primero;

	while ( actual ){

		/* guardo el siguiente para seguir buscando coincidencias */
		Nodo* siguiente = actual->getSiguiente();

		/* verifico si el elemento actual es el buscado */
		if ( actual->getDato() == datoBuscado){

			if ( actual == this->primero ){

				/* el primero y el anterior ahora son el siguiente */
				this->primero = siguiente;
				anterior = siguiente;
			}
			else{

				/* conecto el anterior del actual con su siguiente */
				anterior->setSiguiente( siguiente );
			}

			/* elimino el elemento y apunto al siguiente de la lista */
			delete actual;
			actual = siguiente;

			/* Descuento el elemento del contador */
			this->cantidadDeElementos--;
		}
		/* si no hay coincidencia solo corro los punteros a sus correspondientes siguientes */
		else{

			anterior = actual;
			actual = siguiente;
		}
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

	std::cout <<"Cantidad de elementos de la lista : " << this->cantidadDeElementos << std:: endl;
}

/* ----------------    PRIVADOS   --------------------  */

Nodo* Lista::recorrerLista ( int posicion ){

	/* Verifico que la posici�n ingresada exista en la lista */
	if ( this->recorridoFueraDeRango ( posicion ) ){

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



bool Lista::recorridoFueraDeRango( int posicion ){

	return ( posicion > this->cantidadDeElementos ) ||
				( posicion < PRIMER_ELEMENTO );
}

bool Lista::agregadoFueraDeRango( int posicion ){

	/* se aumenta en 1 la cantidad de elementos para
	 * permitir agregar al final de la lista un nuevo elemento
	 */
	return ( posicion > this->cantidadDeElementos + 1 ) ||
				( posicion < PRIMER_ELEMENTO );
}
