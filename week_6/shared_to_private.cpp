#include <iostream>
#include "omp.h"

using namespace std;

int main() {
    int x = 5;
    #pragma omp parallel num_threads(5) private(x)
    {
        cout << x << endl;
    }

    cout << "out of parallel region x : " << x << endl;

    return 0;
}