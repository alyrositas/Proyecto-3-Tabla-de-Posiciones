#ifndef RESULTADO_H
#define RESULTADO_H

#include <string>
#include <iostream>
using namespace std;

class Resultado {
private:
    int golesLocal;
    int golesVisitante;

public:
    Resultado(int local = 0, int visitante = 0);

    int getGolesLocal() const;
    int getGolesVisitante() const;

    // Sobrecarga: sumar marcadores (ej. resultado global de doble partido)
    Resultado operator+(const Resultado& otro) const;

    // Sobrecarga: comparar si un resultado es victoria del local (>), empate (==), derrota (<)
    bool operator>(const Resultado& otro) const;
    bool operator<(const Resultado& otro) const;
    bool operator==(const Resultado& otro) const;

    // Sobrecarga: imprimir resultado
    friend ostream& operator<<(ostream& os, const Resultado& r);
};

#endif
