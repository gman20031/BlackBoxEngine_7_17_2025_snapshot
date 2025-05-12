#include <iostream>
#include "GameManager.h"
#include "../Engine Project/System/SimpleTimingSystem.h"

int main()
{
	GameManager zeldaManager;

    BlackBoxEngine::SimpleTimer::StartTimer("Startup time");
    
	zeldaManager.StartGame();

	return 0;
} 

/************** TODO **************

 Actor importing : 
        Add a single file to import all the actors in the game
    rather than needing to import each actor 1 by 1 in code. Something
    like ZeldaGameActors.xml
    code to look like
        LoadLevel(filePath)
        {
           levelDoc = new xmlDoc (filePath)
           for each node in levelDoc
             New thread ( loadActor(node.ActorfilePath) );
        }



*/