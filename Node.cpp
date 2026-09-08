#include "Node.h"
Node::Node(string id, string nombre, int edad, string servicio){
    next = nullptr;
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
    prev=nullptr;
}