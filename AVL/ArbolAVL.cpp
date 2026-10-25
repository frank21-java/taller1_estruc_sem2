#include "ArbolAVL.h"
#include <algorithm>
#include <iostream>
using namespace std;

ArbolAVL::ArbolAVL() : raiz(nullptr){}
ArbolAVL::~ArbolAVL() {destruir(raiz);}

void ArbolAVL::destruir(NodoAVL* nodo){
    if(nodo){
        destruir(nodo->izq);
        destruir(nodo->der);
        delete nodo;
    }
}
int ArbolAVL::obtenerAltura(NodoAVL* nodo){
    return nodo ? nodo->altura : 0;
}
int ArbolAVL::obtenerBalance(NodoAVL* nodo){
    return nodo ? obtenerAltura(nodo->izq) - obtenerAltura(nodo->der) : 0;
}
void ArbolAVL::ActualizarAltura(NodoAVL* nodo){
    if (nodo) nodo->altura = 1+ max(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));
}

NodoAVL* ArbolAVL::rotarDer(NodoAVL* y){
    NodoAVL* x = y->izq;
    NodoAVL* y2 = x->der;
    x->der = y;
    y->izq = y2;
    ActualizarAltura(y);
    ActualizarAltura(x);
    return x;
}
NodoAVL* ArbolAVL::rotarIzq(NodoAVL* x){
    NodoAVL* y = x->der;
    NodoAVL* x2 = x->izq;
    y->izq = x;
    x->der = x2;
    ActualizarAltura(x);
    ActualizarAltura(y);
    return y;
}
NodoAVL* ArbolAVL::insertarAux(NodoAVL* nodo, const paciente& p) {
    if (nodo == nullptr) {
        return new NodoAVL(p);
    }
    if (p.getId() < nodo->dato.getId()) {
        nodo->izq = insertarAux(nodo->izq, p);
    } 
    else if (p.getId() > nodo->dato.getId()) {
        nodo->der = insertarAux(nodo->der, p);
    } 
    else {
        return nodo; 
    }
    ActualizarAltura(nodo);
    int balance = obtenerBalance(nodo);
    if (balance > 1 && p.getId() < nodo->izq->dato.getId()) {
        return rotarDer(nodo);
    }
    if (balance < -1 && p.getId() > nodo->der->dato.getId()) {
        return rotarIzq(nodo);
    }
    if (balance > 1 && p.getId() > nodo->izq->dato.getId()) {
        nodo->izq = rotarIzq(nodo->izq);
        return rotarDer(nodo);
    }
    if (balance < -1 && p.getId() < nodo->der->dato.getId()) {
        nodo->der = rotarDer(nodo->der);
        return rotarIzq(nodo);
    }
    return nodo;
}

void ArbolAVL::insertar(const paciente& p) {
    raiz = insertarAux(raiz, p);
}
bool ArbolAVL::buscarID(string id, paciente& resultado, string& ruta){
    NodoAVL* actual = raiz;
    if (!actual) return false; 
    bool esRaiz = true;
    while (actual){
        if (id == actual->dato.getId()){
            if (esRaiz) ruta = "0";
            resultado = actual->dato; 
            return true;
        }
        esRaiz = false;
        
        if (id < actual->dato.getId()) {
            ruta += "0";
            actual = actual->izq;
        } else {
            ruta += "1";
            actual = actual->der;
        }
    }
    
    return false;
}

bool ArbolAVL::buscarPorNombre(NodoAVL* nodo, const string& nombre, paciente& resultado, string& ruta) {
    if (!nodo) return false;
    if (nodo->dato.getNombre() == nombre) {
        resultado = nodo->dato;
        return true;
    }
    ruta += "(" + nodo->dato.getId() + ")";
    if (buscarPorNombre(nodo->izq, nombre, resultado, ruta)) {
        return true;
    }
    return buscarPorNombre(nodo->der, nombre, resultado, ruta);
}

bool ArbolAVL::buscarNombre(string nombre, paciente& resultado, string& ruta) {
    return buscarPorNombre(raiz, nombre, resultado,ruta);
}
void ArbolAVL::mostrarInOrden() { 
    inOrden(raiz); 
    cout << endl; 
}
void ArbolAVL::inOrden(NodoAVL* nodo){
    if(!nodo) return;
    inOrden(nodo->izq);
    cout << nodo->dato.getNombre() << " (" << nodo->dato.getId() << ")" << endl;
    inOrden(nodo->der);
}
void ArbolAVL::mostrarPreOrden() { 
    preOrden(raiz); 
    cout << endl; 
}
void ArbolAVL::preOrden(NodoAVL* nodo){
    if(!nodo) return;
    cout << nodo->dato.getNombre() << " (" << nodo->dato.getId() << ")" << endl;
    preOrden(nodo->izq);
    preOrden(nodo->der);
}
void ArbolAVL::mostrarPostOrden() { 
    postOrden(raiz); 
    cout << endl; 
}
void ArbolAVL::postOrden(NodoAVL* nodo){
    if(!nodo) return;
    postOrden(nodo->izq);
    postOrden(nodo->der);
    cout << nodo->dato.getNombre() << " (" << nodo->dato.getId() << ")" << endl;
}

int ArbolAVL::alturaArbol() { return obtenerAltura(raiz); }

bool ArbolAVL::estaVacio() {
    return raiz == nullptr;
}