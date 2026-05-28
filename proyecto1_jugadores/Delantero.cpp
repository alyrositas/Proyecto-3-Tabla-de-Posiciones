#include "Delantero.h"
#include <iostream>

Delantero::Delantero(string nombre, int edad, string nacionalidad, int numeroCamiseta)
    : Jugador(nombre, edad, nacionalidad, numeroCamiseta), asistencias(0) {}

void Delantero::darAsistencia() { asistencias++; }
int Delantero::getAsistencias() const { return asistencias; }
string Delantero::getPosicion() const { return "Delantero"; }

void Delantero::mostrarInfo() const {
    Jugador::mostrarInfo();
    cout << "   Asistencias: " << asistencias << endl;
}
