#ifndef ESTADISTICA_EQUIPO_H
#define ESTADISTICA_EQUIPO_H

#include "EstadisticaBase.h"
#include "EstadisticaJugador.h"
#include <vector>
#include <map>
using namespace std;

class EstadisticaEquipo : public EstadisticaBase {
private:
    int golesAFavor;
    int golesEnContra;
    int victorias;
    int empates;
    int derrotas;
    map<string, EstadisticaJugador*> jugadores;

public:
    EstadisticaEquipo(string nombre);
    ~EstadisticaEquipo();

    void agregarJugador(const string& nombre);
    EstadisticaJugador& getJugador(const string& nombre);

    void registrarResultado(int gf, int gc);

    double calcularRendimiento() const override;
    void mostrarResumen() const override;
    void mostrarTablajugadores() const;
};

#endif
