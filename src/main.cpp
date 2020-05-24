/*
 * main.cpp
 *
 *  Created on: 22 may. 2020
 *      Author: brian
 */
#include <iostream>
#include "Lista.h"

int main(){

	Lista* lista = new Lista();
	int buscado = 57;

	std::cout << "alta final \n" << std::endl;

	lista->altaFinal(1);
	lista->altaFinal(5);
	lista->altaFinal(4);
	lista->altaFinal(5);
	lista->altaFinal(8);
	lista->altaFinal(5);

	lista->mostrar();

	std::cout << "\n alta principio \n" << std::endl;

	lista->altaPrincipio(9);
	lista->altaPrincipio(57);
	lista->altaPrincipio(9);

	lista->mostrar();

	//std::cout << "\n Borrar coincidencias donde hay un " << buscado << " \n" << std::endl;

	//lista->eliminarDato(buscado);

	//lista->mostrar();

	std::cout << "\n buscar " << buscado << " \n" << std::endl;

	if ( lista->buscarDato(buscado) ){

		std::cout << " se encontro el elemento en la lista " << std::endl;
	}
	else{

		std::cout << " no existe el elemento en la lista " << std::endl;
	}



	delete lista;

	return 0;
}


