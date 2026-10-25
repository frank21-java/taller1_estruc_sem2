#pragma once
#include <string>
#include "../PACIENTE/paciente.h"
using namespace std;

struct Node {
    paciente p;
    Node* next;
    Node* prev;
    Node(const paciente& p);
};