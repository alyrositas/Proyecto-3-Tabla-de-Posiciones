#ifndef MUNDIAL_EXCEPTION_H
#define MUNDIAL_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class MundialException : public exception {
protected:
    string mensaje;
public:
    MundialException(const string& msg) : mensaje(msg) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class EquipoNoEncontradoException : public MundialException {
public:
    EquipoNoEncontradoException(const string& equipo)
        : MundialException("Equipo no encontrado: " + equipo) {}
};

class PuntosNegativosException : public MundialException {
public:
    PuntosNegativosException()
        : MundialException("Los puntos no pueden ser negativos") {}
};

class GrupoLlenoException : public MundialException {
public:
    GrupoLlenoException(const string& grupo)
        : MundialException("El grupo " + grupo + " ya tiene 4 equipos") {}
};

class EquipoDuplicadoException : public MundialException {
public:
    EquipoDuplicadoException(const string& equipo)
        : MundialException("El equipo ya existe en el grupo: " + equipo) {}
};

#endif
