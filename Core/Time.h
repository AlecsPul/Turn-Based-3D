#pragma once

#include <chrono>

class Time {
public:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;
    using Duration = std::chrono::duration<float>;

    static float GetDeltaTime() { return s_DeltaTime; }
    static float GetTime() { return s_TotalTime; }

    static void Update() {
        TimePoint currentTime = Clock::now();
        s_DeltaTime = std::chrono::duration_cast<Duration>(currentTime - s_LastFrameTime).count();
        s_LastFrameTime = currentTime;
        s_TotalTime += s_DeltaTime;
    }

    static void Reset() {
        s_LastFrameTime = Clock::now();
        s_DeltaTime = 0.0f;
        s_TotalTime = 0.0f;
    }

private:
    static inline TimePoint s_LastFrameTime = Clock::now();
    static inline float s_DeltaTime = 0.0f;
    static inline float s_TotalTime = 0.0f;
};
