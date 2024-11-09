#include "Game.h"
#include <iostream>           
#include "Emmiter.h"
#include "EmmiterConfiguration.h"
#include <ctime> 

void Game::Init() {

    srand(static_cast<unsigned int>(time(nullptr)));  // Inicializamos la semilla de los números aleatorios

    cout << "[GAME] Init..." << endl;

    // Configuramos el emisor
    int numParticulas = 10000;                    // Número máximo de partículas
    int tiempoEmision = 500;                   // Intervalo de emisión en ms
    Solid* particulaRef = new Cube();        // Partícula de referencia, un objeto de tipo Sphere


    EmmiterConfiguration Config(numParticulas, tiempoEmision, particulaRef);
       // Crear el emisor
    Emmiter* emisor = new Emmiter(Config);
    this->mainScene.AddGameObject(emisor);     // Agregar el emisor a la escena

    cout << "[GAME] Initialized with Emmiter." << endl;
}

void Game::Render()
{
	this->mainScene.Render();
}

void Game::Update()
{
	//cout << "[GAME] Update..." << endl;
	this->mainScene.Update();
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	//this->display1.ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
