//main.cpp
//Autores: Ian Mora Rodrígues Ced. 116890118
//         Iván Chinchilla Cordoba Ced. 116730818
//		   Nancy Maroto Araya Ced. 402130446
//Descripcion: Funcion main donde se generan y muestran las Tablas de Simbolos
//			   a base de archivos previamente otorgados

#include "TablaSimbolos.h"

int main() {

	SetConsoleTitleA("Tabla de Simbolos - Segundo Proyecto de Estructuras de Datos");

	TablaSimbolos tabla;
	TablaSimbolos tabla2;
	TablaSimbolos tabla3;
	TablaSimbolos tabla4;
	TablaSimbolos tabla5;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "CODIGO RECUPERADO (funcion1.txt)\n\n";
	tabla.recuperarDesdeArchivo("funcion1.txt");
	std::cout << tabla.imprimirCodigo();
	tabla.mostrarErrores();
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
	tabla2.mostrarErrores();
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

	std::cout << "\n\nCODIGO RECUPERADO (funcion3.txt)\n\n";
	tabla3.recuperarDesdeArchivo("funcion3.txt");
	std::cout << tabla3.imprimirCodigo();
	tabla3.mostrarErrores();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "\n";
	std::cout << "TABLA DE SIMBOLOS (Tabla 3)\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << " | " << std::setw(10) << "TIPO" << " | ";
	std::cout << std::setw(10) << "ID" << " | ";
	std::cout << std::setw(10) << "NOMBRE" << " | ";
	std::cout << std::setw(10) << "PADRE" << " | ";
	std::cout << std::setw(10) << "VALOR" << " |";
	std::cout << std::setw(10) << "HASH_KEY" << "\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << tabla3.toString();
	std::cout << " +----------------------------------------------------------------+\n";

	std::cout << "\n\nCODIGO RECUPERADO (funcion4.txt)\n\n";
	tabla4.recuperarDesdeArchivo("funcion4.txt");
	std::cout << tabla4.imprimirCodigo();
	tabla4.mostrarErrores();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "\n";
	std::cout << "TABLA DE SIMBOLOS (Tabla 4)\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << " | " << std::setw(10) << "TIPO" << " | ";
	std::cout << std::setw(10) << "ID" << " | ";
	std::cout << std::setw(10) << "NOMBRE" << " | ";
	std::cout << std::setw(10) << "PADRE" << " | ";
	std::cout << std::setw(10) << "VALOR" << " |";
	std::cout << std::setw(10) << "HASH_KEY" << "\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << tabla4.toString();
	std::cout << " +----------------------------------------------------------------+\n\n";

	std::cout << "\n\nCODIGO RECUPERADO (funcion5.txt)\n\n";
	tabla5.recuperarDesdeArchivo("funcion5.txt");
	std::cout << tabla5.imprimirCodigo();
	tabla5.mostrarErrores();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "\n";
	std::cout << "TABLA DE SIMBOLOS (Tabla 5)\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << " | " << std::setw(10) << "TIPO" << " | ";
	std::cout << std::setw(10) << "ID" << " | ";
	std::cout << std::setw(10) << "NOMBRE" << " | ";
	std::cout << std::setw(10) << "PADRE" << " | ";
	std::cout << std::setw(10) << "VALOR" << " |";
	std::cout << std::setw(10) << "HASH_KEY" << "\n";
	std::cout << " +----------------------------------------------------------------+\n";
	std::cout << tabla5.toString();
	std::cout << " +----------------------------------------------------------------+\n\n";

	system("pause");
	return 0;
}