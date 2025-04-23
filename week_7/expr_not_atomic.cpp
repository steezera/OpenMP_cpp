#include <iostream>
#include <omp.h>
using namespace std;

int compute(int i) {
    // atomic 보호 대상이 아닌 부분: 함수 호출과 출력은 여전히 병렬로 실행됩니다
    cout << "Thread ID: " << omp_get_thread_num() << endl;
    return i * 2;
}

int main() {
    int x = 0;

    #pragma omp parallel for
    for (int i = 1; i <= 10; ++i) {
        #pragma omp atomic
        x += compute(i);
    }

    cout << "Final x: " << x << endl;
    return 0;
}
