// print_m2_threads.cpp
#include <iostream>
#include <omp.h>

int main() {
    // 시스템이 보고하는 논리적 프로세서(코어) 수
    int procs = omp_get_num_procs();
    // OpenMP가 기본으로 생성하는 최대 스레드 수
    int max_threads = omp_get_max_threads();

    std::cout << "omp_get_num_procs():   " << procs << "\n"
              << "omp_get_max_threads(): " << max_threads << "\n";
    return 0;
}
