#include "SimpleTimingSystem.h"

namespace BlackBoxEngine
{
    SimpleTimer::TimerMapType & SimpleTimer::Map()
    {
        static TimerMapType map;
        return map;
    }

    void SimpleTimer::StartTimer(const std::string& name)
    {
        Map()[name] = ClockType::now();
    }

    std::chrono::milliseconds SimpleTimer::StopTimer(const std::string& name)
    {
        auto duration = ClockType::now() - Map()[name];
        return  std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    }

}