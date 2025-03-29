#ifndef PROJECT_SO1_PHILOSOPHER_H
#define PROJECT_SO1_PHILOSOPHER_H

#pragma once
#include "Chopstick.h"
#include <thread>
#include <atomic>
#include <string>

class Philosopher {
public:
    // Constructor
    Philosopher(int id, Chopstick& left, Chopstick& right, int strategy);

    // Starts the philosopher's thread
    void start();

    // Stops the thread safely
    void stop();

    // Returns current state
     std::string getStatus() const;
private:
    // Thread function
    void run();

    int id; // philosopher ID
    Chopstick& left; // reference to left chopstick
    Chopstick& right; // reference to right chopstick
    int strategy; // selected strategy
    std::thread thread; // thread in which the philosopher runs
    std::atomic<bool> running; // flag to control thread loop
    std::string state; // current activity
    mutable std::mutex stateMutex; // protects access to 'state' in multithreaded context
    int mealsEaten = 0; // number of times the philosopher has eaten
    bool hasLeft = false; // true if the philosopher currently holds the left chopstick
    bool hasRight = false; // true if the philosopher currently holds the right chopstick
};

#endif
