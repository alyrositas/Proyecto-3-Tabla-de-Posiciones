#include <iostream>
#include "SimuladorTorneo.h"
#include "TorneoException.h"
using namespace std;

int main() {
    SimuladorTorneo torneo;

    // Polimorfismo: mezcla de tipos de selección
    torneo.agregarSeleccion(new SeleccionLocal("Canada",    "CONCACAF", 48));
    torneo.agregarSeleccion(new SeleccionEstrella("Francia",    "UEFA",      2,  3));
    torneo.agregarSeleccion(new SeleccionEstrella("Argentina",  "CONMEBOL",  1,  3));
    torneo.agregarSeleccion(new Seleccion("Marruecos",  "CAF",       13));
    torneo.agregarSeleccion(new Seleccion("Croacia",    "UEFA",      10));
    torneo.agregarSeleccion(new SeleccionEstrella("Brasil",     "CONMEBOL",  5,  5));
    torneo.agregarSeleccion(new Seleccion("Holanda",    "UEFA",       7));
    torneo.agregarSeleccion(new Seleccion("Portugal",   "UEFA",       6));

    cout << "=== SIMULADOR MUNDIAL ===" << endl;

    try {
        torneo.simularTorneoCompleto();
        torneo.mostrarHistorial();

        // Intentar agregar después de finalizar — provoca excepción
        torneo.agregarSeleccion(new Seleccion("Chile", "CONMEBOL", 30));
    } catch (const TorneoFinalizadoException& e) {
        cout << "\n[ERROR] " << e.what() << endl;
    } catch (const TorneoException& e) {
        cout << "\n[ERROR TORNEO] " << e.what() << endl;
    }

    // Demostrar excepción por número inválido de equipos
    try {
        SimuladorTorneo torneoMal;
        torneoMal.agregarSeleccion(new Seleccion("Equipo A", "UEFA", 1));
        torneoMal.agregarSeleccion(new Seleccion("Equipo B", "UEFA", 2));
        torneoMal.agregarSeleccion(new Seleccion("Equipo C", "UEFA", 3)); // 3 no es potencia de 2
        torneoMal.simularFase("Fase Invalida");
    } catch (const NumeroEquiposInvalidoException& e) {
        cout << "[ERROR] " << e.what() << endl;
    }

    return 0;
}
