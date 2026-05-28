#ifndef TORNEO_EXCEPTION_H
#define TORNEO_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class TorneoException : public exception {
protected:
    string mensaje;
public:
    TorneoException(const string& msg) : mensaje(msg) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class FaseNoIniciadaException : public TorneoException {
public:
    FaseNoIniciadaException()
        : TorneoException("La fase no ha sido iniciada aun") {}
};

class NumeroEquiposInvalidoException : public TorneoException {
public:
    NumeroEquiposInvalidoException(int n)
        : TorneoException("Numero de equipos invalido: " + to_string(n) + ". Debe ser potencia de 2") {}
};

class TorneoFinalizadoException : public TorneoException {
public:
    TorneoFinalizadoException()
        : TorneoException("El torneo ya ha finalizado") {}
};

#endif
