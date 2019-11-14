//TablaSimbolos.cpp
//Autores: Ian Mora Rodrígues Ced. 116890118
//         Iván Chinchilla Cordoba Ced. 116730818
//		   Nancy Maroto Araya Ced. 402130446
//Descripcion: Implementacion de los metodos declarados en el 
//             archivo de cabecera "TablaSimbolos.h"

#include "TablaSimbolos.h"

TablaSimbolos::TablaSimbolos() {
	initVectores();
}

TablaSimbolos::~TablaSimbolos() {
}

//-------------Metodos basicos para leer y crear la tabla de simbolos----------------!

//Se llenan los vectores con los elementos propios del lenguaje
void TablaSimbolos::initVectores() {

	//Operadores
	operadores.push_back(' ');
	operadores.push_back('(');
	operadores.push_back(')');
	operadores.push_back('{');
	operadores.push_back('}');
	operadores.push_back('[');
	operadores.push_back(']');
	operadores.push_back(';');
	operadores.push_back('=');
	operadores.push_back('+');
	operadores.push_back('-');
	operadores.push_back('/');
	operadores.push_back('*');
	operadores.push_back(':');
	operadores.push_back(',');
	operadores.push_back('.');
	operadores.push_back('!');
	operadores.push_back('<');
	operadores.push_back('>');
	operadores.push_back('\'');
	operadores.push_back('"');

	//Palabras reservadas
	func.push_back("void");
	func.push_back("if");
	func.push_back("while");
	func.push_back("for");
	func.push_back("int");
	func.push_back("float");
	func.push_back("char");
	func.push_back("string");
	func.push_back("bool");

}

//Funcion hash para crear keys
int TablaSimbolos::hashf(std::string id) {
	unsigned int valor = 0;
	for (int i = 0; i < id.length(); i++)
		valor = valor + id[i];
	return (valor % LINEAS_MAX);
}

//Se recupera el codigo desde un archivo y se crea la tabla de simbolos
void TablaSimbolos::recuperarDesdeArchivo(std::string ruta) {
	std::string lineaCodigo;
	std::string errors;
	std::ifstream entrada;
	entrada.open(ruta);
	try {
		if (!entrada.fail()) {
			while (!entrada.eof()) {
				getline(entrada, lineaCodigo, '\n');
				codigo.push_back(lineaCodigo);
				if (lineaCodigo != "") {
					lineaCodigo.erase(std::remove(lineaCodigo.begin(), lineaCodigo.end(), '\t'), lineaCodigo.end());
					leerString(lineaCodigo);
				}
				lineaCodigoActual++;
			}
		}
		else {
			ExceptionE e("ARCHIVO NO ENCONTRADO", 0);
			throw e;
		}
	}
	catch (ExceptionE e) {
		switch (e.v) {
		case 0:
			cerr.push_back(e.s);
			break;
		default:
			break;
		}
	}

	entrada.close();

}

//-------------Metodos propios de la tabla de simbolos----------------!

//Busca y recupera en hash table de variables un elemento
PalabraReservada& TablaSimbolos::buscarVar(std::string id) { //buscar en variables
	return variablesMap[hashf(id)];
}

//Busca y recupera en hash table de funciones un elemento
PalabraReservada TablaSimbolos::buscarFunc(std::string id) { //buscar en funciones
	return funcionesMap[hashf(id)];
}

//Inserta un elemento en la hash table de funciones
void TablaSimbolos::insertarFuncionMap(PalabraReservada pr) {
	int hash = hashf(pr.getNombre());
	auto palabra = std::make_pair(hash, pr);
	funcionesMap.insert(palabra);
}

//Inserta un elemento en la hash table de variables
void TablaSimbolos::insertarVariableMap(PalabraReservada pr) {
	int hash = hashf(pr.getNombre());
	auto palabra = std::make_pair(hash, pr);
	variablesMap.insert(palabra);
}

//Modifica los atributos de un elemento en la hash table de funciones
void TablaSimbolos::modificarAtributosFuncionMap(std::string nombre, std::string tipo, std::string ID, std::string padre, std::string valor) {
	try {
		if (existeFunc(nombre)) {

			PalabraReservada pr = funcionesMap[hashf(nombre)];

			pr.setTipo(tipo);
			pr.setID(ID);
			pr.setPadre(padre);
			pr.setValor(valor);

			std::cout << "Se ha modificado el elemento exitosamente\n";
			std::cout << pr.imprimirAtributos();
		}
		else {
			throw - 1;
		}
	}
	catch (int e) {
		std::cout << "No se ha encontrado el elemento\n";
	}
}

