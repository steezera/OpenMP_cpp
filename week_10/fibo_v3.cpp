#include <stdio.h>
#include <omp.h>

int fib_s(int n) {
    if(n < 2) return n;
    return fib_s(n - 1) + fib_s(n - 2);
}

int fib_v3(int n) {
    if(n < 2) return n;
    if(n <= 30) return fib_s(n);
    int x, y;
    #pragma omp task shared(x)
    {
        x = fib_v3(n - 1);
    }
    #pragma omp task shared(y)
    {
        y = fib_v3(n - 2);
    }
    #pragma omp taskwait
    return x + y;  
}

int main() {
    int n = 40;
    int result;
    // int numThreads = 16;
    double start_time, end_time;

    start_time = omp_get_wtime();
    #pragma omp parallel //num_threads(numThreads)
    {
        #pragma omp single
        {
            result = fib_v3(n);
        }
    }
    end_time = omp_get_wtime();
    printf("Time taken: %f seconds\n", end_time - start_time);
    printf("Fibonacci of %d is %d\n", n, result);

    return 0;
}