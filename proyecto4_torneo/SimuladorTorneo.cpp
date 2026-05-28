#include "SimuladorTorneo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

SimuladorTorneo::SimuladorTorneo() : finalizado(false) {
    srand(static_cast<unsigned>(time(nullptr)));
}

SimuladorTorneo::~SimuladorTorneo() {
    for (auto s : participantes) delete s;
}

bool SimuladorTorneo::esPotenciaDeDos(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void SimuladorTorneo::agregarSeleccion(Seleccion* s) {
    if (finalizado) throw TorneoFinalizadoException();
    participantes.push_back(s);
}

Seleccion* SimuladorTorneo::simularPartido(Seleccion* a, Seleccion* b) {
    double fuerzaA = a->calcularFuerza();
    double fuerzaB = b->calcularFuerza();
    double total   = fuerzaA + fuerzaB;

    // Número aleatorio ponderado por fuerza
    double aleatorio = (rand() % 1000) / 1000.0 * total;
    return (aleatorio < fuerzaA) ? a : b;
}

void SimuladorTorneo::simularFase(const string& nombreFase) {
    if (participantes.size() < 2)
        throw FaseNoIniciadaException();
    if (!esPotenciaDeDos((int)participantes.size()))
        throw NumeroEquiposInvalidoException((int)participantes.size());

    string registro = "\n--- " + nombreFase + " ---\n";
    vector<Seleccion*> clasificados;

    for (size_t i = 0; i < participantes.size(); i += 2) {
        Seleccion* a = participantes[i];
        Seleccion* b = participantes[i + 1];
        Seleccion* ganador = simularPartido(a, b);

        registro += a->getNombre() + " vs " + b->getNombre() + "  =>  Gana: " + ganador->getNombre() + "\n";
        clasificados.push_back(ganador);
    }

    historialFases.push_back(registro);
    participantes = clasificados;

    cout << registro;
}

void SimuladorTorneo::simularTorneoCompleto() {
    if (!esPotenciaDeDos((int)participantes.size()))
        throw NumeroEquiposInvalidoException((int)participantes.size());

    vector<string> fases = {"Octavos de Final", "Cuartos de Final",
                             "Semifinal", "Final"};
    int indiceFase = (int)log2(participantes.size()) - 1;

    while (participantes.size() > 1) {
        string fase = (indiceFase < (int)fases.size()) ? fases[indiceFase++] : "Fase Extra";
        simularFase(fase);
    }

    cout << "\n*** CAMPEON DEL MUNDO: ";
    participantes[0]->mostrar();
    cout << " ***" << endl;

    finalizado = true;
}

void SimuladorTorneo::mostrarHistorial() const {
    cout << "\n=== HISTORIAL DEL TORNEO ===" << endl;
    for (const auto& fase : historialFases)
        cout << fase;
}
