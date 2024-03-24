#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node* duplicateOddValues(Node* P1) {
    if (P1 == nullptr) {
        return nullptr;
    }

    Node* curr = P1;
    Node* last = nullptr;

    while (curr != nullptr) {
        if (curr->data % 2 != 0) {
            Node* newNode = new Node(curr->data);

            newNode->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
            newNode->prev = curr;

            if (newNode->next == nullptr) {
                last = newNode; // Обновляем указатель на последний элемент
            }

            curr = newNode->next;
        }
        else {
            curr = curr->next;
        }
    }

    return last;
}

int main() {
    Node* P1 = new Node(1);
    P1->next = new Node(2);
    P1->next->prev = P1;
    P1->next->next = new Node(3);
    P1->next->next->prev = P1->next;
    P1->next->next->next = new Node(4);
    P1->next->next->next->prev = P1->next->next;

    std::cout << "Список до дублирования элементов с нечетными значениями: ";
    Node* current = P1;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    Node* lastNode = duplicateOddValues(P1);

    std::cout << "Список после дублирования элементов с нечетными значениями: ";
    current = P1;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "Указатель на последний элемент после дублирования: " << lastNode->data << std::endl;

    return 0;
}
