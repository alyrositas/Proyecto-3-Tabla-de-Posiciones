#include <iostream>
#include "GrupoMundial.h"
#include "MundialException.h"
using namespace std;

int main() {
    GrupoMundial grupoC("C");

    // Agregar equipos — con manejo de excepción por duplicado
    try {
        grupoC.agregarEquipo("Argentina");
        grupoC.agregarEquipo("Polonia");
        grupoC.agregarEquipo("Mexico");
        grupoC.agregarEquipo("Arabia Saudita");
        grupoC.agregarEquipo("Bolivia"); // Excepción: grupo lleno
    } catch (const GrupoLlenoException& e) {
        cout << "[ERROR] " << e.what() << endl;
    }

    // Registrar partidos — con manejo de excepción por equipo inexistente
    try {
        grupoC.registrarPartido("Argentina", 1, "Arabia Saudita", 2);
        grupoC.registrarPartido("Polonia",   0, "Mexico",         0);
        grupoC.registrarPartido("Argentina", 2, "Mexico",         0);
        grupoC.registrarPartido("Polonia",   2, "Arabia Saudita", 0);
        grupoC.registrarPartido("Argentina", 2, "Polonia",        0);
        grupoC.registrarPartido("Mexico",    2, "Arabia Saudita", 1);

        // Equipo inexistente — provoca excepción
        grupoC.registrarPartido("Uruguay", 1, "Mexico", 0);
    } catch (const EquipoNoEncontradoException& e) {
        cout << "[ERROR] " << e.what() << endl;
    } catch (const MundialException& e) {
        cout << "[ERROR MUNDIAL] " << e.what() << endl;
    }

    grupoC.mostrarTabla();

    // Demostrar excepción de puntos negativos
    try {
        EquipoGrupo eq("Test");
        eq.registrarVictoria(-1, 0);
    } catch (const PuntosNegativosException& e) {
        cout << "\n[ERROR] " << e.what() << endl;
    }

    return 0;
}
