#include "Portero.h"
#include <iostream>

Portero::Portero(string nombre, int edad, string nacionalidad, int numeroCamiseta)
    : Jugador(nombre, edad, nacionalidad, numeroCamiseta), atajadas(0) {}

void Portero::atajar() { atajadas++; }
int Portero::getAtajadas() const { return atajadas; }
string Portero::getPosicion() const { return "Portero"; }

void Portero::mostrarInfo() const {
    Jugador::mostrarInfo();
    cout << "   Atajadas: " << atajadas << endl;
}
