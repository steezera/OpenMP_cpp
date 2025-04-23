#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int n = 100;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int sum = 0;

    // Parallel region with reduction
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    cout << "Sum: " << sum << endl;

    return 0;
}