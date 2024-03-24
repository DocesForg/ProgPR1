#include <iostream>

// Структура элемента очереди
struct Node {
    double data;
    Node* next;
};

// Класс для реализации очереди
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Добавление элемента в очередь (enqueue)
    void enqueue(double value) {
        Node* newNode = new Node{ value, nullptr };
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Удаление элемента из очереди (dequeue)
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Очередь пуста." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Печать содержимого очереди
    void printQueue() {
        Node* current = front;
        std::cout << "Содержимое очереди:" << std::endl;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Нахождение суммы элементов очереди
    double sumQueue() {
        double sum = 0.0;
        Node* current = front;
        while (current != nullptr) {
            sum += current->data;
            current = current->next;
        }
        return sum;
    }
};

int main() {
    Queue queue;

    // Добавление чисел в очередь
    queue.enqueue(2.2);
    queue.enqueue(1.2);
    queue.enqueue(2.0);
    queue.enqueue(5.2);

    // Печать содержимого очереди
    queue.printQueue();

    // Удаление двух элементов
    queue.dequeue();
    queue.dequeue();

    // Добавление числа 2.9
    queue.enqueue(2.9);

    // Печать содержимого очереди после модификаций
    queue.printQueue();

    // Нахождение суммы элементов в очереди
    double sum = queue.sumQueue();
    std::cout << "Сумма элементов в очереди: " << sum << std::endl;

    return 0;
}
