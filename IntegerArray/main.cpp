#include <iostream>
#include "integerarray.h"

int main()
{
    // Объявляем контейнер из 10 элементов (создание)
    const int size = 10;
    IntegerArray array(size);

    // Заполняем контейнер последовательными числами до установленного приемлемого размера
    for (int i{ 0 }; i < size; ++i)
        array[i] = i + 1;

    // Изменяем размер контейнера до 8 элементов
    array.resize(8);

    // Вставляем число 20 перед элементами с индексами 5 и 7
    array.insertBefore(20, 5);
    array.insertBefore(20, 7);

    // Удаляем элемент с индексом 3
    array.remove(3);

    // Добавляем 30 и 40 в конец и начало контейнера
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Реализуем и проверяем копию
    array.copy_create_show();

    // Выведем все числа контейнера для контроля
    for (int i{ 0 }; i < array.getLength(); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    // Осуществим поиск и взятие элемента по индексу
    std::cout << array.get_by_index(5);
    std::cout << '\n';
    // Осуществим поиск и взятие элемента по значению
    array.get_by_value(20);
    std::cout << '\n';
}
