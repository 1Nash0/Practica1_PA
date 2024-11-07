#pragma once
#include "Solid.h"

class EmmiterConfiguration {
private:
    int numParticulas;            // Número máximo de partículas
    int tiempoEmision;            // Intervalo de tiempo de emisión en milisegundos
    Solid* particulaRef;          // Partícula de referencia

public:
    // Constructor que acepta los tres parámetros necesarios
    EmmiterConfiguration(int numParticulas, int tiempoEmision, Solid* particulaRef)
        : numParticulas(numParticulas), tiempoEmision(tiempoEmision), particulaRef(particulaRef) {}

    // Métodos de acceso
    int GetNumParticulas() const { return numParticulas; }
    int GetTiempoEmision() const { return tiempoEmision; }
    Solid* GetParticula() const { return particulaRef; }
};


