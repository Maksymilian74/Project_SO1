#ifndef PROJECT_SO1_TABLE_H
#define PROJECT_SO1_TABLE_H

#pragma once
#include "Philosopher.h"
#include "Chopstick.h"

class Table {
public:
    // Constructor
    Table(int strategy);

    // Starts the simulation
    void start(std::atomic<bool>& running);

    // Stops all philosophers
    void stop();

    // Displays the current state of each philosopher
    void printStates() const;

private:
    static const int NUM_PHILOSOPHERS = 5; // number of philosophers
    Philosopher* philosophers[NUM_PHILOSOPHERS]; // array of philosopher pointers
    Chopstick chopsticks[NUM_PHILOSOPHERS]; // array of chopsticks
};

#endif
