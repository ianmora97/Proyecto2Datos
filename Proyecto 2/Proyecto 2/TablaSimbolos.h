#pragma once

#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <stack> 
#include <iostream>

#include "PalabraReservada.h"

class TablaSimbolos{
public:
	TablaSimbolos();
	~TablaSimbolos();

	void recuperarDesdeArchivo(std::string ruta);
	std::string imprimirCodigo();

	void llenarStatments(std::string);

	void funcionHash(std::string, int);

	void crearTablaSimbolos();

private:
	std::unordered_map<std::string, std::string> hashtable;
	std::vector<std::string> codigo;
	std::vector<std::string> staments;
	std::stack<PalabraReservada> funciones;
	std::stack<PalabraReservada> variables;
};
