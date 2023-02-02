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
    // Нам нужно убедиться, что мы установили здесь m_data
    // равным nullptr, иначе это оставит указатель
    // указывающим на освобожденную память
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
    // Сначала мы удаляем все существующие элементы
    erase();

    // Если теперь наш контейнер будет пустым, возвращаемся отсюда
    if (newLength <= 0)
        return;

    // Затем нам нужно разместить новые элементы
    m_data = new int[newLength];
    m_length = newLength;
}

void IntegerArray::resize(int newLength)
{
    // если контейнер уже имеет нужную длину, мы закончили
    if (newLength == m_length)
        return;

    // Если мы изменяем размер до пустого контейнера, делаем это и возвращаемся
    if (newLength <= 0)
    {
        erase();
        return;
    }

    // Теперь мы можем предположить, что newLength - это как минимум 1 элемент.
    // Этот алгоритм работает следующим образом:
    // Сначала размешаем новый контейнер.
    // Затем копируем элементы из существующего контейнера в новый контейнер.
    // Как только это будет сделано, можно уничтожить старый контейнер
    // и заставить m_data указывать на новый контейнер.

    // Сначала мы должны разместить новый контейнер
    int* data{ new int[newLength] };

    // Затем нам нужно выяснить, сколько элементов скопировать из
    // существующего контейнера в новый контейнер. Мы хотим скопировать
    // столько элементов, сколько есть в меньшем из двух контейнеров.
    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        // Теперь копируем элементы один за другим
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    // Теперь мы можем удалить старый контейнер, потому что он нам больше не нужен
    delete[] m_data;

    // И вместо него используем новый контейнер.
    // m_data указывает на адрес нового контейнера, который мы
    // разместили динамически. Поскольку данные были размещены динамически,
    // они не будут уничтожены, когда выйдут за пределы области видимости.
    m_data = data;
    m_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)
{
    // Проверяем значение нашего индекса на корректность
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

    // Сначала создаем новый массив на один элемент больше старого массива
    int* data{ new int[m_length + 1] };

    // Копируем все элементы до индекса
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    // Вставляем наш новый элемент в новый массив
    data[index] = value;

    // Копируем все значения после вставленного элемента
    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    // Удаляем старый массив и используем вместо него новый
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntegerArray::copy_create_show()
{
    // Сначала создаем новый контейнер
    int* data_copy{ new int[m_length] };
    // Копируем все элементы
    for (int before{ 0 }; before < m_length; ++before)
        data_copy[before] = m_data[before];
    // Покажем копию, чтобы убедиться, что операция прошла успешно
    for (int i{ 0 }; i < m_length; ++i)
        std::cout << data_copy[i] << ' ';
    std::cout << '\n';
}

void IntegerArray::remove(int index)
{
    // Проверяем значение нашего индекса на корректность
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
    // Если это последний элемент в контейнере,
    // делаем контейнер пустым и выходим
    if (m_length == 1)
    {
        erase();
        return;
    }

    // Сначала создаем новый контейнер на один элемент меньше старого контейнера
    int* data{ new int[m_length - 1] };

    // Копируем все элементы до индекса
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    // Копируем все значения после удаленного элемента
    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    // Удаляем старый контейнер и используем вместо него новый
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
