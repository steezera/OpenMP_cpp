// square_root_sum.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;

static const int N = 100000000;

int main() {
    // 1) 데이터 준비
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) arr[i] = i;

    double t0, t1;
    long long serial_sum   = 0;
    long long parallel_sum = 0;
    long long critical_sum = 0;

    // --- Serial ---
    t0 = omp_get_wtime();
    for (int i = 0; i < N; ++i) {
        int v = static_cast<int>(sqrt(arr[i]));
        serial_sum += v;
    }
    t1 = omp_get_wtime();
    cout << "[Serial]   Sum: " << serial_sum
         << ", Time: " << t1 - t0 << " seconds\n";

    // --- Parallel (Unsafe) ---
    t0 = omp_get_wtime();
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < N; ++i) {
        int v = static_cast<int>(sqrt(arr[i]));
        parallel_sum += v;  // race condition!
    }
    t1 = omp_get_wtime();
    cout << "[Parallel] Sum: " << parallel_sum
         << ", Time: " << t1 - t0 << " seconds\n";

    // --- Parallel (with critical) ---
    t0 = omp_get_wtime();
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < N; ++i) {
        int v = static_cast<int>(sqrt(arr[i]));
        #pragma omp critical
        critical_sum += v;
    }
    t1 = omp_get_wtime();
    cout << "[Critical] Sum: " << critical_sum
         << ", Time: " << t1 - t0 << " seconds\n";

    return 0;
}
