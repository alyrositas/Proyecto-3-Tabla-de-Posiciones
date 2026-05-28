#include <iostream>
#include <vector>
#include "Persona.h"
#include "Delantero.h"
#include "Portero.h"
#include "DT.h"
using namespace std;

void mostrarPlantilla(const vector<Persona*>& plantilla) {
    cout << "\n=== PLANTILLA ===" << endl;
    for (const auto& p : plantilla)
        p->mostrarInfo();
}

int main() {
    // Polimorfismo: vector de punteros a la clase base
    vector<Persona*> plantilla;

    plantilla.push_back(new DT("Lionel Scaloni", 46, "Argentina", "Argentina", 1));
    plantilla.push_back(new Portero("Emiliano Martinez", 31, "Argentina", 23));
    plantilla.push_back(new Delantero("Lionel Messi", 37, "Argentina", 10));
    plantilla.push_back(new Delantero("Julian Alvarez", 24, "Argentina", 9));

    // Simular acciones del partido
    Delantero* messi = dynamic_cast<Delantero*>(plantilla[2]);
    Delantero* julian = dynamic_cast<Delantero*>(plantilla[3]);
    Portero* dibu = dynamic_cast<Portero*>(plantilla[1]);

    if (messi) { messi->anotar(); messi->darAsistencia(); }
    if (julian) { julian->anotar(2); }
    if (dibu) { dibu->atajar(); dibu->atajar(); dibu->atajar(); }

    mostrarPlantilla(plantilla);

    // Llamada polimorfica: cada objeto ejecuta su propia version de getRol()
    cout << "\n=== ROLES ===" << endl;
    for (const auto& p : plantilla)
        cout << p->getNombre() << " -> " << p->getRol() << endl;

    for (auto p : plantilla) delete p;
    return 0;
}
