#include "Emmiter.h"
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <iostream>

// Constructor de Emmiter
Emmiter::Emmiter(const EmmiterConfiguration& config)
    : config(config),
    initialMilliseconds(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch())),
    lastUpdateTime(0) {
    // Semilla para números aleatorios
    srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Destructor
Emmiter::~Emmiter() {
    for (auto particula : particulas) {
        delete particula;
    }
}

// Renderiza todas las partículas
void Emmiter::Render() {
    for (auto p : particulas) {
        p->Render();
    }
}

// Actualiza el emisor y genera nuevas partículas según el tiempo de emisión
void Emmiter::Update() {
    // Obtener el tiempo actual en milisegundos
    auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();

    // Verificar si ha pasado el tiempo de emisión y si no se ha alcanzado el número máximo de partículas
    if (currentTime - lastUpdateTime >= config.GetTiempoEmision() && particulas.size() <= config.GetNumParticulas()) {
        // Clonar la partícula de referencia
        Solid* newParticle = config.GetParticula()->Clone();

        // Configurar propiedades aleatorias de la partícula
        newParticle->SetPosition(Vector3D(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50));
        newParticle->SetColor(Color(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            1.0f));
        newParticle->SetOrientation(Vector3D(rand() % 360, rand() % 360, rand() % 360));

        // Agregar la partícula al vector de partículas
        particulas.push_back(newParticle);

        // Actualizar el tiempo del último update
        lastUpdateTime = currentTime;
    }

    // Actualizar todas las partículas existentes
    for (auto p : particulas) {
        p->Update();
    }
}
