#include "Game.h"
#include <iostream>           
#include "Emmiter.h"
#include "EmmiterConfiguration.h"
#include <ctime> 

void Game::Init() {


    cout << "[GAME] Init..." << endl;

    // Configuramos el emisor
    int numParticulas = 1000;                    
    int tiempoEmision = 10;                   
    Solid* particulaRef = new Cube();        


    EmmiterConfiguration Config(numParticulas, tiempoEmision, particulaRef);

    // Crear el emisor

    Emmiter* emisor = new Emmiter(Config);
    this->mainScene.AddGameObject(emisor);    

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
