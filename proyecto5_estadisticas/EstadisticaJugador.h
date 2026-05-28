#ifndef ESTADISTICA_JUGADOR_H
#define ESTADISTICA_JUGADOR_H

#include "EstadisticaBase.h"

class EstadisticaJugador : public EstadisticaBase {
private:
    int goles;
    int asistencias;
    int tarjetasAmarillas;
    int tarjetasRojas;
    int minutosjugados;

public:
    EstadisticaJugador(string nombre);

    void registrarGol();
    void registrarAsistencia();
    void registrarTarjeta(bool esRoja = false);
    void agregarMinutos(int minutos);

    int getGoles() const;
    int getAsistencias() const;
    double getPromedioGoles() const;

    // Rendimiento = goles + asistencias - tarjetas
    double calcularRendimiento() const override;
    void mostrarResumen() const override;

    EstadisticaJugador& operator+=(const EstadisticaJugador& otro);
    friend ostream& operator<<(ostream& os, const EstadisticaJugador& e);
};

#endif
