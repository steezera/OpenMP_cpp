// atomic_example.cpp
#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 100;
    int sum = 0;

    double t0 = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 1; i <= N; ++i) {
        #pragma omp atomic
        sum = sum + i;      // not a “valid” atomic update in OpenMP 3.1
    }
    double t1 = omp_get_wtime();
    cout << "[Invalid Atomic] Time: " << (t1 - t0)
         << " seconds, Final sum: " << sum << "\n";

    sum = 0;
    t0 = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 1; i <= N; ++i) {
        #pragma omp atomic
        sum += i;           //  valid atomic update
    }
    t1 = omp_get_wtime();
    cout << "[Valid Atomic]   Time: " << (t1 - t0)
         << " seconds, Final sum: " << sum << "\n";

    return 0;
}
