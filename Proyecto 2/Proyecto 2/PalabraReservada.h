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

	std::string getTipo();
	std::string getNombre();
	std::string getID();
	std::string getPadre();

private:
	std::string tipo;
	std::string nombre;
	std::string ID;
	std::string padre;
};

