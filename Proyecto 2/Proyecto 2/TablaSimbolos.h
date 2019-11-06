#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <fstream>

class TablaSimbolos{
public:
	TablaSimbolos();
	~TablaSimbolos();

	void recuperarDesdeArchivo(std::string ruta);
	std::string imprimirCodigo();

private:
	//std::unordered_map<std::string, > hashtable;
	std::vector<std::string> funcion;
};
