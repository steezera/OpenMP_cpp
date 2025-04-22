#include <iostream>
#include <omp.h>

using namespace std;

int main() {

    #pragma omp parallel num_threads(3) 
    {
        #pragma omp single
        {
            #pragma omp task
            {
                cout << "task 1 executed by thread " << omp_get_thread_num() << endl;
            }
            #pragma omp task
            {
                cout << "task 2-1 executed by thread " << omp_get_thread_num() << endl;
                cout << "task 2-2 executed by thread " << omp_get_thread_num() << endl;
    
            }
        }
    }
    return 0;
}