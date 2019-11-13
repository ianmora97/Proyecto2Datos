
#include <iostream>
#include "TablaSimbolos.h"

int main() {

	TablaSimbolos tabla;
	TablaSimbolos tabla2;

	std::cout << "CODIGO RECUPERADO\n\n";
	tabla.recuperarDesdeArchivo("funcion1.txt");
	std::cout << tabla.imprimirCodigo();
	std::cout << "\n";
	std::cout << "TABLA DE SIMBOLOS\n";
	std::cout << " ------------------------------------------------------------------\n";
	std::cout << " | " << std::setw(10) << "TIPO" << " | ";
	std::cout << std::setw(10) << "ID" << " | ";
	std::cout << std::setw(10) << "NOMBRE" << " | ";
	std::cout << std::setw(10) << "PADRE" << " | ";
	std::cout << std::setw(10) << "VALOR" << " |\n";
	std::cout << " ------------------------------------------------------------------\n";
	std::cout << tabla.toString();
	std::cout << " ------------------------------------------------------------------\n";

	//tabla2.recuperarDesdeArchivo("funcion2.txt");
	//std::cout << tabla2.imprimirCodigo();
	//<<
	//"-------------------------------------\n";
	//std::cout << "\nFuncion 2:\n";
	//    "-------------------------------------\n";
	//std::cout << tabla2.imprimirCodigo() <<
	//    "-------------------------------------\n";

	system("pause");
	return 0;
}