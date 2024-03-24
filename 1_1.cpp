#include <iostream>
#include <stack>
#include <string>

struct Student {
    std::string name;
    double avgGrade;
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::stack<Student> studentStack;

    // Добавление информации о студенте в стек
    Student student1 = { "Мальцев", 5.0 };
    studentStack.push(student1);

    Student student2 = { "Торубаров", 4.5 };
    studentStack.push(student2);

    // Просмотр данных в стеке
    std::cout << "Данные студентов в стеке:" << std::endl;
    while (!studentStack.empty()) {
        Student topStudent = studentStack.top();
        std::cout << "Фамилия: " << topStudent.name << "  Средний бал: " << topStudent.avgGrade << std::endl;
        studentStack.pop();
    }

    return 0;
}
