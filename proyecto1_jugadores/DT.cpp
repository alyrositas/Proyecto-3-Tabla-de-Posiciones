#include "DT.h"
#include <iostream>

DT::DT(string nombre, int edad, string nacionalidad, string seleccion, int mundiales)
    : Persona(nombre, edad, nacionalidad), seleccionDirigida(seleccion), mundialísGanados(mundiales) {}

string DT::getSeleccion() const { return seleccionDirigida; }
string DT::getRol() const { return "Director Tecnico"; }

void DT::mostrarInfo() const {
    cout << "[DT] " << nombre << " (" << nacionalidad << ") | "
         << "Seleccion: " << seleccionDirigida
         << " | Mundiales ganados: " << mundialísGanados << endl;
}
