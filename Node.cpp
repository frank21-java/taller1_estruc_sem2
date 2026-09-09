#include "Node.h"
Node::Node(string id, string nombre, int edad, string servicio)
    : p(id, nombre, edad, servicio), 
        next(nullptr),
        prev(nullptr) {
    
}