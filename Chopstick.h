#ifndef PROJECT_SO1_CHOPSTICK_H
#define PROJECT_SO1_CHOPSTICK_H

#pragma once
#include <mutex>

class Chopstick {
public:
    Chopstick() = default;

    // Locks the chopstick
    void pickUp(int philosopherId);

    // Unlocks the chopstick
    void putDown();
private:
    std::mutex mtx; // protects access to the chopstick
    int owner = -1; // ID of philosopher holding the chopstick
};

#endif
