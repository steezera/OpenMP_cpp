#include <cstdio>
#include <omp.h>
#include <unistd.h>

int main() {
    int temp = 0;
    #pragma omp parallel // private(temp), 이거 안해주면 temp = k 로 다 동일한 k 출력함.
    {
        #pragma omp for 
        for (int i = 0; i < 10; ++i ) {
            temp = omp_get_thread_num() * 2;
            sleep(1);
            printf("Thread %d: temp = %d\n", omp_get_thread_num(), temp);
        }
    }

    return 0;
}
