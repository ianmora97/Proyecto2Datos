#include "TablaSimbolos.h"

TablaSimbolos::TablaSimbolos(){
	initVectores();
}

TablaSimbolos::~TablaSimbolos(){
}
void TablaSimbolos::initVectores() {
	//operadores
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
	//palabras reservadas
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
//-------------Metodos----------------
int TablaSimbolos::hashf(std::string id){
	int numeroASCII = 0;

	for (int i = 0; i < id.length(); i++) {
		numeroASCII = numeroASCII + id[i];
	}
	return (numeroASCII % LINEAS_MAX);
}

std::string TablaSimbolos::buscar(std::string id){
	int index = hashf(id);
	/*
	for (auto registro : hashtable) {
		std::cout << registro.first << "\t" << registro.second.getNombre()
			<< "\t" << registro.second.getEdad() << "\n" ;
	}
	*/

	return "-1"; 
}
void TablaSimbolos::insertarFuncionMap(PalabraReservada pr) {
	auto palabra = std::make_pair(pr.getNombre(), pr);
	funcionesMap.insert(palabra);

}
void TablaSimbolos::insertarVariableMap(PalabraReservada pr) {
	auto palabra = std::make_pair(pr.getNombre(), pr);
	variablesMap.insert(palabra);
}
//-------------Metodos----------------!
void TablaSimbolos::recuperarDesdeArchivo(std::string ruta){
	std::string lineaCodigo;

	std::ifstream entrada;
	entrada.open(ruta);

	if (!entrada.fail()) {
		while (!entrada.eof()) {
			getline(entrada, lineaCodigo, '\n');
			codigo.push_back(lineaCodigo);
			if (lineaCodigo != "") {
				lineaCodigo.erase(std::remove(lineaCodigo.begin(), lineaCodigo.end(), '\t'), lineaCodigo.end());
				leerString(lineaCodigo);
			}

		}
	}

	entrada.close();

}

std::string TablaSimbolos::toString() {
	std::stack<PalabraReservada> pila;

	std::stringstream s;

	int tam;

	s << "Funciones: \n\n";

	tam = funciones.size();
	for (int i = 0; i < tam; i++) {
		pila.push(funciones.top());
		s << funciones.top().toString();
		funciones.pop();
		s << "\n";
	}

	tam = pila.size();
	for (int i = 0; i < tam; i++) {
		funciones.push(pila.top());
		pila.pop();
	}

	s << "\nVariables: \n\n";

	tam = variables.size();
	for (int i = 0; i < tam; i++) {
		pila.push(variables.top());
		s << variables.top().toString();
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

std::string TablaSimbolos::imprimirCodigo() {
	std::stringstream s;

	int i = 0;
	while (i < codigo.size()) {
		s << codigo[i] << "\n";
		i++;
	}

	return s.str();
}
bool TablaSimbolos::declaracionInvalida(PalabraReservada p) {

	return true;
}


void TablaSimbolos::leerString(std::string linea) {
	std::stack<std::string> pila;
	std::vector<std::string> staments;
	std::string statement;
	for (int i = 0; i < linea.size(); i++) {
		
		try{		
			if (linea[i] != ' ' && linea[i] != '(' && linea[i] != '=' && linea[i] != ';') { //creo el statement
				statement += linea[i];
			}
			else if (linea[i] == '(' && statement != "if") { //capturo los parametros de la funcion
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
					i+=2;
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
				variables.push(pr);
				insertarVariableMap(pr);
			}
			else if (linea[i] == '=' && staments.size() != 2) { //variables
				std::string e = pila.top();

				
				throw - 1;
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
				pr.setNombre(statement);
				pr.setPadre(funciones.top().getNombre());
				pr.setTipo("if");
				funciones.push(pr);
				statement = "";
				insertarFuncionMap(pr);
			}
			else {
				staments.push_back(statement);
				statement = "";
			}
			
		}
		catch (int e){
			switch (e){
			case 1:
				std::cerr << "Error de lectura";
				break;
			default:
				break;
			}
		}
	}
}
void TablaSimbolos::paramentros(std::string s) {
	std::vector<std::string> staments;
	std::string lectura;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ' && s[i] != ',' && s[i] != ')') {
			lectura += s[i];
		}
		else if (s[i] == ' ' && s[i-1] == ',') {
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
bool TablaSimbolos::comparar(char l) {
	for (int i = 0; i < operadores.size(); i++) {
		if (operadores[i] == l) {
			return true;
		}
	}
	return false;
}

bool TablaSimbolos::compararFunc(std::string l) {
	for (int i = 0; i < func.size(); i++) {
		if (func[i] == l) {
			return true;
		}
	}
	return false;
}

