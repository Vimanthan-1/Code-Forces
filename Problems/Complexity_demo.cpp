
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;

volatile long long resultSink = 0;

template <typename Function>
double measureMicroseconds(Function function) {
    auto start = steady_clock::now();
    long long result = function();
    auto end = steady_clock::now();

    resultSink = resultSink + result;

    return duration<double, micro>(end - start).count();
}

// O(1): Constant time
long long constantTime(int n) {
    return n * 2LL;
}

// O(log n): Binary search
long long logarithmicTime(int n) {
    int low = 0, high = n - 1;
    int target = n - 1;
    long long operations = 0;

    while (low <= high) {
        operations++;
        int mid = low + (high - low) / 2;

        if (mid == target)
            break;
        else if (mid < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return operations;
}

// O(n): Linear traversal
long long linearTime(int n) {
    long long sum = 0;

    for (int i = 0; i < n; i++)
        sum += i;

    return sum;
}

// O(n log n): Sorting
long long linearithmicTime(int n) {
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        arr[i] = (i * 7919LL) % (n + 1);

    sort(arr.begin(), arr.end());

    return arr.empty() ? 0 : arr[n / 2];
}

// O(n^2): Compare every pair
long long quadraticTime(int n) {
    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }

    return count;
}

// O(2^n): Enumerate every subset
long long exponentialTime(int n) {
    long long count = 0;
    long long subsets = 1LL << n;

    for (long long mask = 0; mask < subsets; mask++)
        count++;

    return count;
}

int main() {
    cout << fixed << setprecision(2);

    cout << "=== DSA TIME COMPLEXITY DEMO ===\n\n";
    cout << "Times are in microseconds (us).\n\n";

    cout << "1. CONSTANT TIME - O(1)\n";
    for (int n : {1000, 100000, 10000000}) {
        double time = measureMicroseconds(
            [&]() { return constantTime(n); });
        cout << "n = " << n << " | " << time << " us\n";
    }

    cout << "\n2. LOGARITHMIC TIME - O(log n)\n";
    for (int n : {1000, 100000, 10000000}) {
        double time = measureMicroseconds(
            [&]() { return logarithmicTime(n); });
        cout << "n = " << n << " | "
             << logarithmicTime(n) << " comparisons | "
             << time << " us\n";
    }

    cout << "\n3. LINEAR TIME - O(n)\n";
    for (int n : {1000, 100000, 10000000}) {
        double time = measureMicroseconds(
            [&]() { return linearTime(n); });
        cout << "n = " << n << " | " << time << " us\n";
    }

    cout << "\n4. LINEARITHMIC TIME - O(n log n)\n";
    for (int n : {1000, 10000, 100000}) {
        double time = measureMicroseconds(
            [&]() { return linearithmicTime(n); });
        cout << "n = " << n << " | " << time << " us\n";
    }

    cout << "\n5. QUADRATIC TIME - O(n^2)\n";
    for (int n : {100, 1000, 5000}) {
        double time = measureMicroseconds(
            [&]() { return quadraticTime(n); });
        cout << "n = " << n << " | "
             << 1LL * n * n << " iterations | "
             << time << " us\n";
    }

    cout << "\n6. EXPONENTIAL TIME - O(2^n)\n";
    for (int n : {10, 15, 20, 24}) {
        double time = measureMicroseconds(
            [&]() { return exponentialTime(n); });
        cout << "n = " << n << " | "
             << (1LL << n) << " subsets | "
             << time << " us\n";
    }

    cout << "\nKeep this result alive: " << resultSink << '\n';
    return 0;
}
