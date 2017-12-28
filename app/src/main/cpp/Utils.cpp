//
// Created by csq on 2017/12/28.
//

#include "Utils.h"
#include "Sort.h"

SNode_p CUtils::reverseList(SNode_p h) {
    SNode_p reverseHead = NULL;
    SNode_p cur = h;
    SNode_p next;
    while (cur != NULL) {
        next = cur->next;
        cur->next = reverseHead;
        reverseHead = cur;
        cur = next;
    }
    return reverseHead;

}

SNode_p CUtils::isLoopInList(SNode_p h) {

    SNode_p slow = h;
    SNode_p fast = h;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    return slow;

}

int CUtils::loopListLen(SNode_p h) {

    SNode_p encounter = isLoopInList(h);
    if (encounter == NULL)
        return 0;
    int len = 0;
    SNode_p slow = encounter;
    SNode_p fast = encounter;
    while (true) {
        slow = slow->next;
        fast = fast->next->next;
        len++;
        if (slow == fast)
            break;
    }

    return len;

}

SNode_p CUtils::loopListEntry(SNode_p h) {
    SNode_p encounter = isLoopInList(h);
    if (encounter == NULL)
        return NULL;

    SNode_p p1 = h;
    SNode_p p2 = encounter
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next
    }
    return p1;

}

void CUtils::sortListQuicker(SNode_p head) {
    if (head == NULL || head->next == NULL)
        return;
    sortListQuick(head, NULL);


}

void CUtils::sortListQuick(SNode_p head, SNode_p tail) {
    if (head == tail || head->next == tail)
        return;
    SNode_p mid = listPartition(head, tail);
    sortListQuick(head, mid);
    sortListQuick(mid->next, tail);
}

SNode_p CUtils::listPartition(SNode_p head, SNode_p tail) {

    int key = head->val;
    SNode_p p = head;
    SNode_p q = head->next;
    while (q != tail) {
        if (q->val > key) {
            q = p->next;
            CSort::swap(p->val, q->val);
        }
        q = q->next;
    }
    CSort::swap(head->val, p->val);
}

SNode_p CUtils::sortListQuickUnChange(SNode_p head) {
    if (head == NULL || head->next == NULL)
        return head;
    SNode pre(0);
    pre.next = head;
    sortListQuick(&pre, pre.next, NULL);
    return pre.next;
}

void CUtils::sortListQuick(SNode_p pre, SNode_p head, SNode_p tail) {
    if (head == tail && head->next == tail)
        return;
    SNode_p mid = listPartition(pre, head, tail);
    sortListQuick(pre, head, tail);
    sortListQuick(mid, mid->next, tail);

}

SNode_p CUtils::listPartition(SNode_p pre, SNode_p head, SNode_p tail) {
    SNode low(0);
    SNode_p lowCur = &low;
    SNode high(0);
    SNode_p highCur = &high;

    int key = head->val;
    SNode_p next = head->next;
    while (next != tail) {
        if (next->val < key) {
            lowCur->next = next;
            lowCur = next;
        } else {
            highCur->next = next;
            highCur = next;
        }
    }
    highCur->next = tail;
    head->next = high.next;
    lowCur->next = head;
    pre->next = low.next;
    return head;
}

STreeNode_p CUtils::reverseTree(STreeNode_p root) {
    if (root == NULL)
        return root;
    root->left = reverseTree(root->left);
    root->right = reverseTree(root->right);

    STreeNode_p temp
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;

}