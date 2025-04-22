#include <iostream>
#include <omp.h>
#include <unistd.h> // sleep()
using namespace std;

int counter;
#pragma omp threadprivate(counter)

int main() {
    omp_set_num_threads(4);

    #pragma omp parallel // private(counter)
    {
        counter = omp_get_thread_num();
        cout << "Thread " << omp_get_thread_num() << ": counter = " << counter << "\n";
    }

    cout << "\n";

    #pragma omp parallel // private(counter)
    {
        cout << "Thread " << omp_get_thread_num() << ": counter = " << counter << "\n";
    }

    return 0;
}
