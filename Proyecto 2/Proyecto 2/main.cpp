
#include <iostream>
#include "TablaSimbolos.h"

int main() {

	TablaSimbolos tabla;
	TablaSimbolos tabla2;

	tabla.recuperarDesdeArchivo("funcion1.txt");
	std::cout << tabla.imprimirCodigo();

	tabla2.recuperarDesdeArchivo("funcion2.txt");
	std::cout << tabla2.imprimirCodigo();

	//std::cout << "Funcion 1:\n"

	


	tabla.crearTablaSimbolos();
		//<<
		//"-------------------------------------\n";
	//std::cout << "\nFuncion 2:\n";
	//	"-------------------------------------\n";
	//std::cout << tabla2.imprimirCodigo() <<
	//	"-------------------------------------\n";

	system("pause");
	return 0;
}