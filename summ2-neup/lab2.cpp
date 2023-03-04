#include <iostream>
#include <chrono>
#include <random>


int random(int* arr) {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, 9);
    return arr[dstr(rng)];
}


int* generator(int N) {
    int* arr = new int[N];
    for (int i {0}; i < N; i++)
        std::cin >> arr[i];

    return arr;
}


int finder_poln(int N, int x) {
    int* arr = new int[N];
    arr = generator(N);
    for (int i {0}; i < N; i++) {
        if (arr[i] == x) {
            break;
        }
    }
    return 0;
}


int finder(int* begin, int* end, int& x) {
    int* l = begin - 1;
    int* r = end;
    while (l < r - 1) {
        int* m = l + (r - l) / 2;
        if (!(*m < x) && !(x < *m)) {
            return *m;
        }
        if (*m < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return -1;
}
    

int main() {
    int* arr = new int[1000000];
    for (int k = 0; k < 1000000; k++)
        arr[k] = k;   
    for (int i = 1000; i < 1000000; i += 1000) {
        auto begin = std::chrono::steady_clock::now();
        for (int j = 1; j < 100001; j++) {
            int x;
            x = random(arr);
            finder_bin(arr, arr + i - 1, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/100000);
        std::cout << time_span.count() << std::endl;
    }

    return 0;
}