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


void menu();
void mostrarEsp();

void txt();
void atencion();

Node* headEspera = nullptr;
Node* headHistorial = nullptr;
Node* Urgencias = nullptr;
Node* Medicina_General = nullptr;
Node* Cardiologia = nullptr;
Node* Neurologia = nullptr;
Node* Traumatologia = nullptr;
Node* Cirugia = nullptr;
Node* Pediatria = nullptr;
Node* Hospitalizacion = nullptr;

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
            break;
        case 3: 
            break;
        case 4: cout << "Hasta luego :D." << endl; break; 
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



void atencion(){
    cout<<"=== PACIENTES EN ESPERA =="<< endl;
    do{
        mostrarEsp(headEspera);
        int opcionEs;
        cin>> opcionEs;
    }
}



