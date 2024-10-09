#include <iostream>
#include <thread>

// Function for thread to count up to 20
void countUp() {
    int localCounter = 0;  // Each thread has its own local counter
    for (int i = 0; i <= 20; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        localCounter = i;
        std::cout << "Thread 1 counting up: " << localCounter << std::endl;
    }
}

// Function for thread to count down from 20 to 0
void countDown() {
    int localCounter = 20;  // Each thread has its own local counter
    for (int i = 20; i >= 0; --i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        localCounter = i;
        std::cout << "Thread 2 counting down: " << localCounter << std::endl;
    }
}

int main() {
    // Create threads
    std::thread thread1(countUp);
    std::thread thread2(countDown);

    // Wait for threads to finish
    thread1.join();
    thread2.join();

    return 0;
}
