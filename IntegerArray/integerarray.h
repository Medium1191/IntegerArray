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
        // ����� ��� �� ����� ������������� m_data � �������� null
        // ��� m_length � 0, ��� ��� ������ � ����� ������ �����
        // ��������� ����� ����� ���� �������
    }

    void erase();

    int& operator[](int index);
    // reallocate �������� ������ ����������. ����� ������������ ��������
    // ����� ����������.
    void reallocate(int newLength);

    // resize �������� ������ ����������. ����� ������������ ��������
    // ����� ���������.

    void resize(int newLength);
    void insertBefore(int value, int index);
    void copy_create_show();
    void remove(int index);
    // ���������� ������� ��������� � ������ � ����� ����������
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    // ����� ������������� ���������� ��� ��������
    int getLength() const;
    // ���������� ����� � ������ �������� �� ������� � ��������
    int get_by_index(int index);
    void get_by_value(int znachenie);
};
