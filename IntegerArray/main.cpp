#include <iostream>
#include "integerarray.h"

int main()
{
    // ��������� ��������� �� 10 ��������� (��������)
    const int size = 10;
    IntegerArray array(size);

    // ��������� ��������� ����������������� ������� �� �������������� ����������� �������
    for (int i{ 0 }; i < size; ++i)
        array[i] = i + 1;

    // �������� ������ ���������� �� 8 ���������
    array.resize(8);

    // ��������� ����� 20 ����� ���������� � ��������� 5 � 7
    array.insertBefore(20, 5);
    array.insertBefore(20, 7);

    // ������� ������� � �������� 3
    array.remove(3);

    // ��������� 30 � 40 � ����� � ������ ����������
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // ��������� � ��������� �����
    array.copy_create_show();

    // ������� ��� ����� ���������� ��� ��������
    for (int i{ 0 }; i < array.getLength(); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    // ���������� ����� � ������ �������� �� �������
    std::cout << array.get_by_index(5);
    std::cout << '\n';
    // ���������� ����� � ������ �������� �� ��������
    array.get_by_value(20);
    std::cout << '\n';
}
