#include <iostream>
#include <vector>

struct Node {
    float data;
    Node* next;

    Node(float data) : data(data), next(nullptr) {}
};

void insertFirstNegativeBefore20(Node* head) {
    Node* curr = head;
    float firstNegative = 0;

    while (curr != nullptr) {
        if (curr->data < 0) {
            firstNegative = curr->data;
            break;
        }
        curr = curr->next;
    }

    if (firstNegative != 0) {
        Node* prev = nullptr;
        curr = head;

        while (curr != nullptr) {
            if (curr->data == 20) {
                Node* negNode = new Node(firstNegative);
                negNode->next = curr;
                if (prev != nullptr) {
                    prev->next = negNode;
                }
                else {
                    head = negNode;
                }
                prev = negNode;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Node* head = nullptr;
    Node* tail = nullptr;

    std::vector<float> numbers;
    float inputNum;

    std::cout << "Введите список вещественных чисел (для завершения введите любой символ):" << std::endl;

    while (std::cin >> inputNum) {
        if (head == nullptr) {
            head = new Node(inputNum);
            tail = head;
        }
        else {
            tail->next = new Node(inputNum);
            tail = tail->next;
        }
    }

    std::cin.clear();  // Очистим флаг ошибок ввода
    std::cin.ignore(); // Игнорируем символ новой строки

    std::cout << "Список до вставки первого отрицательного элемента перед числами 20: ";
    printList(head);

    insertFirstNegativeBefore20(head);

    std::cout << "Список после вставки первого отрицательного элемента перед каждым числом 20: ";
    printList(head);

    return 0;
}
