//
// Created by csq on 2017/12/27.
//

#ifndef SORT_STACK_H
#define SORT_STACK_H

#include "stddef.h"

template<class T>
class CStack {
public:
    CStack();

    CStack(const CStack &stack);

    ~CStack();

    bool top(T &t);

    bool pop(T &t);

    bool push(const T &t);

    bool clear() { m_nTop = -1; }

    bool isEmpty() { return m_nTop == -1; }

    int size();

    int capability() { return m_nSize; }

public:

    CStack &operator=(const CStack &stack);

private:
    bool isFull() { return m_nTop == m_nSize - 1; }

    void expandSize();

private:
    int m_nSize;
    int m_nTop;
    T *m_Array;
};

template<class T>
CStack<T>::CStack()
        : m_nSize(10), m_nTop(-1) {
    m_Array = new T[m_nSize];
    for (int i = 0; i < m_nSize; i++)
        m_Array[i] = NULL;

}

template<class T>
CStack<T>::CStack(const CStack &stack) {
    m_nSize = stack.m_nSize;
    m_nTop = stack.m_nTop;
    m_Array = new T[m_nSize];
    for (int i = 0; i < m_nSize; i++)
        m_Array[i] = stack.m_Array[i];
}

template<class T>
CStack<T>::~CStack() {
    delete[]m_Array;
}

template<class T>
int CStack<T>::size() {
    return m_nTop + 1;
}


template<class T>
bool CStack<T>::top(T &t) {
    if (isEmpty())
        return false;
    t = m_Array[m_nTop];
    return true;
}


template<class T>
bool CStack<T>::pop(T &t) {
    if (isEmpty())
        return false;
    t = m_Array[m_nTop];
    m_Array[m_nTop--] = NULL;
    return true;
}

template<class T>
bool CStack<T>::push(const T &t) {
    if (isFull())
        expandSize();
    m_Array[++m_nTop] = t;
    return true;
}

template<class T>
CStack<T> &CStack<T>::operator=(const CStack &stack) {
    if (this == &stack)
        return *this;
    delete[]m_Array;
    m_nSize = stack.m_nSize;
    m_nTop = stack.m_nTop;
    m_Array = new T[m_nSize];
    for (int i = 0; i < m_nSize; i++)
        m_Array[i] = stack.m_Array[i];
    return *this;

}

template<class T>
void CStack<T>::expandSize() {
    if (!isFull())
        return;
    m_nSize *= 2;
    T *array = new T[m_nSize];
    for (int i = 0; i < m_nSize; i++) {
        if (i <= m_nTop)
            array[i] = m_Array[i];
        else
            array[i] = NULL;
    }

    delete[]m_Array;
    m_Array = array;
}


#endif //SORT_STACK_H
