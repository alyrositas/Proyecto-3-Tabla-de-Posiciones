# Proyectos Prácticos — Mundial de Fútbol
## Programación Orientada a Objetos en C++

> Cada proyecto tiene una base de código ya proporcionada. Tu trabajo es **extenderla** siguiendo las instrucciones de cada sección.

---

## Contenidos evaluados

| Tópico | Proyecto(s) |
|---|---|
| Herencia y diseño de POO | 1, 4, 5 |
| Modificadores de acceso | 1, 5 |
| Sobrecarga y sobreescritura de métodos | 1, 4 |
| Polimorfismo y clases abstractas | 1, 4, 5 |
| Interfaces | 5 |
| Sobrecarga de operadores | 2, 3, 5 |
| Manejo de excepciones | 3, 4, 5 |

---

---

# Proyecto 1 — Plantilla de Selección
### Tópicos: Herencia · Polimorfismo · Clases abstractas · Sobreescritura

## Descripción

Se tiene la base de una jerarquía de clases para gestionar los integrantes de una selección de fútbol. El sistema ya incluye las clases `Persona`, `Jugador`, `Delantero`, `Portero` y `DT`.

## Jerarquía existente

```
Persona  (abstracta)
├── Jugador  (abstracta)
│   ├── Delantero
│   └── Portero
└── DT
```

## Tareas a implementar

### Tarea 1 — Nueva clase: `Mediocampista`
Crea el archivo `Mediocampista.h` y `Mediocampista.cpp`. Esta clase hereda de `Jugador` y debe:
- Agregar el atributo privado `int pasesCompletados`
- Implementar el método `void completarPase(int cantidad = 1)`
- Implementar `int getPasesCompletados() const`
- Sobreescribir `getPosicion()` retornando `"Mediocampista"`
- Sobreescribir `mostrarInfo()` mostrando los datos base del jugador **más** los pases completados

### Tarea 2 — Nueva clase: `Defensor`
De manera similar, crea la clase `Defensor` con:
- Atributo privado `int despejes`
- Método `void despejar()`
- Sobreescritura de `getPosicion()` y `mostrarInfo()`

### Tarea 3 — Modificar `main.cpp`
- Agrega al menos un `Mediocampista` y un `Defensor` al vector `plantilla`
- Demuestra que el bucle polimórfico sigue funcionando sin cambios (solo agrega los objetos)
- Usa `dynamic_cast` para llamar métodos específicos de cada clase derivada
- Imprime cuántos jugadores del campo (no DT, no portero) hay en la plantilla

### Tarea 4 — Clase abstracta `Integrante` (refactor)
Analiza la diferencia entre `Persona` y la interfaz de un integrante de selección. Responde en un comentario al inicio de `Persona.h`:
1. ¿Por qué `getRol()` y `mostrarInfo()` son métodos puramente virtuales?
2. ¿Qué pasaría si intentaras crear un objeto `Persona` directamente?
3. ¿Cuál es la diferencia entre `protected` y `private` en `Jugador`?

## Criterios de evaluación

| Criterio | Puntaje |
|---|---|
| `Mediocampista` implementada correctamente | 25% |
| `Defensor` implementada correctamente | 25% |
| `main.cpp` actualizado con polimorfismo | 30% |
| Respuestas en comentarios (Tarea 4) | 20% |

---

---

# Proyecto 2 — Resultados de Partidos
### Tópicos: Sobrecarga de operadores

## Descripción

El sistema ya permite representar `Resultado` y `Partido` con operadores sobrecargados básicos. Debes extenderlo para cubrir más escenarios del mundial.

## Tareas a implementar

### Tarea 1 — Operador `!=` en `Resultado`
Agrega la declaración en `Resultado.h` e implementación en `Resultado.cpp`:
```cpp
bool operator!=(const Resultado& otro) const;
```
Dos resultados son distintos si su diferencia de goles es diferente.

### Tarea 2 — Operador `[]` en `Partido`
Agrega un operador de indexación que retorne los goles de cada equipo:
```cpp
int operator[](int indice) const;
// indice 0 = goles local, indice 1 = goles visitante
// Si el indice es inválido, retorna -1
```

### Tarea 3 — Clase `JornadaMundial`
Crea `JornadaMundial.h` y `JornadaMundial.cpp` con:
- Un `vector<Partido>` de partidos de la jornada
- Método `void agregarPartido(const Partido& p)`
- Sobrecarga del operador `+=` para agregar un partido: `jornada += partido`
- Sobrecarga del operador `<<` para imprimir todos los partidos de la jornada
- Método `Partido getMasGoleador() const` — retorna el partido con mayor suma de goles

### Tarea 4 — Demostración en `main.cpp`
Crea una jornada con mínimo 6 partidos y demuestra **todos** los operadores implementados con ejemplos comentados que expliquen qué hace cada uno.

## Criterios de evaluación

| Criterio | Puntaje |
|---|---|
| Operador `!=` correcto | 15% |
| Operador `[]` correcto | 20% |
| Clase `JornadaMundial` completa | 40% |
| Demostración clara en `main.cpp` | 25% |

