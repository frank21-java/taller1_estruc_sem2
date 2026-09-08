#include "paciente.h"

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
void menu();
void txt();
void atencion();


int main()
{
    txt();
    int opcion;
    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1 :
            atencion();
            break;
        case 2:
            break;
        case 3: 
            break;
        case 4: cout << "¡Hasta pronto!" << endl; break; 
        default: cout << "Opción inválida" << endl;
        }
    } while (opcion != 4);
    return 0;
}
void menu(){
    system("cls");
    cout << "=== HOSPITAL MARMAJA ==="<< endl;
    cout << "1. Atender pacientes"<< endl;
    cout << "2. Ver departamento"<< endl;
    cout << "3. Revisar historial de atención"<< endl;
    cout << "4. Sali"<< endl;
    cout << ""<< endl;
    cout << "Seleccionar opción: ";
}

void txt(){
    ifstream archivo("ejemplo.txt");
    if(!archivo.is_open()) {
        cout << "el archivo no se a encontrado " << endl;
        return;
    }
    string linea;
    while (getline(archivo,linea)){
        stringstream ss(linea);
        string id,nombre,edades,servicio;
        int edad;
        getline(ss, id, ';');
        getline(ss,nombre,';');
        getline(ss,edades,';');
        getline(ss,servicio,';');
        edad = stoi(edades);
        paciente pacientes(string id, string nombre,int edad,string servicio); 

    }
    archivo.close();
}

void atencion(){
    cout<<"=== PACIENTES EN ESPERA =="<< endl;
    
    
}



