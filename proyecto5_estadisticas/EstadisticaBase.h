#ifndef ESTADISTICA_BASE_H
#define ESTADISTICA_BASE_H

#include "EstadisticaException.h"
#include <string>
#include <iostream>
using namespace std;

// Interfaz para cualquier entidad con estadísticas
class IEstadistica {
public:
    virtual double calcularRendimiento() const = 0;
    virtual void mostrarResumen() const = 0;
    virtual string getNombre() const = 0;
    virtual ~IEstadistica() = default;
};

// Clase base con datos comunes de estadística
class EstadisticaBase : public IEstadistica {
protected:
    string nombre;
    int partidosJugados;

public:
    EstadisticaBase(string nombre);

    string getNombre() const override;
    int getPartidosJugados() const;
    void incrementarPartidos();

    // Sobrecarga: sumar estadísticas
    virtual EstadisticaBase& operator+=(const EstadisticaBase& otro);

    // Sobrecarga: comparar por rendimiento
    bool operator>(const EstadisticaBase& otro) const;
    bool operator==(const EstadisticaBase& otro) const;

    friend ostream& operator<<(ostream& os, const EstadisticaBase& e);
};

#endif
