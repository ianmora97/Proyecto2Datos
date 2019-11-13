
#include "TablaSimbolos.h"

int main() {
	SetConsoleTitleA("Tabla de Simbolos - Segundo Proyecto de Estructuras de Datos");
	/*system("mode con: cols=110 lines=40");*/

	TablaSimbolos tabla;
	TablaSimbolos tabla2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "CODIGO RECUPERADO (funcion1.txt)\n\n";
	tabla.recuperarDesdeArchivo("funcion1.txt");
	std::cout << tabla.imprimirCodigo();
	std::cout<<tabla.mostrarErrores();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "\n";
	std::cout << "TABLA DE SIMBOLOS (Tabla 1)\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << " | " << std::setw(10) << "TIPO" << " | ";
	std::cout << std::setw(10) << "ID" << " | ";
	std::cout << std::setw(10) << "NOMBRE" << " | ";
	std::cout << std::setw(10) << "PADRE" << " | ";
	std::cout << std::setw(10) << "VALOR" << " |";
	std::cout << std::setw(10) << "HASH_KEY" << "\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << tabla.toString();
	std::cout << " +----------------------------------------------------------------+\n";

	std::cout << "\n\nCODIGO RECUPERADO (funcion2.txt)\n\n";
	tabla2.recuperarDesdeArchivo("funcion2.txt");
	std::cout << tabla2.imprimirCodigo();
	std::cout << tabla2.mostrarErrores();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "\n";
	std::cout << "TABLA DE SIMBOLOS (Tabla 2)\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << " | " << std::setw(10) << "TIPO" << " | ";
	std::cout << std::setw(10) << "ID" << " | ";
	std::cout << std::setw(10) << "NOMBRE" << " | ";
	std::cout << std::setw(10) << "PADRE" << " | ";
	std::cout << std::setw(10) << "VALOR" << " |";
	std::cout << std::setw(10) << "HASH_KEY" << "\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << tabla2.toString();
	std::cout << " +----------------------------------------------------------------+\n";

	system("pause");
	return 0;
}