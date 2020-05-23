/*
 * main.cpp
 *
 *  Created on: 22 may. 2020
 *      Author: brian
 */
#include "Lista.h"

int main(){

	Lista* lista = new Lista();

	lista->altaFinal(1);
	lista->altaFinal(5);
	lista->altaFinal(4);

	lista->mostrar();

	delete lista;

	return 0;
}


