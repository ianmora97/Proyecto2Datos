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
	s << "Tipo: " << tipo << "\n";
	s << "Id: " << ID << "\n";
	s << "Nombre: " << nombre << "\n";
	s << "Padre: " << padre << "\n";
	s << "Valor: " << valor << "\n";


	return s.str();
}
