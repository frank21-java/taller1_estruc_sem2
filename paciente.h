#pragma once
#include <string>
using namespace std;

class paciente
{
private:
    string id, nombre, servicio;
    int edad;
public:
    paciente(string id, string nombre, int edad, string servicio);
    ~paciente();
    
    string getId();
    string getNombre();
    int getEdad();
    string getServicio();
    void setServicio(string servicio);
};