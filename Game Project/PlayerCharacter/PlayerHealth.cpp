#include "PlayerHealth.h"

#include <BlackBoxManager.h>
#include <system/Log.h>

#include "../GameActors/Enemy.h"

using namespace BlackBoxEngine;

void PlayerHealth::Start()
{
}

void PlayerHealth::CheckHealth()
{
    if (m_health <= 0)
    {
        PlayerDied();
        return;
    }
    if (m_health > m_maxHealth)
        m_health = m_maxHealth;
}

void PlayerHealth::ModifyHealth(int change)
{
    m_health += change;
    CheckHealth();
}

void PlayerHealth::SetHealth(int newHealth)
{
    m_health = newHealth;
    CheckHealth();
}

void PlayerHealth::PlayerDied()
{
    BB_LOG(LogType::kMessage, "PLAYER DIED!!");
    BlackBoxManager::Get()->m_pActorManager->DestroyActor(m_pOwner);
    BlackBoxManager::Get()->m_pMessagingManager->EnqueueMessage(kPlayerDiedMessage, m_pOwner);
}


