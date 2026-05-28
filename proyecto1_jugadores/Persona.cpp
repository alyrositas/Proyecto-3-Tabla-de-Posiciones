#include "Persona.h"
#include <iostream>

Persona::Persona(string nombre, int edad, string nacionalidad)
    : nombre(nombre), edad(edad), nacionalidad(nacionalidad) {}

string Persona::getNombre() const { return nombre; }
int Persona::getEdad() const { return edad; }
string Persona::getNacionalidad() const { return nacionalidad; }
