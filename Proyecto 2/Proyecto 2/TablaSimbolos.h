#pragma once

#include "PalabraReservada.h"

//el numero maximo de linea de codigo por archivo
#define LINEAS_MAX 25 

struct ExceptionE {
	ExceptionE(std::string s, int v)
		:s(s), v(v){}
	std::string s;
	int v;
};


class TablaSimbolos{
public:
	TablaSimbolos();
	~TablaSimbolos();

	void initVectores();

	int hashf(std::string id);

	PalabraReservada& buscarVar(std::string id);

	PalabraReservada buscarFunc(std::string id);

	bool check_key(std::string e);

	void recuperarDesdeArchivo(std::string ruta);
	std::string toString();
	std::string imprimirCodigo();

	std::string mostrarErrores();

	
	void insertarFuncionMap(PalabraReservada);
	void insertarVariableMap(PalabraReservada);
	void leerString(std::string linea);

	void paramentros(std::string s);

	bool comparar(char l);

	bool compararFunc(std::string l);

private:
	std::unordered_map<int, PalabraReservada> funcionesMap;
	std::unordered_map<int, PalabraReservada> variablesMap;
	std::vector<std::string> codigo;

	std::stack<PalabraReservada> funciones;
	std::stack<PalabraReservada> variables;

	std::stack<PalabraReservada> funcionesImprimir;

	std::vector<char> operadores;
	std::vector<std::string> func;

	std::vector<std::string> cerr;
	int lineaCodigoActual = 1;
};
