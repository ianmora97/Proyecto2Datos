//PalabraReservada.h
//Autores: Ian Mora Rodrígues Ced. 116890118
//         Iván Chinchilla Cordoba Ced. 116730818
//		   Nancy Maroto Araya Ced. 402130446
//Descripcion: Clase Palabra Reservada, tipo de dato necesario para identificar y manipular
//			   los elementos de la tabla de simbolos

#ifndef PALABRARESERVADA_H
#define PALABRARESERVADA_H

#include "tools.h"

class PalabraReservada {
public:
	PalabraReservada();
	~PalabraReservada();

	void setTipo(std::string);
	void setNombre(std::string);
	void setID(std::string);
	void setPadre(std::string);
	void setValor(std::string);

	std::string getTipo();
	std::string getNombre();
	std::string getID();
	std::string getPadre();
	std::string getValor();

	std::string imprimirAtributos();
	std::string toString();

private:
	std::string tipo;	//int, void, while, if
	std::string nombre; //nombre de variable o funcion
	std::string ID;		//statement variable o funcion
	std::string padre;	//lugar al que pertenece
	std::string valor;  //valor asignado a la variable
};

#endif