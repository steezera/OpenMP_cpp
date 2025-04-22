#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int base = 100;
    #pragma omp parallel sections firstprivate(base)
    {
        #pragma omp section
        {
            int tid = omp_get_thread_num();
            cout << "Thread " << tid << ": base = " << base + tid << endl;
        }
        #pragma omp section
        {
            int tid = omp_get_thread_num();
            cout << "Thread " << tid << ": base = " << base + tid << endl;
        }
        #pragma omp section
        {
            int tid = omp_get_thread_num();
            cout << "Thread " << tid << ": base = " << base + tid << endl;
        }
    }

    return 0;
}