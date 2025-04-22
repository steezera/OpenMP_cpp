// task_example_posix.cpp
#include <cstdio>
#include <omp.h>
#include <unistd.h>   // sleep(), usleep()

int main() {
    #pragma omp parallel num_threads(4)
    {
        #pragma omp single
        {
            #pragma omp task
            {
                printf("Task 1 started  (Thread %d)\n", omp_get_thread_num());
                sleep(3);
                printf("Task 1 finished (Thread %d)\n", omp_get_thread_num());
            }

            #pragma omp task
            {
                printf("Task 2 started  (Thread %d)\n", omp_get_thread_num());
                sleep(3);
                printf("Task 2 finished (Thread %d)\n", omp_get_thread_num());
            }
        }

        #pragma omp for
        for (int i = 0; i < 4; ++i) {
            printf("Loop iteration %d (Thread %d)\n", i, omp_get_thread_num());
        }
    }
    return 0;
}
