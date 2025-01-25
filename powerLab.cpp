#include <iostream>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

int naive_power(int x, int n){
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    return x * naive_power(x, n-1);
}

int unoptimized_dc_power(int x, int n){
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    if(!(n % 2))  // n is even
        return unoptimized_dc_power(x, n/2) * unoptimized_dc_power(x, n/2);
    else
        return x * unoptimized_dc_power(x, n/2) * unoptimized_dc_power(x, n/2);
}

int optimized_dc_power(int x, int n){
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    
    int temp = optimized_dc_power(x, n/2);

    if(!(n % 2))  // n is even
        return temp * temp;
    else
        return x * temp * temp;
}

// Driver function to manually test a bunch of test cases using assert statements
void test_power_functions() {
    // Edge cases
    // Note: 0^0 has no universally agreed upon value, so it is not tested as an edge case
    // The functions above will encounter the x==0 test first and thus output 0 for 0^0.
    assert(naive_power(0, 3) == 0);
    assert(naive_power(2, 0) == 1);
    assert(naive_power(1, 100) == 1);  // Any power of 1 is 1
    assert(naive_power(10, 1) == 10);  // Any number to the power of 1 is itself
    
    assert(unoptimized_dc_power(0, 3) == 0);
    assert(unoptimized_dc_power(2, 0) == 1);
    assert(unoptimized_dc_power(1, 100) == 1);
    assert(unoptimized_dc_power(10, 1) == 10);
    
    assert(optimized_dc_power(0, 3) == 0);
    assert(optimized_dc_power(2, 0) == 1);
    assert(optimized_dc_power(1, 100) == 1);
    assert(optimized_dc_power(10, 1) == 10);

    // Small exponents
    assert(naive_power(3, 2) == 9);
    assert(naive_power(5, 3) == 125);
    
    assert(unoptimized_dc_power(3, 2) == 9);
    assert(unoptimized_dc_power(5, 3) == 125);
    
    assert(optimized_dc_power(3, 2) == 9);
    assert(optimized_dc_power(5, 3) == 125);

    // Medium exponents
    assert(naive_power(2, 6) == 64);
    assert(naive_power(4, 4) == 256);
    
    assert(unoptimized_dc_power(2, 6) == 64);
    assert(unoptimized_dc_power(4, 4) == 256);
    
    assert(optimized_dc_power(2, 6) == 64);
    assert(optimized_dc_power(4, 4) == 256);

    // Large exponents
    assert(naive_power(2, 10) == 1024);
    assert(naive_power(5, 5) == 3125);
    
    assert(unoptimized_dc_power(2, 10) == 1024);
    assert(unoptimized_dc_power(5, 5) == 3125);

    assert(optimized_dc_power(2, 10) == 1024);
    assert(optimized_dc_power(5, 5) == 3125);

    // Very large numbers
    assert(naive_power(2, 15) == 32768);
    assert(naive_power(3, 8) == 6561);
    assert(naive_power(8, 9) == 134217728);
    assert(naive_power(2, 30) == (1 << 30)); // 2^30 = 1073741824, maximum power of 2 within int bounds

    assert(unoptimized_dc_power(2, 15) == 32768);
    assert(unoptimized_dc_power(3, 8) == 6561);
    assert(unoptimized_dc_power(8, 9) == 134217728);
    assert(unoptimized_dc_power(2, 30) == (1 << 30));

    assert(optimized_dc_power(2, 15) == 32768);
    assert(optimized_dc_power(3, 8) == 6561);
    assert(optimized_dc_power(8, 9) == 134217728);
    assert(optimized_dc_power(2, 30) == (1 << 30));
      

    // Mixed tests for even and odd exponents
    assert(naive_power(2, 7) == 128);
    assert(naive_power(3, 9) == 19683);
    assert(naive_power(4, 6) == 4096);
    assert(naive_power(10, 3) == 1000);

    assert(unoptimized_dc_power(2, 7) == 128);
    assert(unoptimized_dc_power(3, 9) == 19683);
    assert(unoptimized_dc_power(4, 6) == 4096);
    assert(unoptimized_dc_power(10, 3) == 1000);

    assert(optimized_dc_power(2, 7) == 128);
    assert(optimized_dc_power(3, 9) == 19683);
    assert(optimized_dc_power(4, 6) == 4096);
    assert(optimized_dc_power(10, 3) == 1000);

    cout << "All tests passed!" << endl;  // If one of the assertion fails, it will throw an exception
}

// Function to benchmark the functions and compare their runtimes
// It's hard to see a difference with the naked eye since the functions are near-instant even for values approaching maximum integers
// So timing with chrono is needed to answer TPQs

template<typename Func>
void benchmark(Func func, int x, int n, int iterations, const string& label) {
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++) {
        func(x, n); // Call the function
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();
    cout << label << ": " << duration / iterations << " ns (average per call)" << endl;
}


int main() {
    int x = 2, n = 20, iterations = 100000;

    cout << "Testing the functions by timing 100,000 iterations of calculating 2^20" << endl;
    benchmark(naive_power, x, n, iterations, "Naive Power");
    benchmark(unoptimized_dc_power, x, n, iterations, "Unoptimized Divide & Conquer");
    benchmark(optimized_dc_power, x, n, iterations, "Optimized Divide & Conquer");

    cout << "Running unit tests on each function..." << endl;
    test_power_functions();
    return 0;
}