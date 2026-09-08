#include "paciente.h"
paciente::paciente(string id, string nombre,int edad,string servicio){
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}
paciente::~paciente(){}

string paciente::getId(){return id;}
string paciente::getNombre(){return nombre;}
int paciente::getEdad(){return edad;}
string paciente::getServicio(){return servicio;}
void paciente::setServicio(string servicio){this->servicio = servicio;}

void mostrar_paciente(){
    paciente* nodotemp=start;
    while(nodotemp!=nullptr){
        std::cout << nodotemp->id << " - "<<nodotemp->nombre<< std::endl;
        nodotemp = nodotemp->next;
    }
}
