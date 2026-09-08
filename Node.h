#pragma once
#include <string>
using namespace std;
struct Node{
    next = nullptr;
    string id;
    string nombre;
    int edad;
    string servicio;
    prev=nullptr;
    Node(string id, string nombre, int edad, string servicio);
    Node* prev;
};