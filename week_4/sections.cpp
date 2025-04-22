// 파일명: sections_example.cpp
#include <iostream>
#include <vector>
#include <omp.h>

constexpr int N = 100;

void compute_sum(const std::vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
    }
    std::cout << "Sum: " << sum << "\n";
}

void find_max(const std::vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < N; ++i) {
        if (arr[i] > mx) mx = arr[i];
    }
    std::cout << "Max: " << mx << "\n";
}

void find_min(const std::vector<int>& arr) {
    int mn = arr[0];
    for (int i = 1; i < N; ++i) {
        if (arr[i] < mn) mn = arr[i];
    }
    std::cout << "Min: " << mn << "\n";
}

int main() {
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = i + 1;
    }

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            compute_sum(arr);

            #pragma omp section
            find_max(arr);

            #pragma omp section
            find_min(arr);
        }
    }

    return 0;
}
