#include "InputManager.h"

namespace BlackBoxEngine
{
    InputManager::InputManager()
    {
        m_keyCodes.reserve(static_cast<size_t>(KeyCode::kCount));
}

    void InputManager::AddKeyDown(KeyCode key)
    {
        m_keyCodes.emplace(key);
        m_observers[(size_t)InputType::kKeyDown].PushEvent(key);
        if constexpr (kLogInputData)
            BB_LOG(LogType::kMessage, "Key down : ", key);

    }

    void InputManager::RemoveKeyDown(KeyCode key)
    {
        m_keyCodes.erase(key);
        m_observers[(size_t)InputType::kKeyUp].PushEvent(key);
        if constexpr (kLogInputData)
            BB_LOG(LogType::kMessage, "Key up : ", key);
    }

    bool InputManager::IsKeyDown(KeyCode key) const
    {
        return m_keyCodes.contains(key);
    }

    InputManager::CallBackId InputManager::SubscribeKey(Callback&& function, KeyCode key, InputType type)
    {
        return m_observers[(size_t)type].RegisterListener(std::forward<Callback>(function), key);
    }

    void InputManager::UnsubscribeKey(CallBackId id, InputType type)
    {
        m_observers[(size_t)type].RemoveListener(id);
    }

    void InputManager::UnsubscribeKeyHint(CallBackId id, InputType type, KeyCode key)
    {
        m_observers[(size_t)type].RemoveListenerHint(id, key);
    }

    void InputManager::Update()
    {
        for (KeyCode code : m_keyCodes)
        {
            m_observers[(size_t)InputType::kKeyHeld].PushEvent(code);
            if constexpr (kLogInputData)
                BB_LOG(LogType::kMessage, "Key held : ", code);
        }
    }

}

