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
	unsigned int valor = 0;
	for (int i = 0; i < id.length(); i++)
		valor = valor + id[i];
	return (valor % LINEAS_MAX);
}
PalabraReservada& TablaSimbolos::buscarVar(std::string id){ //buscar en variables
	return variablesMap[hashf(id)]; 
}
PalabraReservada TablaSimbolos::buscarFunc(std::string id) { //buscar en funciones
	return funcionesMap[hashf(id)];
}
bool TablaSimbolos::check_key(std::string e){
	if (variablesMap.find(hashf(e)) == variablesMap.end())
		return false;
	return true;
}
void TablaSimbolos::insertarFuncionMap(PalabraReservada pr) {
	int hash = hashf(pr.getNombre());
	auto palabra = std::make_pair(hash, pr);
	funcionesMap.insert(palabra);
}
void TablaSimbolos::insertarVariableMap(PalabraReservada pr) {
	int hash = hashf(pr.getNombre());
	auto palabra = std::make_pair(hash, pr);
	variablesMap.insert(palabra);
}
//-------------Metodos----------------!
void TablaSimbolos::recuperarDesdeArchivo(std::string ruta){
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
			ExceptionE e("ARCHIVO NO ENCONTRADO",0);
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

std::string TablaSimbolos::imprimirCodigo() {
	std::stringstream s;

	int i = 0;
	while (i < codigo.size()) {
		s << std::setw(2) << i + 1 <<" | ";
		s <<codigo[i] << "\n";
		i++;
	}
	s << "\n";
	return s.str();
}

std::string TablaSimbolos::mostrarErrores() {
	std::stringstream s;
	for (int i = 0; i < cerr.size(); i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); 
		std::cout << cerr[i] << "\n";
	}
	if (cerr.empty()) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); 
		std::cout << "Compilado correctamente sin errores!\n";

	}
	return s.str();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

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
			if (check_key(pr.getNombre())) {
				std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) + ": La variable '" + pr.getNombre() + "' ya esta Declarada";
				cerr.push_back(se);
			}
			else{
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
			if (!check_key(e)) {
				ExceptionE ex(e,1);
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
				if (check_key(statement)) {
					PalabraReservada pr = variablesMap[hashf(statement)];
					PalabraReservada padre = funcionesMap[hashf(pr.getPadre())];
					if ((padre.getTipo() == "void") ) {
						std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) +
							": void no retorna nada";
						cerr.push_back(se);
					}
					else if ((padre.getTipo() != pr.getTipo()) && (pr.getTipo() != funciones.top().getTipo())) {
						std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) +
							": el valor de retorno no coninicide con la declaracion de '" + padre.getNombre() + "'";
						cerr.push_back(se);
					}
					else if ((pr.getTipo() != funciones.top().getTipo())) {
						std::string se = "Error - Linea " + std::to_string(lineaCodigoActual) +
							": el valor de retorno no coninicide con la declaracion de '" + funciones.top().getNombre() + "'";
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