//Modifica los atributos de un elemento en la hash table de variables
void TablaSimbolos::modificarAtributosVariableMap(std::string nombre, std::string tipo, std::string ID, std::string padre, std::string valor) {
	try {
		if (existeVar(nombre)) {

			PalabraReservada pr = variablesMap[hashf(nombre)];

			pr.setTipo(tipo);
			pr.setID(ID);
			pr.setPadre(padre);
			pr.setValor(valor);

			std::cout << "Se ha modificado el elemento exitosamente\n";
			std::cout << pr.imprimirAtributos();
		}
		else {
			throw - 1;
		}
	}
	catch (int e) {
		std::cout << "No se ha encontrado el elemento\n";
	}
}

//Elimina un elemento en la hash table de funciones
void TablaSimbolos::borrarFuncionMap(std::string id) {
	try {
		if (existeFunc(id)) {
			funcionesMap.erase(hashf(id));
			std::cout << "Se ha borrado el elemento exitosamente\n";
		}
		else {
			throw - 1;
		}
	}
	catch (int e) {
		std::cout << "No se ha podido borrar el elemento\n";
	}
}

//Elimina un elemento en la hash table de variables
void TablaSimbolos::borrarVariableMap(std::string id) {
	try {
		if (existeVar(id)) {
			variablesMap.erase(hashf(id));
			std::cout << "Se ha borrado el elemento exitosamente\n";
		}
		else {
			throw - 1;
		}
	}
	catch (int e) {
		std::cout << "No se ha podido borrar el elemento\n";
	}
}

//Obtiene los atributos de un elemento en la hash table de funciones
std::string TablaSimbolos::obtenerAtributosFuncionMap(std::string id) {
	std::stringstream s;

	PalabraReservada pr = funcionesMap[hashf(id)];

	s << "Los atributos son los siguientes: \n";
	s << pr.imprimirAtributos();

	return s.str();
}

//Obtiene los atributos de un elemento en la hash table de variables
std::string TablaSimbolos::obtenerAtributosVariableMap(std::string id) {
	std::stringstream s;

	PalabraReservada pr = variablesMap[hashf(id)];

	s << "Los atributos son los siguientes: \n";
	s << pr.imprimirAtributos();

	return s.str();
}

//-------------Metodos auxliares que ayudan a la construccion de la tabla de simbolos-------------!

