//
// Created by csq on 2017/12/28.
//

#include "MaxStack.h"

CMaxStack::CMaxStack() : m_nMax(0) {}

CMaxStack::~CMaxStack() {}

bool CMaxStack::top(int &val) {
    if (!m_stack.top(val))
        return false;
    if (val < 0)
        val += m_nMax;
    else
        val = m_nMax;
    return true;
}

bool CMaxStack::pop(int &val) {
    if (!m_stack.pop(val))
        return false;
    if (val < 0)
        val += m_nMax;
    else {
        int temp = m_nMax;
        m_nMax = m_nMax - val;
        val = temp;
    }
    return true;
}

bool CMaxStack::push(const int &val) {
    if (val > m_nMax) {
        int temp = m_nMax;
        m_nMax = val;
        return m_stack.push(val - temp);
    } else {
        return m_stack.push(val - m_nMax);
    }
}

bool CMaxStack::empty() {
    return m_stack.isEmpty();
}
