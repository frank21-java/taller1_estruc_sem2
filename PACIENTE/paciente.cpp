#include "paciente.h"

paciente::paciente(string id, string nombre, int edad,
                   float temperatura, int presionArterial, int dolor, string tipoDolor,
                   int trauma, int sintomasNeurologicos, int requiereCirugia, int diasHospitalizacion){
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->temperatura = temperatura;
    this->presionArterial = presionArterial;
    this->dolor = dolor;
    this->tipoDolor = tipoDolor;
    this->trauma = trauma;
    this->sintomasNeurologicos = sintomasNeurologicos;
    this->requiereCirugia = requiereCirugia;
    this->diasHospitalizacion = diasHospitalizacion;
}

paciente::~paciente(){}

string paciente::getId() const { return id; }
string paciente::getNombre() const { return nombre; }
int paciente::getEdad() const { return edad; }
float paciente::getTemperatura() const { return temperatura; }
int paciente::getPresionArterial() const { return presionArterial; }
int paciente::getDolor() const { return dolor; }
string paciente::getTipoDolor() const { return tipoDolor; }
int paciente::getTrauma() const { return trauma; }
int paciente::getSintomasNeurologicos() const { return sintomasNeurologicos; }
int paciente::getRequiereCirugia() const { return requiereCirugia; }
int paciente::getDiasHospitalizacion() const { return diasHospitalizacion; }

void paciente::mostrarDatosBusqueda(string departamento){
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Departamento: " << departamento << endl;
    
    cout << "T: " << temperatura << " | D: " << dolor 
         << " | TD: " << tipoDolor 
         << " | T: " << (trauma ? "Si" : "No")  // Muestra Si o No dependiendo del dato
         << " | SN: " << (sintomasNeurologicos ? "Si" : "No") 
         << " | RC: " << (requiereCirugia ? "Si" : "No") 
         << " | DH: ";
         
    if (diasHospitalizacion == 0) cout << "Ninguno";
    else cout << diasHospitalizacion;
    cout << endl;
}