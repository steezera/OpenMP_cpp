#include <iostream>
#include <omp.h>

int main() {
    int x = -1;

    #pragma omp parallel sections lastprivate(x)
    {
        #pragma omp section
        {
            x = 1;
        }
        #pragma omp section
        {
            x = 2;
        }
        #pragma omp section
        {
            x = 3;
        }
    }
    std::cout << "Final value of x: " << x << std::endl;
    return 0;
}
