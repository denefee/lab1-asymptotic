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


int finder(int* arr, int N, int x) {
    for (int i {0}; i < N; i++) {
        for (int j {0}; j < N; j++) {
            if (arr[i] + arr[j] == x) {
                /*std::cout << "Пара: " << i << ", " << j << std::endl;*/
                break;
            }
            else {
                continue;
            }
        }
    }
    return 0;
}


int main() {
    int N = 2000;
    int* arr = generator(N);

    for (int i = 10; i < 2001; i += 10) {
        auto begin = std::chrono::steady_clock::now();
        for (int j = 1; j < 100; j++) {
            int x;
            x = -1;
            finder(arr, i, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/100);
        std::cout << time_span.count() << std::endl;
    }

    return 0;
}