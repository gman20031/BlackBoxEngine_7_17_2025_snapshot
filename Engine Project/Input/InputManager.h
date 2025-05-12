#pragma once

#include <cassert>
#include <cstddef>
#include <functional>
#include <bitset>
#include <unordered_set>

#include "KeyCodes.h"
#include "../System/Observer.h"


namespace BlackBoxEngine
{

    class InputManager
    {
    public:
        enum class InputType
        {
            kKeyDown,
            kKeyUp,
            kKeyHeld,
            kCount,
        };

    private:
        using Callback = std::function<void()>;
        using CallBackId = uint64_t;
        using InputObserver = BB_Observer< Callback, KeyCode , CallBackId>;
        inline static constexpr bool kLogInputData = false;

        std::unordered_set<KeyCode> m_keyCodes;
        InputObserver m_observers[(size_t)InputType::kCount];

    public:
        InputManager();

        void AddKeyDown(KeyCode key);
        void RemoveKeyDown(KeyCode key);

        bool IsKeyDown(KeyCode key) const;

        CallBackId SubscribeKey(Callback&& function, KeyCode key, InputType type);
        void UnsubscribeKey(CallBackId id, InputType type);
        void UnsubscribeKeyHint(CallBackId id, InputType type, KeyCode key);
        void Update();


    };
};