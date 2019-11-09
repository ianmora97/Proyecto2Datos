#include "PalabraReservada.h"

PalabraReservada::PalabraReservada(){
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
