#include "../Engine Project/Actors/ComponentFactory.h"

#include "PlayerCharacter/PlayerMovement.h"

using namespace BlackBoxEngine;

static std::tuple
<
    ComponentFactory::Registrar<PlayerMovement>
> EngineRegistrar;