#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);

void incrementCounter() {
    for (int i = 0; i < 100; ++i) {
        ++counter;
    }
}

int main() {
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}
