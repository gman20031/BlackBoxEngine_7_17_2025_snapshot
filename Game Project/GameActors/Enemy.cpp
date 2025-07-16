#include "Enemy.h"

#include <BlackBoxManager.h>

#include "../PlayerCharacter/PlayerHealth.h"


using namespace BlackBoxEngine;
void EnemyLogic::Start()
{
    m_pEngine = BlackBoxEngine::BlackBoxManager::Get();
}

void EnemyLogic::OnCollide(BlackBoxEngine::Actor* pOther)
{
    assert(m_pEngine);
    PlayerHealth* pHealth = pOther->GetComponent<PlayerHealth>();
    if (!pHealth)
        return;

    pHealth->ModifyHealth( -kDamage );
    m_pEngine->m_pMessagingManager->EnqueueMessage(kHitPlayerMessage, m_pOwner, pOther);
}
