#include "Emmiter.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

// Constructor
Emmiter::Emmiter(const EmmiterConfiguration& config)
    : config(config),
    initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())),
    lastUpdateTime(0) {
    std::srand(std::time(nullptr));  // Establecer la semilla para la aleatoriedad
}

// Destructor
Emmiter::~Emmiter() {
    for (auto particula : particulas) {
        delete particula;  // Liberar la memoria de las partículas
    }
}

// Implementación del método Render() que invoca Render en todas las partículas
void Emmiter::Render() {
    for (auto p : particulas) {
        p->Render();  // Renderizar cada partícula
    }
}

// Implementación del método Update() que controla la frecuencia de emisión y crea nuevas partículas
void Emmiter::Update() {
    // Obtener el tiempo actual
    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());


    // Verificar si ha pasado el tiempo de emisión configurado
    if (currentTime.count() - this->initialMilliseconds.count() - this->lastUpdateTime > this->config.GetTiempoEmision() && particulas.size() < config.GetNumParticulas()) {
        // Crear nueva partícula clonando la partícula de referencia
        Solid* newParticle = config.GetParticula()->Clone();

        // Modificar las propiedades de la partícula (puedes poner valores aleatorios o deterministas)
        newParticle->SetPosition(Vector3D(0.0, 0.0, -10.0));  // Posición dispersa
        newParticle->SetColor(Color((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f));  // Color aleatorio
        newParticle->SetOrientation(Vector3D(rand() % 360, rand() % 360, rand() % 360));  // Orientación aleatoria
        newParticle->SetOrientationSpeed(Vector3D(
            (rand() % 10 - 5) / 10.0f,  // Rango reducido para que gire más despacio
            (rand() % 10 - 5) / 10.0f, 
            (rand() % 10 - 5) / 10.0f)); 
        // Velocidad fija para todas las partículas (ajustar según necesidad)
        Vector3D velocity((rand() % 100 - 50) / 10000.0f,
            (rand() % 100 - 50) / 10000.0f,
            (rand() % 100 - 50) / 10000.0f);  // Velocidad constante
        newParticle->SetVelocity(velocity);  // Asignar la velocidad a la partícula

        // Añadir la nueva partícula al vector
        particulas.push_back(newParticle);

        // Actualizar el tiempo del último update
        this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
    }

    // Actualizar todas las partículas
    for (auto p : particulas) {
        // Mover las partículas en su dirección de velocidad
        Vector3D position = p->GetPosition();
        Vector3D velocity = p->GetVelocity();
        position = position + velocity;  // Desplazar la partícula

        // Rebote cuando la partícula se sale de los límites (ajustar los valores de los límites si es necesario)
        if (position.x < -25 || position.x > 25) velocity.x *= -1;  // Rebote en el eje X
        if (position.y < -25 || position.y > 25) velocity.y *= -1;  // Rebote en el eje Y
        if (position.z < -25 || position.z > 25) velocity.z *= -1;  // Rebote en el eje Z

        // Actualizar la posición de la partícula
        p->SetPosition(position);
        p->SetVelocity(velocity);  // Actualizar la velocidad

        // Actualizar la partícula (como lo harías normalmente en el método Update)
        p->Update();
    }
}

