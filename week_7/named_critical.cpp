#include <iostream>
#include <omp.h>
using namespace std;

int total  = 0;
int total2 = 0;

// total 을 보호하는 named critical (lock 이름: update_total)
void add_to_total(int value) {
    #pragma omp critical(update_total)
    {
        total += value;
        cout << "Add "  << value
             << ", total: " << total << "\n";
    }
}

void subtract_from_total(int value) {
    #pragma omp critical(update_total)
    {
        total -= value;
        cout << "Sub "  << value
             << ", total: " << total << "\n";
    }
}

int main() {
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        if (tid % 2 == 0) {
            add_to_total(10);
        } else {
            subtract_from_total(5);
        }

        // total2 를 보호하는 또 다른 named critical (lock 이름: update_total2)
        #pragma omp critical(update_total2)
        {
            total2 += tid;
        }
    }

    cout << "Final total:  "  << total  << "\n"
         << "Final total2: " << total2 << "\n";
    return 0;
}
