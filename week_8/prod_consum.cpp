#include <iostream>
#include <omp.h>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    int buf = 0;
    bool isProdDone = false;
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            int numItem = 10;
            while (numItem >= 1) {
                omp_set_lock(&lock);
                if (buf == 0) {
                    buf = numItem;
                    cout << "Producer push " << buf << "\n";
                    --numItem;
                }
                omp_unset_lock(&lock);
                this_thread::sleep_for(chrono::milliseconds(500));
            }
            isProdDone = true;
        }

        #pragma omp section
        {
            while (!isProdDone || buf > 0) {
                omp_set_lock(&lock);
                if (buf > 0) {
                    int got = buf;
                    buf = 0;
                    cout << "Consumer get " << got << "\n";
                }
                omp_unset_lock(&lock);
                this_thread::sleep_for(chrono::milliseconds(500));
            }
        }
    }

    omp_destroy_lock(&lock);
    cout << "Producer-Consumer Work Done.\n";
    return 0;
}
