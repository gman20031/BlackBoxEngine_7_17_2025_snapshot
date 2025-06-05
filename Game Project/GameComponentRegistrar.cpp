#include "../Engine Project/Actors/ComponentFactory.h"

#include "PlayerCharacter/PlayerMovement.h"
#include "PlayerCharacter/GameTestingComponent.h"
#include "PlayerCharacter/PlayerReaction.h"
#include "PlayerCharacter/PlayerHealth.h"
#include "GameActors/Enemy.h"
#include "GameActors/Key.h"
#include "GameActors/Door.h"
#include "GameActors/Goal.h"

using namespace BlackBoxEngine;

static std::tuple
<
    ComponentFactory::Registrar<GameTestingComponent>,
    ComponentFactory::Registrar<PlayerMovement>,
    ComponentFactory::Registrar<PlayerHealth>,
    ComponentFactory::Registrar<PlayerReaction>,
    ComponentFactory::Registrar<KeyLogic>,
    ComponentFactory::Registrar<DoorLogic>,
    ComponentFactory::Registrar<GameGoal>,
    ComponentFactory::Registrar<EnemyLogic>
> EngineRegistrar;