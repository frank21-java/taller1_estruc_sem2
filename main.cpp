#include "PACIENTE/paciente.h"
#include "NODOS/Node.h"
#include "AVL/ArbolAVL.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

//principal
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void liberarLista(Node*& head);
void menu();
void txt();
Node* existe(Node* head, const string& id);
Node* eliminarPrimero(Node*& head);
//primerpunto
void insertarEnAVL(const paciente& p, const string& serv);
void atencion();
string  criterio(paciente p);

//segundopunto
void verDepartamento();

//parte3
void buscarPaciente();
///


Node* headEspera = nullptr;

ArbolAVL UrgenciasAVL;
ArbolAVL MedicinaGeneralAVL;
ArbolAVL CardiologiaAVL;
ArbolAVL NeurologiaAVL;
ArbolAVL TraumatologiaAVL;
ArbolAVL CirugiaAVL;
ArbolAVL PediatriaAVL;
ArbolAVL HospitalizacionAVL;

//principal

void agregar(Node*& head, Node* nuevo) {
    if (nuevo == nullptr) return;
    nuevo->next = nullptr;
    nuevo->prev = nullptr;
    if (head == nullptr) {
        head = nuevo;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = nuevo;
    nuevo->prev = temp;
}

Node* existe(Node* head, const string& id){
    Node* temp = head;
    while (temp != nullptr)
    {
        if(temp->p.getId() == id) {return temp;}
        temp = temp->next;
    }
    return nullptr;
}
void liberarLista(Node*& head){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
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
            verDepartamento();
            break;
        case 3:
            buscarPaciente();
            break;
        case 4: cout << "Hasta luego :D." << endl; break; 
        default: cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);
    liberarLista(headEspera);
    return 0;
}
void menu(){
    system("cls");
    cout << "=== HOSPITAL MARMAJA ==="<< endl;
    cout << "1. Atender pacientes"<< endl;
    cout << "2. Ver departamento"<< endl;
    cout << "3. Buscar paciente"<< endl;
    cout << "4. Salir"<< endl;
    cout << ""<< endl;
    cout << "Seleccionar opcion: ";
}
void txt(){
    ifstream archivo("DATA/ejemplo.txt"); 
    if(!archivo.is_open()) {
        cout << "el archivo no se a encontrado " << endl;
        system("pause");
        return;
    }
    string linea;
    while (getline(archivo,linea)){
        if (linea.empty()) continue;
        stringstream ss(linea);
        string id, nombre, edad_str, temp_str, presion_str, dolor_str, tipoDolor, trauma_str, neuro_str, cirugia_str, dias_str;
        
        if (!getline(ss, id, ';') || !getline(ss, nombre, ';') || !getline(ss, edad_str, ';') ||
            !getline(ss, temp_str, ';') || !getline(ss, presion_str, ';') || !getline(ss, dolor_str, ';') ||
            !getline(ss, tipoDolor, ';') || !getline(ss, trauma_str, ';') || !getline(ss, neuro_str, ';') ||
            !getline(ss, cirugia_str, ';') || !getline(ss, dias_str, ';')) {
            continue;
        }
        try {
            int edad = stoi(edad_str);
            float temp = stof(temp_str);
            int presion = stoi(presion_str);
            int dolor = stoi(dolor_str);
            int trauma = stoi(trauma_str);
            int neuro = stoi(neuro_str);
            int cirugia = stoi(cirugia_str);
            int dias = stoi(dias_str);

            if (existe(headEspera, id)) continue;

            paciente p(id, nombre, edad, temp, presion, dolor, tipoDolor, trauma, neuro, cirugia, dias);
            Node* nuevo = new Node(p);
            agregar(headEspera, nuevo);

        } catch (const exception& e) {
            continue;
        }
    }
    archivo.close();
}
Node* eliminarPrimero(Node*& head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}


//primer punto

