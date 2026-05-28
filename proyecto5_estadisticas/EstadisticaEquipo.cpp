#include "EstadisticaEquipo.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

EstadisticaEquipo::EstadisticaEquipo(string nombre)
    : EstadisticaBase(nombre), golesAFavor(0), golesEnContra(0),
      victorias(0), empates(0), derrotas(0) {}

EstadisticaEquipo::~EstadisticaEquipo() {
    for (auto& par : jugadores) delete par.second;
}

void EstadisticaEquipo::agregarJugador(const string& nombre) {
    jugadores[nombre] = new EstadisticaJugador(nombre);
}

EstadisticaJugador& EstadisticaEquipo::getJugador(const string& nombre) {
    auto it = jugadores.find(nombre);
    if (it == jugadores.end()) throw JugadorNoExisteException(nombre);
    return *(it->second);
}

void EstadisticaEquipo::registrarResultado(int gf, int gc) {
    if (gf < 0) throw ValorNegativoException("goles a favor");
    if (gc < 0) throw ValorNegativoException("goles en contra");
    golesAFavor   += gf;
    golesEnContra += gc;
    partidosJugados++;
    if (gf > gc) victorias++;
    else if (gf == gc) empates++;
    else derrotas++;
}

double EstadisticaEquipo::calcularRendimiento() const {
    if (partidosJugados == 0) return 0.0;
    int puntos = victorias * 3 + empates;
    return static_cast<double>(puntos) / (partidosJugados * 3) * 100.0;
}

void EstadisticaEquipo::mostrarResumen() const {
    cout << "\n--- " << nombre << " ---" << endl;
    cout << "PJ:" << partidosJugados << " V:" << victorias
         << " E:" << empates << " D:" << derrotas
         << " | GF:" << golesAFavor << " GC:" << golesEnContra
         << " | Rendimiento: " << fixed << setprecision(1)
         << calcularRendimiento() << "%" << endl;
}

void EstadisticaEquipo::mostrarTablajugadores() const {
    // Ordenar jugadores por rendimiento
    vector<EstadisticaJugador*> lista;
    for (const auto& par : jugadores) lista.push_back(par.second);
    sort(lista.begin(), lista.end(),
         [](const EstadisticaJugador* a, const EstadisticaJugador* b) {
             return *a > *b;
         });

    cout << "\n  Jugadores de " << nombre << ":" << endl;
    for (const auto& j : lista)
        j->mostrarResumen();
}
