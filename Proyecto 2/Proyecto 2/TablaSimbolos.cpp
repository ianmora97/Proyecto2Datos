#include "TablaSimbolos.h"

TablaSimbolos::TablaSimbolos(){
	auto tipoDato1 = std::make_pair("void", "TipoDato");
	hashtable.insert(tipoDato1);
	auto tipoDato2 = std::make_pair("int", "TipoDato");
	hashtable.insert(tipoDato2);
	auto tipoDato3 = std::make_pair("float", "TipoDato");
	hashtable.insert(tipoDato3);
	auto tipoDato4 = std::make_pair("string", "TipoDato");
	hashtable.insert(tipoDato4);
	auto sentencia1 = std::make_pair("if", "Sentencia");
	hashtable.insert(sentencia1);
	auto sentencia2 = std::make_pair("while", "Sentencia");
	hashtable.insert(sentencia2);
}

TablaSimbolos::~TablaSimbolos(){
}

void TablaSimbolos::recuperarDesdeArchivo(std::string ruta){
	std::string lineaCodigo;

	std::ifstream entrada;
	entrada.open(ruta);

	while (!entrada.fail()) {
		getline(entrada, lineaCodigo, '\n');
		funcion.push_back(lineaCodigo);
	}

	entrada.close();

}

std::string TablaSimbolos::imprimirCodigo() {
	std::stringstream s;

	int i = 0;
	while (i < funcion.size() - 1) {
		s << funcion[i] << "\n";
		i++;
	}

	return s.str();
}