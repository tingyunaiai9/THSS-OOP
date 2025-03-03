#pragma once

#include <iostream>
using namespace std;

template <typename T>

class CMyVector
{
private:
    T* m_pVector;
    size_t m_size;
    size_t m_capacity;

public:
    // 构造函数
    CMyVector<T>();
    CMyVector<T>(size_t n, const T& value = T());
    CMyVector<T>(const CMyVector<T>& other);
    ~CMyVector<T>();

    // 基本信息
    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    // 改变向量长度与容量
    void reserve(size_t n);
    void resize(size_t n, const T& value = T());
    void clear();

    // 向量元素引用
    T& operator[](size_t index);
    T& at(size_t index);
    T& front();
    T& back();

    // 向量元素插入与删除
    void push_back(const T& value);
    void pop_back();
    void insert(size_t index, const T& value);
    void erase(size_t index);

    void swap(CMyVector<T>& other);
};

template <typename T>
CMyVector<T>::CMyVector()
{
    m_capacity = 5;
    m_size = 0;
    m_pVector = new T[m_capacity];
    memset(m_pVector, 0, sizeof(T) * m_capacity);
}

template <typename T>
CMyVector<T>::CMyVector(size_t n, const T& value)
{
    m_capacity = n;
    m_size = n;
    m_pVector = new T[m_capacity];
    for (int i = 0; i < n; i++)
    {
        m_pVector[i] = value;
    }
}

template <typename T>
CMyVector<T>::CMyVector(const CMyVector<T>& other)
{
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_pVector = new T[m_capacity];
    for (int i = 0; i < m_size; i++)
    {
        m_pVector[i] = other.m_pVector[i];
    }
}

template <typename T>
CMyVector<T>::~CMyVector()
{
    if (m_pVector)
    {
        delete[] m_pVector;
        m_pVector = nullptr;
    }
}

template <typename T>
size_t CMyVector<T>::size() const
{
    return m_size;
}

template <typename T>
size_t CMyVector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
bool CMyVector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void CMyVector<T>::reserve(size_t n)
{
    if (n > m_capacity)
    {
        m_capacity = n;
        T* tmp = new T[m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            tmp[i] = m_pVector[i];
        }
        delete[] m_pVector;
        m_pVector = tmp;
    }
}

template <typename T>
void CMyVector<T>::resize(size_t n, const T& value)
{
    if (n > m_capacity)
    {
        reserve(n);
    }

    if (n < m_size)
    {
        m_size = n;
    }
    else if (n > m_size)
    {
        for (int i = m_size; i < n; i++)
        {
            m_pVector[i] = value;
        }
        m_size = n;
    }
}

template <typename T>
void CMyVector<T>::clear()
{
    m_size = 0;
}

template <typename T>
T& CMyVector<T>::operator[](size_t index)
{
    if (index < m_size)
        return m_pVector[index];
    else
        cout << "index out of range";
}

template <typename T>
T& CMyVector<T>::at(size_t index)
{
    if (index < m_size)
        return m_pVector[index];
    else
        cout << "index out of range";
}

template <typename T>
T& CMyVector<T>::front()
{
    if (m_size > 0)
        return m_pVector[0];
    else
        cout << "index out of range";
}

template <typename T>
T& CMyVector<T>::back()
{
    if (m_size > 0)
        return m_pVector[m_size - 1];
    else
        cout << "index out of range";
}

template <typename T>
void CMyVector<T>::push_back(const T& value)
{
    if (m_size >= m_capacity)
        reserve(m_capacity * 2);
    m_pVector[m_size++] = value;
}

template <typename T>
void CMyVector<T>::pop_back()
{
    if (m_size > 0)
        m_size--;
}

template <typename T>
void CMyVector<T>::insert(size_t index, const T& value)
{
    if (index > m_size)
        cout << "index out of range";

    if (m_size >= m_capacity)
        reserve(m_capacity * 2);

    for (int i = m_size; i > index; i--)
    {
        m_pVector[i] = m_pVector[i - 1];
    }
    m_pVector[index] = value;
    m_size++;
}

template <typename T>
void CMyVector<T>::erase(size_t index)
{
    if (index >= m_size)
        cout << "index out of range";

    for (int i = index; i < m_size - 1; i++)
    {
        m_pVector[i] = m_pVector[i + 1];
    }
    m_size--;
}

template <typename T>
void CMyVector<T>::swap(CMyVector<T>& other)
{
    size_t tmp_capacity = m_capacity;
    size_t tmp_size = m_size;
    T* tmp_pVector = m_pVector;

    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_pVector = other.m_pVector;

    other.m_capacity = tmp_capacity;
    other.m_size = tmp_size;
    other.m_pVector = tmp_pVector;
}