//Lee una parte de la linea del codigo y crea las Palabras Reservadas (metodos y funciones)
void TablaSimbolos::leerString(std::string linea) {
	std::stack<std::string> pila;
	std::vector<std::string> staments;
	std::string statement;
	for (int i = 0; i < linea.size(); i++) {
		if (linea[i] != ' ' && linea[i] != '(' && linea[i] != '=' && linea[i] != ';' && linea[i] != '}') { //creo el statement
			statement += linea[i];
		}
		else if (linea[i] == '}') {
			funciones.pop();
		}
		else if (linea[i] == '(' && statement != "if" && statement != "while") { //capturo los parametros de la funcion
			statement = "";
			pila.push("(");
			i++;
			while (!pila.empty()) {
				if (linea[i] == ')') {
					pila.pop();
				}
				statement += linea[i];
				i++;
			}
			i--;
			if (statement != ")") {
				paramentros(statement);
			}
			statement = "";
		}
		else if (linea[i] == '=' && staments.size() == 2) { //variables
			PalabraReservada pr;
			if (funciones.empty()) {
				pr.setID("variable");
				pr.setNombre(staments[1]);
				pr.setTipo(staments[0]);
				pr.setPadre("main");
				statement = "";
				pila.push("(");
				i += 2;
				while (!pila.empty()) {
					statement += linea[i];
					i++;
					if (linea[i] == ';') {
						pila.pop();
					}
				}
				i--;
				pr.setValor(statement);
			}
			else {
				pr.setID("variable");
				pr.setNombre(staments[1]);
				pr.setTipo(staments[0]);
				pr.setPadre(funciones.top().getPadre());
				statement = "";
				pila.push("(");
				i++;
				while (!pila.empty()) {
					if (linea[i] == ';') {
						pila.pop();
					}
					statement += linea[i];
					i++;
				}
				i--;
				pr.setValor(statement);
			}
			if (existeVar(pr.getNombre())) {
				std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) + ": La variable '" + pr.getNombre() + "' ya esta Declarada";
				cerr.push_back(se);
			}
			else {
				variables.push(pr);
				insertarVariableMap(pr);
			}

		}
		else if (linea[i] == '=' && staments.size() != 2) { //asignacion de una variable
			std::string e = staments.front();
			//buscar un elemento y asignarlo

			statement = "";
			pila.push("(");
			i++;
			while (!pila.empty()) {
				statement += linea[i];
				i++;
				if (linea[i] == ';') {
					pila.pop();
				}
			}
			if (!existeVar(e)) {
				ExceptionE ex(e, 1);
				std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) + ": '" + e + "' no esta Declarado";
				cerr.push_back(se);
			}
			else {
				variablesMap[hashf(e)].setValor(statement);
			}
		}
		else if (statement == "void") {
			PalabraReservada pr;
			pr.setID("funcion");

			statement = "";
			pila.push("(");
			i++;
			while (!pila.empty()) {
				if (linea[i] == '(') {
					pila.pop();
				}
				if (linea[i] != '(') {
					statement += linea[i];
					i++;
				}
			}
			i--;
			pr.setNombre(statement);
			pr.setPadre("main");
			pr.setTipo("void");
			funciones.push(pr);
			funcionesImprimir.push(pr);
			statement = "";

			insertarFuncionMap(pr);
		}
		else if (statement == "while") {
			PalabraReservada pr;
			pr.setID("statement");

			statement = "";
			i++;
			pila.push("(");
			while (!pila.empty()) {
				if (linea[i] == ')') {
					pila.pop();
				}
				if (linea[i] != ')') {
					statement += linea[i];
					i++;
				}
			}
			i--;
			pr.setNombre("while");
			pr.setPadre(funciones.top().getNombre());
			pr.setTipo("while");
			pr.setValor(statement);
			funciones.push(pr);
			funcionesImprimir.push(pr);
			statement = "";
			insertarFuncionMap(pr);
		}
		else if (statement == "if") {
			PalabraReservada pr;
			pr.setID("statement");

			statement = "";
			i++;
			pila.push("(");
			while (!pila.empty()) {
				if (linea[i] == ')') {
					pila.pop();
				}
				if (linea[i] != ')') {
					statement += linea[i];
					i++;
				}
			}
			i--;
			pr.setNombre("if");
			pr.setPadre(funciones.top().getNombre());
			pr.setTipo("if");
			pr.setValor(statement);
			funciones.push(pr);
			funcionesImprimir.push(pr);
			statement = "";
			insertarFuncionMap(pr);
		}
		else if (statement == "return") {
			if (funciones.size() != 0) {
				statement = "";
				i++;
				pila.push("(");
				while (!pila.empty()) {
					statement += linea[i];
					i++;
					if (linea[i] == ';') {
						pila.pop();
					}
				}
				if (existeVar(statement)) {
					PalabraReservada pr = variablesMap[hashf(statement)];
					PalabraReservada padre = funcionesMap[hashf(pr.getPadre())];
					if ((padre.getTipo() == "void")) {
						std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) +
							": void no retorna nada";
						cerr.push_back(se);
					}
					else if ((padre.getTipo() != pr.getTipo()) && (pr.getTipo() != funciones.top().getTipo())) {
						std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) +
							": el valor de retorno no coincide con la declaracion de '" + padre.getNombre() + "'";
						cerr.push_back(se);
					}
					else if ((pr.getTipo() != funciones.top().getTipo())) {
						std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) +
							": el valor de retorno no coincide con la declaracion de '" + funciones.top().getNombre() + "'";
						cerr.push_back(se);
					}
				}
			}
			else {
				std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) +
					": return sin funcion";
				cerr.push_back(se);
			}

		}
		else if (statement == "int") {
			bool flag = true;
			statement = "";
			pila.push("(");
			int j = i;
			j++;
			while (!pila.empty()) {
				if (linea[j] != '=' && linea[j] != ' ' && linea[j] != '(') {
					statement += linea[j];
				}
				if (linea[j] == '=') {
					pila.pop();
					flag = false;
				}
				if (linea[j] == '(') {
					pila.pop();
					flag = true;
				}
				j++;
			}

			if (flag) {
				PalabraReservada pr;
				pr.setID("funcion");
				pr.setNombre(statement);
				pr.setPadre("main");
				pr.setTipo("int");
				funciones.push(pr);
				funcionesImprimir.push(pr);
				statement = "";
				insertarFuncionMap(pr);
			}
			else {
				staments.push_back("int");
				statement = "";
			}
		}
		else if (statement == "float") {
			bool flag = true;
			statement = "";
			pila.push("(");
			int j = i;
			j++;
			while (!pila.empty()) {
				if (linea[j] != '=' && linea[j] != ' ' && linea[j] != '(') {
					statement += linea[j];
				}
				if (linea[j] == '=') {
					pila.pop();
					flag = false;
				}
				if (linea[j] == '(') {
					pila.pop();
					flag = true;
				}
				j++;
			}

			if (flag) {
				PalabraReservada pr;
				pr.setID("funcion");
				pr.setNombre(statement);
				pr.setPadre("main");
				pr.setTipo("float");
				funciones.push(pr);
				funcionesImprimir.push(pr);
				statement = "";
				insertarFuncionMap(pr);
			}
			else {
				staments.push_back("float");
				statement = "";
			}
		}
		else if (statement == "string") {
			bool flag = true;
			statement = "";
			pila.push("(");
			int j = i;
			j++;
			while (!pila.empty()) {
				if (linea[j] != '=' && linea[j] != ' ' && linea[j] != '(') {
					statement += linea[j];
				}
				if (linea[j] == '=') {
					pila.pop();
					flag = false;
				}
				if (linea[j] == '(') {
					pila.pop();
					flag = true;
				}
				j++;
			}

			if (flag) {
				PalabraReservada pr;
				pr.setID("funcion");
				pr.setNombre(statement);
				pr.setPadre("main");
				pr.setTipo("string");
				funciones.push(pr);
				funcionesImprimir.push(pr);
				statement = "";
				insertarFuncionMap(pr);
			}
			else {
				staments.push_back("string");
				statement = "";
			}
		}

		else {
			staments.push_back(statement);
			statement = "";
		}
	}
}

