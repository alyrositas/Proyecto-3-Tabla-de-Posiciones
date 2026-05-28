#ifndef GRUPO_MUNDIAL_H
#define GRUPO_MUNDIAL_H

#include "EquipoGrupo.h"
#include "MundialException.h"
#include <vector>
using namespace std;

class GrupoMundial {
private:
    string nombreGrupo;
    vector<EquipoGrupo> equipos;

    EquipoGrupo& buscarEquipo(const string& nombre);

public:
    GrupoMundial(string nombre);

    void agregarEquipo(const string& nombre);
    void registrarPartido(const string& local, int gLocal,
                          const string& visitante, int gVisitante);
    void mostrarTabla() const;
};

#endif
