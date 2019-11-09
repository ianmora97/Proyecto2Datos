#pragma once

#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <stack> 
#include <iostream>
#include <algorithm>
#include <cctype>

#include "PalabraReservada.h"

class TablaSimbolos{
public:
	TablaSimbolos();
	~TablaSimbolos();

	void initVectores();

	void recuperarDesdeArchivo(std::string ruta);
	std::string imprimirCodigo();

	void llenarStatments(std::string);

	void funcionHash(std::string, int);

	void leerString(std::string linea);

	void paramentros(std::string s);

	bool comparar(char l);

	bool compararFunc(std::string l);

	void crearTablaSimbolos();

	

private:
	std::unordered_map<std::string, std::string> hashtable;
	std::vector<std::string> codigo;
	std::stack<PalabraReservada> funciones;
	std::stack<PalabraReservada> variables;
	std::vector<char> operadores;
	std::vector<std::string> func;
};
