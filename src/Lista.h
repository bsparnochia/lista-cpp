/*
 * Lista.h
 *
 *  Created on: 22 may. 2020
 *      Author: brian
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"

class Lista {

public:

	/*
	 * Crea una lista vac�a
	 */
	Lista();

	/*
	 * Elimina la lista
	 */
	~Lista();

	/*
	 * Agrega el registro al principio de la lista
	 */
	void altaPrincipio( int dato );

	/*
	 * Agrega el registro al final de la lista
	 */
	void altaFinal( int dato );

	/*
	 * Agrega el dato en la posici�n de la lista indicada por par�metro
	 */
	void altaEnPosicion( int dato, int posicion );

	/*
	 * Elimina todos los registros que contengan el dato indicado por par�metro
	 */
	void eliminarDato( int dato );

	/*
	 * Indica si el elemento indicado existe en la lista
	 */
	bool buscarDato( int dato );

	/*
	 * Indica si la lista no tiene elementos
	 */
	bool listaVacia();

	/*
	 * Emite por pantalla el contenido de la lista
	 */
	void mostrar();


private:

	Nodo *primero;
	int cantidadDeElementos;

	/* Devuelve el registro de la posici�n indicada */
	Nodo* recorrerLista( int posicion);

	/*
	 * Post: Indica si la posicion no corresponde a ninguna
	 * 		 ubicaci�n de la lista
	 */
	bool fueraDeRango( int posicion );
};

#endif /* LISTA_H_ */
