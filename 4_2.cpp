#include <iostream>
#include <string>

// Структура для элемента списка строк
struct Node {
    std::string data;
    Node* next;

    Node(const std::string& value) : data(value), next(nullptr) {}
};

// Функция для удаления первой строки, оканчивающейся на цифру
void deleteFirstStringWithDigit(Node*& head) {
    if (head == nullptr) {
        return;
    }

    if (std::isdigit(head->data.back())) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && !std::isdigit(current->next->data.back())) {
        current = current->next;
    }

    if (current->next != nullptr && std::isdigit(current->next->data.back())) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Функция для вывода списка строк
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Node* head = nullptr;

    // Создание линейного однонаправленного списка строк
    head = new Node("C++");      // Пример строк в списке: "Apple" -> "Banana" -> "Cherry1" -> "Date"

    head->next = new Node("JavaScript");
    head->next->next = new Node("Python1");
    head->next->next->next = new Node("CSS");

    std::cout << "Список до удаления первой строки с цифрой:" << std::endl;
    printList(head);

    // Удаление первой строки с цифрой из списка
    deleteFirstStringWithDigit(head);

    std::cout << "Список после удаления первой строки с цифрой:" << std::endl;
    printList(head);

    return 0;
}
