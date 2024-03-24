#include <iostream>
#include <string>

// Структура элемента очереди
struct Node {
    std::string data;
    Node* next;
};

// Класс для реализации очереди строк
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Добавление элемента в очередь (enqueue)
    void enqueue(const std::string& value) {
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

    // Нахождение количества строк, состоящих из 4 символов
    int countStringsOfLength4() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            if (current->data.length() == 4) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Queue queue;

    // Добавление строк в очередь
    queue.enqueue("one");
    queue.enqueue("two");
    queue.enqueue("three");
    queue.enqueue("four");
    queue.enqueue("five");
    queue.enqueue("six");
    queue.enqueue("seven");

    // Печать содержимого очереди
    queue.printQueue();

    // Удаление четырех элементов
    for (int i = 0; i < 4; ++i) {
        queue.dequeue();
    }

    // Добавление новых строк в очередь
    queue.enqueue("eight");
    queue.enqueue("nine");

    // Печать содержимого очереди после модификаций
    queue.printQueue();

    // Нахождение количества строк, состоящих из 4 символов
    int count = queue.countStringsOfLength4();
    std::cout << "Количество строк из 4 символов: " << count << std::endl;

    return 0;
}
