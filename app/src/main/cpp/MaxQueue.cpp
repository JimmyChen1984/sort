//
// Created by csq on 2017/12/28.
//

#include "MaxQueue.h"

bool CMaxQueue::enqueue(const int &val) {
    m_s1.push(val);

}

bool CMaxQueue::dequeue(int &val) {
    if (m_s2.empty()) {
        int val;
        while (!m_s1.empty()) {
            m_s1.pop(val);
            m_s2.push(val);
        }
    }
    m_s2.pop(val);

}

bool CMaxQueue::front(int &val) {
    dequeue(val);
}

int CMaxQueue::max() {

    if (!m_s1.empty() && !m_s2.empty()) {
        return m_s1.max() > m_s2.max() ? m_s1.max() : m_s2.max();
    } else if (!m_s1.empty()) {
        return m_s1.max();
    } else if (!m_s2.max()) {
        return m_s2.max();
    } else {
        return 0;
    }


}

bool CMaxQueue::empty() {
    return m_s1.empty() && m_s2.empty();
}