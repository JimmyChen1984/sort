//
// Created by csq on 2017/12/28.
//

#ifndef SORT_CMAXSTACK_H
#define SORT_CMAXSTACK_H

#include "Stack.h"

class CMaxStack {
public:
    CMaxStack();
    ~CMaxStack();
    bool top(int &val);

    bool pop(int &val);

    bool push(const int &val);

    bool empty();

    int max() { return m_nMax;}

private:
    int m_nMax;
    CStack<int> m_stack;
};


#endif //SORT_CMAXSTACK_H