//Ayudan a identificar y crear las variables propias de los parametros de una funcion
void TablaSimbolos::paramentros(std::string s) {
	std::vector<std::string> staments;
	std::string lectura;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ' && s[i] != ',' && s[i] != ')') {
			lectura += s[i];
		}
		else if (s[i] == ' ' && s[i - 1] == ',') {
			//hola
		}
		else if (s[i] == ',') {
			PalabraReservada pr;
			pr.setID("parametro");
			pr.setNombre(lectura);
			pr.setTipo(staments[0]);
			pr.setPadre(funciones.top().getNombre());
			variables.push(pr);
			staments.pop_back();
			lectura = "";
			insertarVariableMap(pr);
		}
		else if (s[i] == ')') {
			PalabraReservada pr;
			pr.setID("parametro");
			pr.setNombre(lectura);
			pr.setTipo(staments[0]);
			pr.setPadre(funciones.top().getNombre());
			variables.push(pr);
			staments.pop_back();
			lectura = "";
			insertarVariableMap(pr);
		}
		else {
			staments.push_back(lectura);
			lectura = "";

		}
	}
}

//Compara operadores
bool TablaSimbolos::comparar(char l) {
	for (int i = 0; i < operadores.size(); i++) {
		if (operadores[i] == l) {
			return true;
		}
	}
	return false;
}

//Compara palabras reservadas (while, if, float, string, int, void, etc...)
bool TablaSimbolos::compararFunc(std::string l) {
	for (int i = 0; i < func.size(); i++) {
		if (func[i] == l) {
			return true;
		}
	}
	return false;
}

//Revisa si algun elemento ya existe en la hash table de variables
bool TablaSimbolos::existeVar(std::string e) {
	if (variablesMap.find(hashf(e)) == variablesMap.end())
		return false;
	return true;
}

//Revisa si algun elemento ya existe en la hash table de funciones
bool TablaSimbolos::existeFunc(std::string e) {
	if (funcionesMap.find(hashf(e)) == funcionesMap.end())
		return false;
	return true;
}

//-------------Metodos de impresion----------------!

//Imprime la tabla de simbolos
std::string TablaSimbolos::toString() {
	std::stack<PalabraReservada> pila;

	std::stringstream s;

	int tam;

	//s << "Funciones: \n\n";

	tam = funcionesImprimir.size();
	for (int i = 0; i < tam; i++) {
		pila.push(funcionesImprimir.top());
		s << funcionesImprimir.top().toString();
		s << "\t" << hashf(funcionesImprimir.top().getNombre());
		funcionesImprimir.pop();
		s << "\n";
	}

	tam = pila.size();
	for (int i = 0; i < tam; i++) {
		funcionesImprimir.push(pila.top());
		pila.pop();
	}

	//s << "\nVariables: \n\n";

	tam = variables.size();
	for (int i = 0; i < tam; i++) {
		pila.push(variables.top());
		s << variables.top().toString();
		s << "\t" << hashf(variables.top().getNombre());
		variables.pop();
		s << "\n";
	}
	tam = pila.size();
	for (int i = 0; i < tam; i++) {
		variables.push(pila.top());
		pila.pop();
	}

	return s.str();
}

//Imprime el codigo trabajado
std::string TablaSimbolos::imprimirCodigo() {
	std::stringstream s;

	int i = 0;
	while (i < codigo.size()) {
		s << std::setw(2) << i + 1 << " | ";
		s << codigo[i] << "\n";
		i++;
	}
	s << "\n";
	return s.str();
}

//Imprime los errores encontrados
void TablaSimbolos::mostrarErrores() {

	if (!cerr.empty()) {
		for (int i = 0; i < cerr.size(); i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			std::cout << cerr[i] << "\n";
		}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "Compilado correctamente sin errores!\n";
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}