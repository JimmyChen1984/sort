//
// Created by csq on 2017/12/28.
//

#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include "Def.h"

class CUtils {
public:
    static SNode_p reverseList(SNode_p h);

    static SNode_p isLoopInList(SNode_p h);

    static int loopListLen(SNode_p h);

    static SNode_p loopListEntry(SNode_p h);


    //交换node的值
    static void sortListQuick(SNode_p head);

    static void sortListQuick(SNode_p head, SNode_p tail);

    static SNode_p listPartition(SNode_p head, SNode_p tail);

    //不交换node的值
    static SNode_p sortListQuickUnChange(SNode_p head);

    static void sortListQuick(SNode_p pre, SNode_p head, SNode_p tail);

    static SNode_p listPartition(SNode_p pre, SNode_p head, SNode_p tail);

    static STreeNode_p reverseTree(STreeNode_p root);

    static bool compareTree(STreeNode_p left, STreeNode_p right);

};


#endif //SORT_UTILS_H
