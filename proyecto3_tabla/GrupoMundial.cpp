#include "GrupoMundial.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

GrupoMundial::GrupoMundial(string nombre) : nombreGrupo(nombre) {}

EquipoGrupo& GrupoMundial::buscarEquipo(const string& nombre) {
    for (auto& e : equipos)
        if (e.nombre == nombre) return e;
    throw EquipoNoEncontradoException(nombre);
}

void GrupoMundial::agregarEquipo(const string& nombre) {
    if (equipos.size() >= 4)
        throw GrupoLlenoException(nombreGrupo);
    for (const auto& e : equipos)
        if (e.nombre == nombre) throw EquipoDuplicadoException(nombre);
    equipos.emplace_back(nombre);
}

void GrupoMundial::registrarPartido(const string& local, int gLocal,
                                     const string& visitante, int gVisitante) {
    EquipoGrupo& eLocal     = buscarEquipo(local);
    EquipoGrupo& eVisitante = buscarEquipo(visitante);

    if (gLocal > gVisitante) {
        eLocal.registrarVictoria(gLocal, gVisitante);
        eVisitante.registrarDerrota(gVisitante, gLocal);
    } else if (gLocal < gVisitante) {
        eLocal.registrarDerrota(gLocal, gVisitante);
        eVisitante.registrarVictoria(gVisitante, gLocal);
    } else {
        eLocal.registrarEmpate(gLocal, gVisitante);
        eVisitante.registrarEmpate(gVisitante, gLocal);
    }
}

void GrupoMundial::mostrarTabla() const {
    vector<EquipoGrupo> tabla = equipos;
    sort(tabla.begin(), tabla.end(),
         [](const EquipoGrupo& a, const EquipoGrupo& b) { return a > b; });

    cout << "\n=== GRUPO " << nombreGrupo << " ===" << endl;
    cout << left << setw(18) << "Equipo"
         << setw(4) << "PJ" << setw(4) << "PG" << setw(4) << "PE"
         << setw(4) << "PP" << setw(4) << "GF" << setw(4) << "GC"
         << setw(5) << "DG" << setw(4) << "PTS" << endl;
    cout << string(55, '-') << endl;

    for (const auto& e : tabla) {
        cout << left << setw(18) << e.nombre
             << setw(4) << e.pj << setw(4) << e.pg << setw(4) << e.pe
             << setw(4) << e.pp << setw(4) << e.gf << setw(4) << e.gc
             << setw(5) << e.diferenciaGoles() << setw(4) << e.puntos << endl;
    }
}
