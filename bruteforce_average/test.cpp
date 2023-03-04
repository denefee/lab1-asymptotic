#include <iostream>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()

// Функция генерирования случайного целочисленного числа в указанных пределах.
// Диапазон чисел: [min, max]
int GetRandomNumber(int min, int max)
{
  // Установить генератор случайных чисел
  srand(time(NULL));

  // Получить случайное число - формула
  int num = min + rand() % (max - min + 1);

  return num;
}

int main()
{
  // Использование функции GetRandomNumber()
  int number;
  number = GetRandomNumber(0, N); // Диапазон чисел: [-10, 10]
  std::cout << "number = " << number << std::endl;;

  return 0;
}