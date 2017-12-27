//
// Created by csq on 2017/12/28.
//

#ifndef SORT_MAXQUEUE_H
#define SORT_MAXQUEUE_H



#include "MaxStack.h"

class CMaxQueue {
public:
    bool enqueue(const int &val);

    bool dequeue(int &val);

    bool front(int &val);

    bool empty();

    int max();

private:
    CMaxStack m_s1;
    CMaxStack m_s2;
};


#endif //SORT_MAXQUEUE_H