---

---

# Proyecto 3 — Tabla de Posiciones
### Tópicos: Excepciones personalizadas · Sobrecarga de operadores

## Descripción

El sistema ya gestiona un grupo con su tabla de posiciones y lanza excepciones ante errores. Debes agregar validaciones adicionales y permitir gestionar múltiples grupos.

## Tareas a implementar

### Tarea 1 — Nueva excepción: `PartidoDuplicadoException`
En `MundialException.h` agrega una excepción que se lance cuando se intente registrar dos veces el mismo partido entre los mismos equipos en la misma jornada.

Criterio: si los equipos `A` vs `B` ya jugaron, lanzar la excepción si se vuelve a registrar `A` vs `B` o `B` vs `A`.

### Tarea 2 — Control de partidos en `GrupoMundial`
Modifica `GrupoMundial` para:
- Llevar registro de los partidos ya jugados (`vector<pair<string,string>>`)
- Lanzar `PartidoDuplicadoException` cuando corresponda
- Agregar método `bool yaJugaron(const string& e1, const string& e2) const`

### Tarea 3 — Clase `FaseDeFase` con múltiples grupos
Crea la clase `FaseDeGrupos` con:
- Un `map<string, GrupoMundial>` para almacenar grupos (A, B, C, …)
- Método `void agregarGrupo(const string& letra)`
- Método `void registrarPartidoEnGrupo(const string& grupo, ...)` — debe capturar y relanzar excepciones con información adicional del grupo
- Método `void mostrarTodos() const`
- Operador `[]` para acceder a un grupo: `fase["A"]`

### Tarea 4 — `main.cpp` actualizado
Simula la fase de grupos de un mundial con al menos 2 grupos (8 equipos, 6 partidos por grupo). Demuestra el lanzamiento y captura de **todas** las excepciones definidas.

### Pregunta de análisis (en comentario al inicio de `main.cpp`)
¿Por qué se usa `catch (const MundialException& e)` como captura genérica al final? ¿Qué principio de POO lo hace posible?

## Criterios de evaluación

| Criterio | Puntaje |
|---|---|
| `PartidoDuplicadoException` funcional | 20% |
| Detección de partido duplicado en `GrupoMundial` | 25% |
| Clase `FaseDeGrupos` completa | 35% |
| Demostración y pregunta de análisis | 20% |

---

---

# Proyecto 4 — Simulador de Torneo Eliminatorio
### Tópicos: Herencia · Polimorfismo · Excepciones · Sobrecarga de operadores

## Descripción

El simulador ya puede correr un torneo completo con tres tipos de selecciones. Debes agregar un nuevo tipo de selección, mejorar el sistema de excepciones y agregar estadísticas por fase.

## Tareas a implementar

### Tarea 1 — Nueva subclase: `SeleccionDefensiva`
Crea la clase `SeleccionDefensiva` que hereda de `Seleccion`:
- Atributo privado `double coeficienteDefensivo` (valor entre 1.0 y 1.3)
- Su `calcularFuerza()` penaliza al rival en la simulación: la fuerza se calcula normal, pero al enfrentarse a este equipo el rival tiene -10% (pista: ajusta la lógica en `simularPartido`)
- Sobreescribe `mostrar()` indicando `[DEFENSIVA]`

### Tarea 2 — Registro de resultados por fase
Modifica `SimuladorTorneo` para que además del historial de texto, guarde un `vector<pair<string,string>>` con los pares (ganador, perdedor) de cada partido. Agrega el método:
```cpp
void mostrarEstadisticasFases() const;
// Imprime cuántos partidos se jugaron en total y quién ganó más veces seguidas
```

### Tarea 3 — Excepción `TorneoVacioException`
Agrega en `TorneoException.h` una excepción que se lance cuando se intente simular sin haber agregado equipos.

### Tarea 4 — Operador `<<` en `SimuladorTorneo`
Sobrecarga el operador `<<` para imprimir un resumen del torneo: nombre de los equipos participantes y el estado actual (en curso / finalizado).

### Tarea 5 — `main.cpp` ampliado
- Incluye al menos un equipo de cada tipo (`Seleccion`, `SeleccionLocal`, `SeleccionEstrella`, `SeleccionDefensiva`)
- Corre el torneo completo y muestra las estadísticas de fases
- Demuestra las tres excepciones: `TorneoVacioException`, `TorneoFinalizadoException`, `NumeroEquiposInvalidoException`

## Criterios de evaluación

| Criterio | Puntaje |
|---|---|
| `SeleccionDefensiva` implementada | 25% |
| Registro de resultados y estadísticas | 25% |
| `TorneoVacioException` funcional | 15% |
| Operador `<<` en `SimuladorTorneo` | 15% |
| `main.cpp` completo y bien documentado | 20% |

---

---

# Proyecto 5 — Sistema Integral de Estadísticas
### Tópicos: Interfaces · Herencia · Polimorfismo · Sobrecarga · Excepciones

## Descripción

