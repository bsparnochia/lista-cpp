/*
 * main.cpp
 *
 *  Created on: 22 may. 2020
 *      Author: brian
 */
#include "Lista.h"

int main(){

	Lista* lista = new Lista();

	/* alta final */

	lista->altaFinal(1);
	lista->altaFinal(5);
	lista->altaFinal(4);

	/* alta principio */

	lista->altaPrincipio(9);
	lista->altaPrincipio(57);

	lista->mostrar();

	delete lista;

	return 0;
}


