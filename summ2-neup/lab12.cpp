#include <iostream>
#include <chrono>
#include <random>
#include <stdlib.h> 

int random(int min, int max) {
    srand(time(NULL)); // генератор случайных чисел
    int num = min + rand() % (max - min + 1); // получение случайного числа

    return num;
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


/*
int timer() {
    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0 ; --cnt)
        func();
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "\n\n";
    std::cout << time_span.count ( ) << std::endl;
}
*/


int main() {
    
    for (int i = 1000; i < 1000001; i += 1000) {
        auto begin = std::chrono::steady_clock::now();
        for (int j = 1; j < 26; j++) {
            int x;
            x = random(0, i);
            finder_poln(i, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::microseconds>((end - begin)/25);
        std::cout << time_span.count() << std::endl;
    }

    return 0;
}