#include <iostream>
#include <chrono>
using namespace std;

int main() {
    // Start the timer
    auto start = chrono::high_resolution_clock::now();

    // Perform a simple number of operations to measure CPU speed
    long long count = 0;
    for (long long i = 0; i < 1e9; ++i) {
        count += i;  // Simple operation: addition
    }

    // End the timer
    auto end = chrono::high_resolution_clock::now();
    
    // Calculate time taken
    chrono::duration<double> duration = end - start;
    
    // Output the number of operations and time taken
    cout << "Completed operations: " << 1e9 << endl;
    cout << "Time taken: " << duration.count() << " seconds" << endl;
    cout << "Operations per second: " << (1e9 / duration.count()) << endl;

    return 0;
}