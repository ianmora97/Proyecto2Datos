#pragma once

#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <stack> 
#include <iostream>
#include <algorithm>
#include <cctype>

//el numero maximo de linea de codigo por archivo
#define LINEAS_MAX 15 

#include "PalabraReservada.h"

class TablaSimbolos{
public:
	TablaSimbolos();
	~TablaSimbolos();

	void initVectores();

	int hashf(std::string id);

	std::string buscar(std::string id);

	void recuperarDesdeArchivo(std::string ruta);
	std::string toString();
	std::string imprimirCodigo();

	bool declaracionInvalida(PalabraReservada);
	
	void insertarFuncionMap(PalabraReservada);
	void insertarVariableMap(PalabraReservada);
	void leerString(std::string linea);

	void paramentros(std::string s);

	bool comparar(char l);

	bool compararFunc(std::string l);

private:
	std::unordered_map<std::string, PalabraReservada> funcionesMap;
	std::unordered_map<std::string, PalabraReservada> variablesMap;
	std::vector<std::string> codigo;
	std::stack<PalabraReservada> funciones;
	std::stack<PalabraReservada> variables;
	std::vector<char> operadores;
	std::vector<std::string> func;
};
