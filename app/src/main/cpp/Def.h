//
// Created by csq on 2017/12/28.
//

#ifndef SORT_DEF_H
#define SORT_DEF_H

#include "stddef.h"

#define offset(Type, element) (size_t)&(((Type*)0)->element)
#define container_of(P, Type, element) (Type*)((char*)P-offset(Type, element))

typedef struct SNode {
    int val;
    SNode *next;
    SNode(int value) : val(value), next(NULL) {}

} SNode, *SNode_p, **SNode_pp;

#endif //SORT_DEF_H
