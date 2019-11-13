//PalabraReservada.cpp
//Autores: Ian Mora Rodrígues Ced. 116890118
//         Iván Chinchilla Cordoba Ced. 116730818
//		   Nancy Maroto Araya Ced. 402130446
//Descripcion: Implementacion de los metodos declarados en el 
//             archivo de cabecera "PalabraReservada.h"

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

std::string PalabraReservada::imprimirAtributos(){
	std::stringstream s;

	s << "Nombre: " << nombre << "\n";
	s << "Tipo: " << tipo << "\n";
	s << "ID: " << ID << "\n";
	s << "Padre: " << padre << "\n";
	s << "Valor: " << valor << "\n";

	return s.str();
}

std::string PalabraReservada::toString() {
	std::stringstream s;

	s << " | " << std::setw(10) << tipo << " | ";
	s << std::setw(10) << ID << " | ";
	s << std::setw(10) << nombre << " | ";

	if (padre != "") {
		s << std::setw(10) << padre << " | ";
	}
	else {
		s << std::setw(10) << "NULL" << " | ";
	}

	if (valor != "")
		s << std::setw(10) << valor << " |";
	else
		s << std::setw(10) << "Vacio" << " |";


	return s.str();
}
