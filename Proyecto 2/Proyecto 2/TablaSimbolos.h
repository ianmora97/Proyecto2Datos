//TablaSimbolos.h
//Autores: Ian Mora Rodrígues Ced. 116890118
//         Iván Chinchilla Cordoba Ced. 116730818
//		   Nancy Maroto Araya Ced. 402130446
//Descripcion: Clase que crea la tabla de simbolos, ademas identifica los errores
//			   encontrados en el codigo (si es que existen)

#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include "PalabraReservada.h"

//Numero maximo de linea de codigo por archivo
#define LINEAS_MAX 25 

//Excepciones para identificar errores
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

	//-------------Metodos basicos para leer y crear la tabla de simbolos----------------!
	void initVectores();
	int hashf(std::string id);
	void recuperarDesdeArchivo(std::string);

	//-------------Metodos propios de la tabla de simbolos----------------!
	PalabraReservada& buscarVar(std::string);
	PalabraReservada buscarFunc(std::string);
	void insertarFuncionMap(PalabraReservada);
	void insertarVariableMap(PalabraReservada);
	void modificarAtributosFuncionMap(std::string, std::string, std::string, std::string, std::string);
	void modificarAtributosVariableMap(std::string, std::string, std::string, std::string, std::string);
	void borrarFuncionMap(std::string);
	void borrarVariableMap(std::string);
	std::string obtenerAtributosFuncionMap(std::string);
	std::string obtenerAtributosVariableMap(std::string);

	//-------------Metodos auxliares que ayudan a la construccion de la tabla de simbolos-------------!
	void leerString(std::string);
	void paramentros(std::string);
	bool comparar(char);
	bool compararFunc(std::string);
	bool existeVar(std::string);
	bool existeFunc(std::string);

	//-------------Metodos de impresion----------------!
	std::string toString();
	std::string imprimirCodigo();
	void mostrarErrores();

private:
	std::unordered_map<int, PalabraReservada> funcionesMap; //Tabla hash de funciones
	std::unordered_map<int, PalabraReservada> variablesMap; //Tabla hash de variables

	std::stack<PalabraReservada> funciones; //Pila de funciones
	std::stack<PalabraReservada> funcionesImprimir; //Pila de funciones -solo para imprimir-
	std::stack<PalabraReservada> variables;// Pila de variables

	std::vector<std::string> codigo; //Vector donde en cada posicion guarda una linea de codigo
	std::vector<std::string> func; //Vector que contiene las palabras reservadas del lenguaje
	std::vector<char> operadores; //Vector que contiene los operadores disponibles en el lenguaje
	std::vector<std::string> cerr; //Vector que guarda los errores encontrados

	int lineaCodigoActual = 1; //Linea de codigo que se este trabajando en el momento
};

#endif