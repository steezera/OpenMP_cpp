#include <iostream>
#include <omp.h>

int main() {
    int i;
    int last_val = -1;

    #pragma omp parallel for lastprivate(last_val)
    for (i = 0; i < 10; ++i) {
        last_val = i * 2;
        std::cout << "Thread " << omp_get_thread_num()
                  << ": i = " << i
                  << ", last_val = " << last_val
                  << "\n";
    }

    std::cout << "After loop: last_val = " << last_val << "\n";
    return 0;
}
