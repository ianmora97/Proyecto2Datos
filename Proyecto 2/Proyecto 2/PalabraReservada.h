#pragma once

#include <string>
#include <sstream>

class PalabraReservada{
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

	std::string toString();

private:
	std::string tipo;	//int, void, while, if
	std::string nombre; //nombre de variabla o funcion
	std::string ID;		//statement variable o funcion
	std::string padre;	//parentesis al que pertenece
	std::string valor;	//valor del tipo
};

