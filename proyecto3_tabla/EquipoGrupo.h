#ifndef EQUIPO_GRUPO_H
#define EQUIPO_GRUPO_H

#include <string>
using namespace std;

struct EquipoGrupo {
    string nombre;
    int puntos;
    int pj;   // partidos jugados
    int pg;   // partidos ganados
    int pe;   // partidos empatados
    int pp;   // partidos perdidos
    int gf;   // goles a favor
    int gc;   // goles en contra

    EquipoGrupo(string nombre);

    int diferenciaGoles() const;
    void registrarVictoria(int gf, int gc);
    void registrarEmpate(int gf, int gc);
    void registrarDerrota(int gf, int gc);

    // Sobrecarga para ordenar la tabla
    bool operator>(const EquipoGrupo& otro) const;
    bool operator==(const EquipoGrupo& otro) const;
};

#endif
