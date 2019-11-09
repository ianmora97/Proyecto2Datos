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
		codigo.push_back(lineaCodigo);
	}

	entrada.close();

}

std::string TablaSimbolos::imprimirCodigo() {
	std::stringstream s;

	int i = 0;
	while (i < codigo.size() - 1) {
		s << codigo[i] << "\n";
		i++;
	}

	return s.str();
}

void TablaSimbolos::llenarStatments(std::string ruta){

	std::string lineaCodigo;

	std::ifstream entrada;
	entrada.open(ruta);

	while (!entrada.fail()) {
		getline(entrada, lineaCodigo, ' ');
		staments.push_back(lineaCodigo);
	}

	entrada.close();

}

void TablaSimbolos::funcionHash(std::string, int){

}

void TablaSimbolos::crearTablaSimbolos(){
	for (int i = 0; i < codigo.size() - 1; i++) {

		if (codigo[i] != "") {

			std::string lineaCodigo = codigo[i];
			std::string identificador;
			std::string nombre;



		}

	}
}
