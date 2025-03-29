#include "Table.h"
#include <iostream>
#include <thread>
#include <chrono>

// Constructor
Table::Table(int strategy) {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers[i] = new Philosopher(i,chopsticks[i],chopsticks[(i + 1) % NUM_PHILOSOPHERS], strategy);
    }
}

// Starts all philosopher threads and prints their state
void Table::start(std::atomic<bool>& running) {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        philosophers[i]->start();

    while (running) {
        printStates();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Stops all philosopher threads
void Table::stop() {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers[i]->stop();
        delete philosophers[i];
    }
}

// Displays the current state of each philosopher
void Table::printStates() const {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        std::cout << "Filozof " << i << ": " << philosophers[i]->getState() << "\n";
    }
    std::cout << "---------------------\n";
}
