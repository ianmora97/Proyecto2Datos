#include "PalabraReservada.h"

PalabraReservada::PalabraReservada(){
	valor = "";
}

PalabraReservada::~PalabraReservada(){
}

void PalabraReservada::setTipo(std::string tipo){
	this->tipo = tipo;
}

void PalabraReservada::setNombre(std::string nombre){
	this->nombre = nombre;
}

void PalabraReservada::setID(std::string ID){
	this->ID = ID;
}

void PalabraReservada::setPadre(std::string padre){
	this->padre = padre;
}

void PalabraReservada::setValor(std::string s) {
	this->valor = s;
}

std::string PalabraReservada::getTipo(){
	return tipo;
}

std::string PalabraReservada::getNombre(){
	return nombre;
}

std::string PalabraReservada::getID(){
	return ID;
}

std::string PalabraReservada::getPadre(){
	return padre;
}

std::string PalabraReservada::getValor(){
	return this->valor;
}

std::string PalabraReservada::toString(){
	std::stringstream s;

	if(tipo.size() == 2)
		s << " | " << tipo << "     | ";
	else if(tipo.size() == 3)
		s << " | " << tipo << "    | ";
	else if (tipo.size() == 4)
		s << " | " << tipo << "   | ";
	else if (tipo.size() == 5)
		s << " | " << tipo << "  | ";
	else if (tipo.size() == 6)
		s << " | " << tipo << " | ";

	if(ID.size() == 9)
		s << ID << " | ";
	else if(ID.size() == 8)
		s << ID << "  | ";
	else if (ID.size() == 7)
		s << ID << "   | ";

	s << nombre << " | ";

	if (padre != "") {
		if (padre.size() == 4)
			s << padre << "    | ";
		else
			s << padre << " | ";
	} else {
		s << "NULL" << "  | ";
	}

	if(valor != "")
		s << valor << " |";
	else
		s << "Vacio" << " |";


	return s.str();
}
