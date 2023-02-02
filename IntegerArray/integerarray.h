#pragma once
#include <iostream>

class IntegerArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntegerArray() = default;

    IntegerArray(int length);

    ~IntegerArray()
    {
        delete[] m_data;
        // здесь нам не нужно устанавливать m_data в значение null
        // или m_length в 0, так как объект в любом случае будет
        // уничтожен сразу после этой функции
    }

    void erase();

    int& operator[](int index);
    // reallocate изменяет размер контейнера. Любые существующие элементы
    // будут уничтожены.
    void reallocate(int newLength);

    // resize изменяет размер контейнера. Любые существующие элементы
    // будут сохранены.

    void resize(int newLength);
    void insertBefore(int value, int index);
    void copy_create_show();
    void remove(int index);
    // Реализация вставки элементов в начало и конец контейнера
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    // Вывод состоявшегося результата для контроля
    int getLength() const;
    // Осуществим поиск и взятие элемента по индексу и значению
    int get_by_index(int index);
    void get_by_value(int znachenie);
};
