#pragma once
#include <string>
#include "paciente.h"
using namespace std;

struct Node {
    paciente p;
    Node* next;
    Node* prev;
    Node(string id, string nombre, int edad, string servicio);
};