void insertarEnAVL(const paciente& p, const string& serv) {
    if (serv == "Urgencias") UrgenciasAVL.insertar(p);
    else if (serv == "Medicina General") MedicinaGeneralAVL.insertar(p);
    else if (serv == "Cardiologia") CardiologiaAVL.insertar(p);
    else if (serv == "Neurologia") NeurologiaAVL.insertar(p);
    else if (serv == "Traumatologia") TraumatologiaAVL.insertar(p);
    else if (serv == "Cirugia") CirugiaAVL.insertar(p);
    else if (serv == "Pediatria") PediatriaAVL.insertar(p);
    else if (serv == "Hospitalizacion") HospitalizacionAVL.insertar(p);
}
string determinarServicio(paciente p) {
    cout << "Ruta: ";
    if (p.getTemperatura() >= 39.5 || p.getPresionArterial() >= 160 || p.getDolor() >= 9) {
        cout << "Signos vitales criticos (Temp >= 39.5 o Presion >= 160 o Dolor >= 9)" << endl;
        return "Urgencias";
    }
    cout << "Signos vitales estables -> ";
    if (p.getTipoDolor() == "pecho") {
        cout << "Dolor en el pecho" << endl;
        return "Cardiologia";
    }
    if (p.getSintomasNeurologicos() == 1) {
        cout << "Sintomas neurologicos == 1" << endl;
        return "Neurologia";
    }
    cout << "Sin sintomas neurologicos -> ";
    if (p.getTrauma() == 1) {
        cout << "Trauma == 1 -> ";
        if (p.getRequiereCirugia() == 1) {
            cout << "Requiere cirugia" << endl;
            return "Cirugia";
        }
        cout << "No requiere cirugia" << endl;
        return "Traumatologia";
    }
    cout << "Sin trauma -> ";
    if (p.getEdad() < 14) {
        cout << "Edad < 14" << endl;
        return "Pediatria";
    }
    cout << "Edad >= 14 -> ";
    if (p.getDiasHospitalizacion() >= 3) {
        cout << "Dias hospitalizacion >= 3" << endl;
        return "Hospitalizacion";
    }
    cout << "Dias hospitalizacion < 3" << endl;
    return "Medicina General";
}
void atencion(){
    limpiarPantalla();
    if(headEspera == nullptr){
        cout << "No hay pacientes en espera." << endl;
        system("pause");
        return;
    }
    cout<<"=== ATENDIENDO PACIENTES ==="<< endl;
    while (headEspera != nullptr)
    {
        cout << "" << endl;
        Node* atendido = eliminarPrimero(headEspera);
        if (atendido == nullptr) break;
        cout << "ID: " << atendido->p.getId() << endl;
        cout << "Nombre: " << atendido->p.getNombre() << endl;
        cout << "Edad: " << atendido->p.getEdad() << endl;
        cout << "Temperatura: " << atendido->p.getTemperatura() << endl;
        cout << "Dolor: " << atendido->p.getDolor() << endl;
        cout << "TipoDolor: " << atendido->p.getTipoDolor() << endl;
        cout << "Trauma: " << atendido->p.getTrauma() << endl;
        cout << "SintomasNeurologicos: " << atendido->p.getSintomasNeurologicos() << endl;
        cout << "RequiereCirugia: " << atendido->p.getRequiereCirugia() << endl;
        cout << "DiasHospitalizacion: " << atendido->p.getDiasHospitalizacion() << endl;
        cout << endl;
        string asignar = criterio(atendido->p);
        cout << "\nServicio asignado: " << asignar << endl;

        // Insertar en el AVL correspondiente
        insertarEnAVL(atendido->p, asignar);
        cout << "Paciente insertado en el AVL de " << asignar << ".\n";

    }
    
    system("pause");
}

//punto 2
void verDepartamento(){
    limpiarPantalla();
    cout << "=== ESTADO DE LOS DEPARTAMENTOS ===" << endl << endl;
    ArbolAVL* arboles[] = {
        &UrgenciasAVL, &MedicinaGeneralAVL, &TraumatologiaAVL, &CardiologiaAVL, 
        &NeurologiaAVL, &CirugiaAVL, &PediatriaAVL, &HospitalizacionAVL
    };
    string nombres[] = {
        "Urgencias", "Medicina General", "Traumatologia", "Cardiologia", 
        "Neurologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };
    for (int i = 0; i < 8; i++) {
        cout << nombres[i] << endl;
        
        if (arboles[i]->estaVacio()) {
            cout << "Sin pacientes" << endl;
        } else {
            cout << "Pacientes:" << endl;
            arboles[i]->mostrarInOrden();
        }
        cout << endl;
    }
    system("pause");
}


//punto 3
void buscarPaciente(){
    limpiarPantalla();
    string buscar;
    cout << "=== BUSCAR PACIENTE ===" << endl;
    cout << "\nIndique el ID o Nombre del paciente: ";
    cin.ignore();
    getline(cin,buscar);
    cout << "\nBuscando en AVL..." << endl;

    paciente encontrado;
    bool hallado = false;
    string deptoEncontrado = "";
    string ruta = "";
    
    ArbolAVL* arboles[] = {
        &UrgenciasAVL, &MedicinaGeneralAVL, &TraumatologiaAVL, &CardiologiaAVL, 
        &NeurologiaAVL, &CirugiaAVL, &PediatriaAVL, &HospitalizacionAVL
    };
    string nombres[] = {
        "Urgencias", "Medicina General", "Traumatologia", "Cardiologia", 
        "Neurologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    for (int i = 0; i < 8; i++) {
        ruta ="";
        if (arboles[i]->buscarID(buscar, encontrado, ruta)) {
            deptoEncontrado = nombres[i];
            hallado = true;
            break;
        }
        ruta = "";
        if (arboles[i]->buscarNombre(buscar, encontrado, ruta)) {
            deptoEncontrado = nombres[i];
            hallado = true;
            break;
        }
    }
    if (hallado) {
        cout << "\nPaciente encontrado:\n";
        cout << "---------" << endl;
        encontrado.mostrarDatosBusqueda(deptoEncontrado);
        cout << "---------" << endl;
        
        cout << "\nRuta de busqueda:\n" << ruta << endl;
    } else {
        cout << "\nEl paciente no se encuentra en ningun departamento.\n";
    }
    cout << endl;
    system("pause");
}