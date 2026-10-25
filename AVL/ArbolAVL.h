#pragma once
#include "../NODOS/NodoAVL.h"
#include <string>
class ArbolAVL {
private:
    NodoAVL* raiz;

    int obtenerAltura(NodoAVL* nodo);
    int obtenerBalance(NodoAVL* nodo);
    void ActualizarAltura(NodoAVL* nodo);
    
    NodoAVL* rotarDer(NodoAVL* y);
    NodoAVL* rotarIzq(NodoAVL* x);
    NodoAVL* insertar(NodoAVL* nodo, const paciente& p);
    void destruir(NodoAVL* nodo);
    NodoAVL* insertarAux(NodoAVL* nodo, const paciente& p);
    bool buscarPorNombre(NodoAVL* nodo,const string& nombre, paciente& resultado, string& ruta);
    void inOrden(NodoAVL* nodo);
    void preOrden(NodoAVL* nodo);
    void postOrden(NodoAVL* nodo);
    void mostrarFactores(NodoAVL* nodo);


public:
    ArbolAVL();
    ~ArbolAVL();
    void insertar(const paciente& p);
    bool buscarID(string id, paciente& resultado, string& ruta);
    bool buscarNombre(string nombre, paciente& resultado, string& ruta);
    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
    int alturaArbol();
    void mostrarFactoresBalance();
    bool estaVacio();
};