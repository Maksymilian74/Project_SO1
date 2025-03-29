#include "Philosopher.h"
#include <iostream>
#include <chrono>
#include <random>

// Constructor
Philosopher::Philosopher(int id, Chopstick& left, Chopstick& right, int strategy)
        : id(id), left(left), right(right), strategy(strategy), running(false), state("Mysli") {}

// Starts philosopher thread
void Philosopher::start() {
    running = true;
    thread = std::thread(&Philosopher::run, this);
}

// Signals thread to stop
void Philosopher::stop() {
    running = false;
    if (thread.joinable()) thread.join();
}

// Returns current state
std::string Philosopher::getState() const {
    std::lock_guard<std::mutex> lock(stateMutex);
    return state;
}

// Main philosopher loop
void Philosopher::run() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> eatDist(1000, 4000); // eating duration: 1-4s
    std::uniform_int_distribution<> thinkDist(2000, 5000); // thinking duration: 2-5s

    while (running) {
        {
            std::lock_guard<std::mutex> lock(stateMutex);
            state = "Czeka";
        }

        switch (strategy) {
            case 1: // Deadlock
                right.pickUp(id);
                left.pickUp(id);
                break;

            case 2: // Starvation
                if (rand() % 2 == 0) {
                    left.pickUp(id);
                    right.pickUp(id);
                } else {
                    right.pickUp(id);
                    left.pickUp(id);
                }
                break;

            case 3: // Fair
            default:
                if (id == 0) {
                    left.pickUp(id);
                    right.pickUp(id);
                } else {
                    right.pickUp(id);
                    left.pickUp(id);
                }
                break;
        }

        {
            std::lock_guard<std::mutex> lock(stateMutex);
            state = "Je";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(eatDist(gen)));

        left.putDown();
        right.putDown();

        {
            std::lock_guard<std::mutex> lock(stateMutex);
            state = "Mysli";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(thinkDist(gen)));
    }
}
