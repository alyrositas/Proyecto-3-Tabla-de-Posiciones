#ifndef SIMULADOR_TORNEO_H
#define SIMULADOR_TORNEO_H

#include "Seleccion.h"
#include "TorneoException.h"
#include <vector>
#include <string>
using namespace std;

class SimuladorTorneo {
private:
    vector<Seleccion*> participantes;
    vector<string> historialFases;
    bool finalizado;

    // Simula un partido y retorna el ganador (basado en fuerza + aleatoriedad)
    Seleccion* simularPartido(Seleccion* a, Seleccion* b);
    bool esPotenciaDeDos(int n);

public:
    SimuladorTorneo();
    ~SimuladorTorneo();

    void agregarSeleccion(Seleccion* s);
    void simularFase(const string& nombreFase);
    void simularTorneoCompleto();
    void mostrarHistorial() const;
};

#endif
