#include <iostream>
#include "GameManager.h"
#include "../Engine Project/System/SimpleTimingSystem.h"

int main()
{
    GameManager zeldaManager;
    zeldaManager.Launch();

    return 0;
} 

/************** TODO **************

    Level Creation / engine editor    
        Make a seperate program or the like that is just for level creation?

    Input System : 
        Make the input work on its own seperate thread, that waits for input to be seen
        instead of needing to check every single frame.

    Resource System:
        make run on seperate thread

REQUIRED
        Compression importing
        when in release mode, I will have all the textures in a single zip file, and all the
        xml files in a single zip. Then grab load the textures from those into the resource system
        instead of trying to grab each file indivdually.

    Collision System:
        2 ) Actors should not stop dead when moving into a wall. they should slide along it. (PlayerMovement component's fault right now, maybe move a stopper into the movement blocker? or some sort of interace??)
        3 ) support more than just actors moving, like probing a point in space, raytracing,
        or anything that requries distance calculations (see Ai component)
    
    Simple AI component
        A simple component that will have a state machine interface for AI
        1) idle affect
        2) ability to react to messages or the world around them. Try to hook into the collision systems
        qaudtree in order to see the world around them
        3) concrecte example of a zombie that walks around in a bounds. Then if the player is within
        a radius of the actor, it will chase for a maximum of x distance outside of bounds
        leashing a lot like a WOW Mob.

    Text Rendering

*/