#include <iostream>
#include <queue>

int main() {
    setlocale(LC_ALL, "Russian");
    std::queue<int> oddQueue;
    std::queue<int> evenQueue;
    const int nil = -1; // Константа nil для пустой очереди

    // Исходный набор из 10 чисел
    int numbers[] = { 1, 8, 3, 6, 5, 4, 7, 2, 9, 10 };

    // Разделение чисел на нечетные и четные и добавление их в соответствующие очереди
    for (int i = 0; i < 10; ++i) {
        if (numbers[i] % 2 == 0) {
            evenQueue.push(numbers[i]);
        }
        else {
            oddQueue.push(numbers[i]);
        }
    }

    // Вывод указателей на начало и конец первой очереди (нечетные числа)
    std::cout << "Указатели на начало и конец первой очереди (нечетные числа):" << std::endl;
    if (!oddQueue.empty()) {
        std::cout << "Начало: " << &oddQueue.front() << ", Конец: " << &oddQueue.back() << std::endl;
    }
    else {
        std::cout << "Начало: " << nil << ", Конец: " << nil << std::endl;
    }

    // Вывод указателей на начало и конец второй очереди (четные числа)
    std::cout << "Указатели на начало и конец второй очереди (четные числа):" << std::endl;
    if (!evenQueue.empty()) {
        std::cout << "Начало: " << &evenQueue.front() << ", Конец: " << &evenQueue.back() << std::endl;
    }
    else {
        std::cout << "Начало: " << nil << ", Конец: " << nil << std::endl;
    }

    return 0;
}
