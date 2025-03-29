#include "Table.h"
#include <iostream>
#include <csignal>
#include <atomic>

// Global atomic flag to control simulation loop
std::atomic<bool> running(true);

// Signal handler for Ctrl+C
void simulationStop(int signal) {
    if (signal == SIGINT) {
        std::cout << "\nPrzerwano przez uzytkownika\n";
        running = false;
    }
}

// Ask user to choose simulation strategy
int chooseStrategy() {
    int choice = 0;
    do {
        std::cout << "Wybierz strategie:\n";
        std::cout << "1. Zakleszczenie\n";
        std::cout << "2. Zaglodzenie\n";
        std::cout << "3. Zrownowazona\n";
        std::cin >> choice;
        std::cout << "\n\n";
    } while (choice < 1 || choice > 3);
    return choice;
}

int main() {
    std::signal(SIGINT, simulationStop);
    int strategy = chooseStrategy();

    Table table(strategy);
    table.start(running);
    table.stop();

    return 0;
}
