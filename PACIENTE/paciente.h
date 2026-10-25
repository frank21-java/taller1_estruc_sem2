#pragma once
#include <string>
#include <iostream>
using namespace std;

class paciente
{
private:
    string id, nombre;
    int edad;
    float temperatura;
    int presionArterial;
    int dolor;
    string tipoDolor;
    int trauma;
    int sintomasNeurologicos;
    int requiereCirugia;
    int diasHospitalizacion;
public:
    paciente() {}
    paciente(string id, string nombre, int edad,
        float temperatura, int presionArterial, int dolor, string tipoDolor,
        int trauma, int sintomasNeurologicos, int requiereCirugia, 
        int diasHospitalizacion);
    ~paciente();
    
    string getId() const;
    string getNombre() const;
    int getEdad() const;
    float getTemperatura() const;
    int getPresionArterial() const;
    int getDolor() const;
    string getTipoDolor() const;
    int getTrauma() const;
    int getSintomasNeurologicos() const;
    int getRequiereCirugia() const;
    int getDiasHospitalizacion() const;
    void mostrarDatosBusqueda(string departamento);
};