#include "Jugador.h"
#include <iostream>

Jugador::Jugador(string nombre, int edad, string nacionalidad, int numeroCamiseta)
    : Persona(nombre, edad, nacionalidad), numeroCamiseta(numeroCamiseta), golesAnotados(0) {}

int Jugador::getGolesAnotados() const { return golesAnotados; }

void Jugador::anotar(int goles) { golesAnotados += goles; }

string Jugador::getRol() const { return "Jugador"; }

void Jugador::mostrarInfo() const {
    cout << "[" << getPosicion() << "] #" << numeroCamiseta
         << " " << nombre << " (" << nacionalidad << ") | "
         << "Goles: " << golesAnotados << endl;
}
