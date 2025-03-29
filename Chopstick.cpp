#include "Chopstick.h"

// Acquires the chopstick (mutex)
void Chopstick::pickUp(int philosopherId) {
    mtx.lock();
    owner = philosopherId;
}

// Releases the chopstick
void Chopstick::putDown() {
    owner = -1;
    mtx.unlock();
}

