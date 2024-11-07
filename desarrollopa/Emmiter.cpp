#include "Emmiter.h"

// Constructor
Emmiter::Emmiter(const EmmiterConfiguration& config)
    : config(config),
    initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())),
    lastUpdateTime(0) {}

// Destructor
Emmiter::~Emmiter() {
    // Liberamos la memoria de las partículas
    for (auto particula : particulas) {
        delete particula;
    }
}

// Implementación del método Render() que invoca Render en todas las partículas
void Emmiter::Render() {
    for (auto p : particulas) {
        p->Render();  // Renderizamos cada partícula
    }
}

// Implementación del método Update() que controla la frecuencia de emisión y crea nuevas partículas
void Emmiter::Update() {
    // Obtener el tiempo actual
    auto currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    // Verifica si ha pasado el tiempo de emisión configurado
    if (currentTime - lastUpdateTime >= config.GetTiempoEmision()) {
        // Crear nueva partícula clonando la partícula de referencia
        Solid* newParticle = config.GetParticula()->Clone();

        // Modificar las propiedades de la nueva partícula (ejemplo con valores aleatorios)
        newParticle->SetPosition(Vector3D(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 50));
        newParticle->SetColor(Color((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f));  // Color aleatorio
        newParticle->SetOrientation(Vector3D(rand() % 360, rand() % 360, rand() % 360));  // Orientación aleatoria

        // Añadir la nueva partícula al vector
        particulas.push_back(newParticle);

        // Actualizar el tiempo del último update
        lastUpdateTime = currentTime;
    }

    // Actualizar todas las partículas
    for (auto p : particulas) {
        p->Update();  // Actualizar el estado de cada partícula
    }
}
