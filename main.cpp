#include "paciente.h"
#include "Node.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

//principal
void menu();
void txt();
//primerpunto
void atencion();
void mostrarEsp(Node* head);
void asiganarDepa(Node* nuevo);
Node* eliminarPrimero(Node*& head);
//segundopunto
void menu2();
void verDepartamento();




Node* headEspera = nullptr;
Node* Urgencias = nullptr;
Node* Medicina_General = nullptr;
Node* Cardiologia = nullptr;
Node* Neurologia = nullptr;
Node* Traumatologia = nullptr;
Node* Cirugia = nullptr;
Node* Pediatria = nullptr;
Node* Hospitalizacion = nullptr;

Node* headHistorial = nullptr;

void agregar(Node*& head, Node* nuevo){
    if(nuevo == nullptr) return;
    if(head == nullptr){
        head = nuevo;
        nuevo->next = nullptr;
        nuevo->prev = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next =nuevo;
    nuevo->prev = temp;
    nuevo->next = nullptr;
}

//principal
int main(){
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
            verDepartamento();
            break;
        case 3:
            break;
        case 4: cout << "Hasta luego :D." << endl; break; 
        default: cout << "Opción inválida" << endl;
        }
    } while (opcion != 4);
    return 0;
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
        Node* nuevo = new Node(id, nombre,edad,servicio); 
        agregar(headEspera, nuevo);
    }
    archivo.close();
}
void menu(){
    system("clear");
    cout << "=== HOSPITAL MARMAJA ==="<< endl;
    cout << "1. Atender pacientes"<< endl;
    cout << "2. Ver departamento"<< endl;
    cout << "3. Revisar historial de atención"<< endl;
    cout << "4. Sali"<< endl;
    cout << ""<< endl;
    cout << "Seleccionar opción: ";
}

//primer punto
Node* eliminarPrimero(Node*& head){
    if(head == nullptr) { return nullptr;}
    Node* temp = head;
    head = head->next;
    if(head != nullptr){head->prev = nullptr;}
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void mostrarEsp(Node* head){
    if(head == nullptr){
        cout << "No hay Pacientes"<< endl;
        return;
    }
    Node* temp = head;
    int cont = 1;
    while(temp != nullptr){
        cout<<cont++<<". "
            << temp->p.getId()<<" - "
            << temp->p.getNombre()<<endl;
        temp = temp->next;
    }
}

void asiganarDepa(Node* nuevo){
    if(nuevo != nullptr){
        return;
    }
    string serv = nuevo->p.getServicio();
    if(serv == "Urgencias"){ agregar(Urgencias,nuevo);}
    else if(serv == "Medicina General"){ agregar(Medicina_General,nuevo);}
    else if(serv == "Cardiología"){ agregar(Cardiologia,nuevo);}
    else if(serv == "Neurología"){ agregar(Neurologia,nuevo);}
    else if(serv == "Traumatología"){ agregar(Traumatologia,nuevo);}
    else if(serv == "Cirugía"){ agregar(Cirugia,nuevo);}
    else if(serv == "Pediatría"){ agregar(Pediatria,nuevo);}
    else if(serv == "Hospitalización"){ agregar(Hospitalizacion,nuevo);}
}

void atencion(){
    cout<<"=== PACIENTES EN ESPERA =="<< endl;
    mostrarEsp(headEspera);
    int opcionEs;
    cout << "Indique la cantidad de pacientes a atender: ";
    cin>> opcionEs;
    cout<<""<<endl;
    int total = 0;
    Node* temp = headEspera;
    while(temp != nullptr){
        total++;
        temp = temp->next;
    }
    if(opcionEs <=0 || opcionEs > total){
        cout<< "Cantidad invalida"<<endl;
        system("stop");
        return;
    }
    cout<< "=== ATENDIENDO PACIENTES ==="<<endl;
    for(int i=0;i<opcionEs;i++){
        Node* atendido = eliminarPrimero(headEspera);
        if(atendido == nullptr){ break;}
        asiganarDepa(atendido);
        Node* copiahistorial = new Node(atendido->p.getId(),atendido->p.getNombre(),atendido->p.getEdad(),atendido->p.getServicio());
        agregar(headHistorial, copiahistorial);
        cout << "ID: "<<atendido->p.getId()<<endl;
        cout << "Nombre: "<<atendido->p.getNombre()<<endl;
        cout << "Edad: "<<atendido->p.getEdad()<<endl;
        cout << "Servicio: "<<atendido->p.getServicio()<<endl;
        cout << ""<<endl;
        cout << "Paciente enviado a "<<atendido->p.getServicio()<<endl;
    }
    cout<<""<<endl;
    string hola;
    cout << "Presione alguna tecla para continuar "<<endl;
    cin>>hola;
}

//punto 2

void menu2(){
    system("clear");
    cout << "=== DEPARTAMENTOS/SERVICIOS ==="<< endl;
    cout << "1. Urgencias"<< endl;
    cout << "2. Medicina General"<< endl;
    cout << "3. Cardiología"<< endl;
    cout << "4. Neurología"<< endl;
    cout << "5. Traumatología"<< endl;
    cout << "6. Cirugía"<< endl;
    cout << "7. Pediatría"<< endl;
    cout << "8. Hospitalización"<< endl;
    cout << ""<< endl;
    cout << "Seleccionar opción: ";
}

void mostrarDepa(Node* head){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->p.getNombre()<<" ("<<temp->p.getEdad()<<")"<<endl;
        temp = temp->next;
    }
}

void verDepartamento(){
    menu2();
    int opcion;
    cout<< "Seleccionar opción: ";
    cin>>opcion;
    cout<<""<<endl;
    if(opcion == 1){ mostrarDepa(Urgencias);}
    else if(opcion == 2){ mostrarDepa(Medicina_General);}
    else if(opcion == 3){ mostrarDepa(Cardiologia);}
    else if(opcion == 4){ mostrarDepa(Neurologia);}
    else if(opcion == 5){ mostrarDepa(Traumatologia);}
    else if(opcion == 6){ mostrarDepa(Cirugia);}
    else if(opcion == 7){ mostrarDepa(Pediatria);}
    else if(opcion == 8){ mostrarDepa(Hospitalizacion);}
    else{
        cout<<"Opcion invalida"<<endl;
    }
    cout<<""<<endl;
    string hola;
    cout << "Presione alguna tecla para continuar "<<endl;
    cin>>hola;
}





//punto 3




