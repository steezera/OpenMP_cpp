// 파일명: fixed_array_example.cpp
#include <iostream>
#include <array>
#include <omp.h>

int main() {
    constexpr int N = 100;

    std::array<int, N> a, b, c;
    // int a[N], b[N], c[N];

    for (int i = 0; i < N; ++i) {
        b[i] = i;
        c[i] = i * 2;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        a[i] = b[i] + c[i];
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << "a[" << i << "] = " << a[i] << "\n";
    }

    #pragma omp parallel 
    {
        #pragma omp sections 
        {
            #pragma omp section
            {
                
            }
        }
    }

    return 0;
}
