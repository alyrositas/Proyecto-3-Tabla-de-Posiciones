#ifndef ESTADISTICA_EXCEPTION_H
#define ESTADISTICA_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class EstadisticaException : public exception {
protected:
    string mensaje;
public:
    EstadisticaException(const string& msg) : mensaje(msg) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class ValorNegativoException : public EstadisticaException {
public:
    ValorNegativoException(const string& campo)
        : EstadisticaException("El campo '" + campo + "' no puede ser negativo") {}
};

class DivisionPorCeroException : public EstadisticaException {
public:
    DivisionPorCeroException()
        : EstadisticaException("Division por cero: no hay partidos jugados") {}
};

class JugadorNoExisteException : public EstadisticaException {
public:
    JugadorNoExisteException(const string& nombre)
        : EstadisticaException("Jugador no registrado: " + nombre) {}
};

#endif
