#include "TablaSimbolos.h"

TablaSimbolos::TablaSimbolos(){
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