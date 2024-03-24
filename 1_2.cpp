#include <iostream>
#include <queue>
#include <string>

struct Product {
    std::string name;
    double price;
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::queue<Product> productQueue;

    // Добавление информации о товарах в очередь
    Product product1 = { "Ручка шариковая", 1.5 };
    productQueue.push(product1);

    Product product2 = { "Тетрадь", 2.0 };
    productQueue.push(product2);

    Product product3 = { "Карандаш", 1.0 };
    productQueue.push(product3);

    // Просмотр данных в очереди и вычисление общей стоимости товаров "Ручка шариковая"
    double totalCost = 0.0;
    std::cout << "Данные товаров в очереди:" << std::endl;
    while (!productQueue.empty()) {
        Product frontProduct = productQueue.front();
        std::cout << "Наименование: " << frontProduct.name << "  Стоимость: " << frontProduct.price << std::endl;
        totalCost += frontProduct.name == "Ручка шариковая" ? frontProduct.price : 0.0;
        productQueue.pop();
    }

    std::cout << "Общая стоимость товаров с наименованием 'Ручка шариковая': " << totalCost << std::endl;

    return 0;
}