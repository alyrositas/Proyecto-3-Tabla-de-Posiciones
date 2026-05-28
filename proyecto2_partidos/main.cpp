#include <iostream>
#include <vector>
#include "Partido.h"
using namespace std;

int main() {
    vector<Partido> jornada = {
        Partido("Argentina", "Arabia Saudita", Resultado(1, 2), "Grupos"),
        Partido("Francia",   "Australia",      Resultado(4, 1), "Grupos"),
        Partido("Brasil",    "Serbia",          Resultado(2, 0), "Grupos"),
        Partido("Alemania",  "Japon",           Resultado(1, 2), "Grupos"),
    };

    cout << "=== RESULTADOS DE LA JORNADA ===" << endl;
    for (const auto& p : jornada)
        p.mostrar();

    // Demostrar operator+: marcador global de ida y vuelta
    Resultado ida(1, 0);
    Resultado vuelta(0, 2);
    Resultado global = ida + vuelta;
    cout << "\n=== ELIMINATORIA (ida + vuelta) ===" << endl;
    cout << "Ida:    " << ida    << endl;
    cout << "Vuelta: " << vuelta << endl;
    cout << "Global: " << global << endl;

    // Demostrar operator> y operator==
    Resultado r1(3, 0), r2(2, 1);
    cout << "\n=== COMPARACION DE RESULTADOS ===" << endl;
    cout << r1 << (r1 > r2 ? " es mejor que " : " NO es mejor que ") << r2 << endl;
    cout << r1 << (r1 == r2 ? " empatan en diferencia con " : " difiere de ") << r2 << endl;

    // Partido más goleador (usando operator>)
    Partido& mejorPartido = jornada[0];
    for (auto& p : jornada)
        if (p > mejorPartido) mejorPartido = p;

    cout << "\n=== PARTIDO MAS GOLEADOR ===" << endl;
    cout << mejorPartido << endl;

    return 0;
}
