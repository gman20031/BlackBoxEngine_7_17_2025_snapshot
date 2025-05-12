#pragma once

#include <queue>
#include "Observer.h"

namespace BlackBoxEngine
{
    class MessagingManager : BB_Observer< void(*)() , size_t >
    {
        std::vector<size_t> m_eventQueue;
    public:
        void QueueNewEvent(size_t event);
        void SendQueuedEvents();
    };


}