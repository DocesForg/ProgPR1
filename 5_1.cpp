#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

void deleteEvenOnOddPosition(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* prev = head;
    Node* curr = head->next;

    while (curr != nullptr) {
        if (curr->data % 2 == 0) {
            prev->next = curr->next;
            delete curr;
            break; // Удаляем только первое найденное четное число на нечетной позиции
        }

        prev = prev->next;
        curr = curr->next;
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
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(9);

    std::cout << "Список до удаления первого четного числа на нечетной позиции: ";
    printList(head);

    deleteEvenOnOddPosition(head);

    std::cout << "Список после удаления первого четного числа на нечетной позиции: ";
    printList(head);

    return 0;
}
