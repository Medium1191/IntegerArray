#include "integerarray.h"


IntegerArray::IntegerArray(int length) :
    m_length{ length }
{
    try
    {
        if (length <= 0)
        {
            throw "ERROR: Such a container is not suitable";
        }
    }
    catch (const char* bad_length)
    {
        std::cout << bad_length << std::endl;
        return;
    }

    if (length > 0)
    {
        m_data = new int[length] {};
    }
}

void IntegerArray::erase()
{
    delete[] m_data;
    // ��� ����� ���������, ��� �� ���������� ����� m_data
    // ������ nullptr, ����� ��� ������� ���������
    // ����������� �� ������������� ������
    m_data = nullptr;
    m_length = 0;
}

int& IntegerArray::operator[](int index)
{
    if (index >= 0 && index < m_length)
        return m_data[index];
    else
        try
    {
        throw "ERROR: There are no indexes to work with";
    }
    catch (const char* bad_range)
    {
        std::cout << bad_range << std::endl;
    }
}

void IntegerArray::reallocate(int newLength)
{
    // ������� �� ������� ��� ������������ ��������
    erase();

    // ���� ������ ��� ��������� ����� ������, ������������ ������
    if (newLength <= 0)
        return;

    // ����� ��� ����� ���������� ����� ��������
    m_data = new int[newLength];
    m_length = newLength;
}

void IntegerArray::resize(int newLength)
{
    // ���� ��������� ��� ����� ������ �����, �� ���������
    if (newLength == m_length)
        return;

    // ���� �� �������� ������ �� ������� ����������, ������ ��� � ������������
    if (newLength <= 0)
    {
        erase();
        return;
    }

    // ������ �� ����� ������������, ��� newLength - ��� ��� ������� 1 �������.
    // ���� �������� �������� ��������� �������:
    // ������� ��������� ����� ���������.
    // ����� �������� �������� �� ������������� ���������� � ����� ���������.
    // ��� ������ ��� ����� �������, ����� ���������� ������ ���������
    // � ��������� m_data ��������� �� ����� ���������.

    // ������� �� ������ ���������� ����� ���������
    int* data{ new int[newLength] };

    // ����� ��� ����� ��������, ������� ��������� ����������� ��
    // ������������� ���������� � ����� ���������. �� ����� �����������
    // ������� ���������, ������� ���� � ������� �� ���� �����������.
    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        // ������ �������� �������� ���� �� ������
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    // ������ �� ����� ������� ������ ���������, ������ ��� �� ��� ������ �� �����
    delete[] m_data;

    // � ������ ���� ���������� ����� ���������.
    // m_data ��������� �� ����� ������ ����������, ������� ��
    // ���������� �����������. ��������� ������ ���� ��������� �����������,
    // ��� �� ����� ����������, ����� ������ �� ������� ������� ���������.
    m_data = data;
    m_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)
{
    // ��������� �������� ������ ������� �� ������������
    try
    {
        if (index < 0 || index > m_length)
        {
            throw "ERROR: there is no index before which it is possible to insert the presented value";
        }
    }
    catch (const char* exception_1)
    {
        std::cout << exception_1 << std::endl;
        return;
    }

    // ������� ������� ����� ������ �� ���� ������� ������ ������� �������
    int* data{ new int[m_length + 1] };

    // �������� ��� �������� �� �������
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    // ��������� ��� ����� ������� � ����� ������
    data[index] = value;

    // �������� ��� �������� ����� ������������ ��������
    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    // ������� ������ ������ � ���������� ������ ���� �����
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntegerArray::copy_create_show()
{
    // ������� ������� ����� ���������
    int* data_copy{ new int[m_length] };
    // �������� ��� ��������
    for (int before{ 0 }; before < m_length; ++before)
        data_copy[before] = m_data[before];
    // ������� �����, ����� ���������, ��� �������� ������ �������
    for (int i{ 0 }; i < m_length; ++i)
        std::cout << data_copy[i] << ' ';
    std::cout << '\n';
}

void IntegerArray::remove(int index)
{
    // ��������� �������� ������ ������� �� ������������
    try
    {
        if (index < 0 || index > m_length)
        {
            throw "ERROR: There is no index to delete";
        }
    }
    catch (const char* exception_2)
    {
        std::cout << exception_2 << std::endl;
        return;
    }
    // ���� ��� ��������� ������� � ����������,
    // ������ ��������� ������ � �������
    if (m_length == 1)
    {
        erase();
        return;
    }

    // ������� ������� ����� ��������� �� ���� ������� ������ ������� ����������
    int* data{ new int[m_length - 1] };

    // �������� ��� �������� �� �������
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    // �������� ��� �������� ����� ���������� ��������
    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    // ������� ������ ��������� � ���������� ������ ���� �����
    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntegerArray::insertAtBeginning(int value) { insertBefore(value, 0); }

void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_length); }

int IntegerArray::get_by_index(int index)
{
    int rez{ 0 };
    try
    {
        if (index < 0 || index > m_length)
        {
            throw "ERROR: There are no indexes to work with";
        }
    }
    catch (const char* exception_3)
    {
        std::cout << exception_3 << std::endl;
    }
    rez = m_data[index];
    return rez;

}

void IntegerArray::get_by_value(int znachenie)
{
    int k{ 0 };
    for (int i = 0; i < m_length; i++)
    {
        if (m_data[i] == znachenie)
        {
            std::cout << i << " ";
            ++k;
        }
    }
    if (k == 0)
    {
        std::cout << "No matches found" << std::endl;
    }
    else
        std::cout << "The number of matches is equal to " << k << std::endl;

};

int IntegerArray::getLength() const { return m_length; }
