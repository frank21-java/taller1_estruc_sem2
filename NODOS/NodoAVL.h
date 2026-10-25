#pragma once
#include "../PACIENTE/paciente.h"
struct NodoAVL {
    paciente dato;
    int altura;
    NodoAVL* izq;
    NodoAVL* der;
    NodoAVL(const paciente& p) : dato(p), altura(1), izq(nullptr), der(nullptr) {}
};