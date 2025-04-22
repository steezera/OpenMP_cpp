// 파일명: task_without_single.cpp
#include <cstdio>
#include <omp.h>
#include <unistd.h>   // sleep()

int main() {
    #pragma omp parallel num_threads(4)
    {
        #pragma omp task
        {
            printf("Task started  (Thread %d)\n", omp_get_thread_num());
            sleep(3);
            printf("Task finished (Thread %d)\n", omp_get_thread_num());
        }

        #pragma omp for
        for (int i = 0; i < 4; ++i) {
            printf("Loop iteration %d (Thread %d)\n", 
                   i, omp_get_thread_num());
        }
    }

    return 0;
}