Este proyecto integra todos los tópicos. Ya existe una jerarquía completa con `IEstadistica` → `EstadisticaBase` → `EstadisticaJugador` / `EstadisticaEquipo`. Debes agregar estadísticas de árbitro, un generador de reportes y ampliar el manejo de excepciones.

## Tareas a implementar

### Tarea 1 — Nueva clase: `EstadisticaArbitro`
Crea `EstadisticaArbitro.h` y `EstadisticaArbitro.cpp`. Hereda de `EstadisticaBase` e implementa `IEstadistica`:
- Atributos privados: `int tarjetasAmarillas`, `int tarjetasRojas`, `int penalesCobrados`
- Métodos: `void cobrarTarjeta(bool esRoja)`, `void cobrarPenal()`
- `calcularRendimiento()`: promedio de decisiones por partido. Lanza `DivisionPorCeroException` si no hay partidos
- `mostrarResumen()`: imprime todos sus atributos

### Tarea 2 — Operador `-=` en `EstadisticaJugador`
A veces se anulan estadísticas (VAR). Implementa:
```cpp
EstadisticaJugador& operator-=(const EstadisticaJugador& otro);
```
Debe lanzar `ValorNegativoException` si el resultado de cualquier campo queda negativo.

### Tarea 3 — Clase `ReporteMundial`
Crea `ReporteMundial.h` y `ReporteMundial.cpp`:
- Almacena un `vector<IEstadistica*>` con jugadores, equipos y árbitros mezclados
- Método `void agregar(IEstadistica* e)`
- Método `void generarRanking() const` — ordena e imprime todos los elementos por `calcularRendimiento()` usando el operador `>` sobreescargado
- Método `IEstadistica* getMejor() const` — retorna el de mayor rendimiento. Lanza una excepción propia `ReporteVacioException` si el vector está vacío
- Operador `+=` para agregar un elemento al reporte

### Tarea 4 — Nueva excepción: `ReporteVacioException`
Agrégala en `EstadisticaException.h`.

### Tarea 5 — `main.cpp` ampliado
Crea un reporte con al menos:
- 3 jugadores de distintos equipos
- 2 equipos
- 1 árbitro
Genera el ranking completo y demuestra todas las excepciones del sistema.

### Pregunta de análisis (en comentario al inicio de `main.cpp`)
Explica con tus palabras:
1. ¿Por qué `ReporteMundial` usa `vector<IEstadistica*>` y no `vector<IEstadistica>`?
2. ¿Qué ocurriría si `calcularRendimiento()` no fuera virtual?

## Criterios de evaluación

| Criterio | Puntaje |
|---|---|
| `EstadisticaArbitro` implementada | 20% |
| Operador `-=` con validación | 15% |
| Clase `ReporteMundial` completa | 35% |
| `ReporteVacioException` funcional | 10% |
| Pregunta de análisis respondida | 20% |

---

---

## Normas generales

### Entrega
- Entregar **todos los archivos fuente** (`.h` y `.cpp`) en un archivo comprimido `.zip` con el nombre `Apellido_Nombre_ProyectoN.zip`
- El código debe **compilar sin errores** con el comando `make` incluido en cada proyecto
- Se descuenta puntaje por **warnings** no justificados

### Restricciones
- No usar librerías externas. Solo la STL estándar de C++17
- No modificar las clases base ya implementadas salvo donde las instrucciones lo indiquen explícitamente
- No usar `goto` ni variables globales

### Buenas prácticas obligatorias
- Cada archivo `.h` debe tener guardas de inclusión (`#ifndef / #define / #endif`)
- Los destructores de clases con herencia deben ser `virtual`
- Liberar toda memoria dinámica (`delete`) antes de terminar el programa
- Los métodos que no modifican el objeto deben ser `const`

### Compilación
Todos los proyectos usan el mismo comando desde la carpeta del proyecto:
```bash
make        # compilar
make clean  # limpiar ejecutable
```

---

## Referencia rápida de tópicos

### Sobreescritura vs Sobrecarga
| | Sobreescritura | Sobrecarga |
|---|---|---|
| Mismo nombre | Sí | Sí |
| Misma firma | **Sí** | No |
| Requiere herencia | **Sí** | No |
| Palabra clave | `override` | — |

### Cuándo usar `virtual`
- Siempre que una clase base deba permitir que sus subclases cambien el comportamiento de un método
- El destructor de toda clase base con herencia debe ser `virtual`

### Jerarquía de excepciones del proyecto
```
std::exception
└── MundialException / TorneoException / EstadisticaException
    ├── EquipoNoEncontradoException
    ├── GrupoLlenoException
    ├── PartidoDuplicadoException      ← Tarea 3-1
    ├── PuntosNegativosException
    ├── FaseNoIniciadaException
    ├── NumeroEquiposInvalidoException
    ├── TorneoFinalizadoException
    ├── TorneoVacioException           ← Tarea 4-3
    ├── ValorNegativoException
    ├── DivisionPorCeroException
    ├── JugadorNoExisteException
    └── ReporteVacioException          ← Tarea 5-4
```
