#include "MessageManager.h"


namespace BlackBoxEngine
{
    void MessagingManager::QueueNewEvent(size_t event)
    {
        m_eventQueue.emplace_back(event);
    }
    void MessagingManager::SendQueuedEvents()
    {
        for (size_t event : m_eventQueue)
            PushEvent(event);
        m_eventQueue.clear();
    }
}
