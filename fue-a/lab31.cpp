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


/*int* rand_arr(int N) {
    int* arr = new int[N];
    int* bas = generator(N);
    for (int i {0}; i < N; i++)
        std::cin >> random(bas) >> arr[i];

    return arr;
}*/


int finder_opt(int* arr, int N, int x) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == x)&&(i != 0) {
            int zam = arr[0];
            arr[i] = zam;
            arr[0] = x;
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}


int main() {
    int N = 10000;
    int* arr = generator(N);

    for (int i = 10; i < 10001; i += 10) {
        auto begin = std::chrono::steady_clock::now();
        for (int j = 1; j < 5001; j++) {
            int x;
            x = -1;
            finder(arr, i, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/5000);
        std::cout << time_span.count() << std::endl;
    }

    return 0;
}