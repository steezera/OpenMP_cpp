#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int sum = 0;
    omp_set_num_threads(4);

    #pragma omp parallel  
    {
        int local_sum = omp_get_thread_num() + 1;
        sum += local_sum;
        cout << "Thread " << omp_get_thread_num()
             << " added " << local_sum
             << ", sum now is " << sum << "\n";
    }

    cout << "Final sum: " << sum << "\n";
    return 0;
}
