#include <atomic>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>
#include <cmath>

#include <pthread.h>
#include <sched.h>

std::atomic<int> share_data{0};
void set_cpu_affinity(int core_id) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
}

// -------------------------------------------------------------------
// CORE A (Core 0): Task A -  Cycle 10ms (Master Timer)
// -------------------------------------------------------------------
void vECU_Task_A_Core_0() {
    set_cpu_affinity(0); // Force to core A 
    std::cout << "[vECU Core A] Task A (10ms) is running...\n";
    auto next_cycle = std::chrono::steady_clock::now();
    int count = 0; 
    while (true) {
        share_data.fetch_add(1 , std::memory_order_relaxed);
        std::cout<<count++<<std::endl;
        std::printf("[Core A] generate counter %d /n", count);
        next_cycle+= std::chrono::milliseconds(10); // cast decto milliseconds
        std::this_thread::sleep_until(next_cycle);
    }
}

// -------------------------------------------------------------------
// CORE B (Core 1): Task B - Cycle 100ms (Synchonize Non-blocking)
// -------------------------------------------------------------------
void vECU_Task_B_Core_1() {
    set_cpu_affinity(1); // Attached to core 1 
    std::cout << "[vECU Core B] Task B (100ms) dang chay...\n";
    int last_value = 0; 
    while (true) {
        int current_value = share_data.load(std::memory_order_relaxed);
        if(current_value != last_value) {
            std::printf("[Core B] Receive new value from coreA %d \n", current_value);
            last_value = current_value;
        }
    }
    // to avoid spin lock using yield or sleep_until
    std::this_thread::yield();
}

int main() {
    std::cout << "=== Simulate vECU & Non-blocking ===" << std::endl;
    std::cout << "Core B polling continuously with Core A." << std::endl;

    std::thread core_A_thread(vECU_Task_A_Core_0);
    std::thread core_B_thread(vECU_Task_B_Core_1);

    core_A_thread.join();
    core_B_thread.join();

    return 0;
}

