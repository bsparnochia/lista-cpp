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
	 * Crea una lista vacía
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
	 * Agrega el dato en la posición de la lista indicada por parámetro
	 */
	void altaEnPosicion( int dato, int posicion );

	/*
	 * Elimina todos los registros que contengan el dato indicado por parámetro
	 */
	void eliminarDato( int dato );

	/*
	 * Indica si el elemento indicado existe en la lista
	 */
	bool buscarDato( int dato );

	/*
	 * Emite por pantalla el contenido de la lista
	 */
	void mostrar();


private:

	Nodo *primero;
	int cantidadDeElementos;
};

#endif /* LISTA_H_ */
