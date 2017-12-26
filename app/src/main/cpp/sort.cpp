//
// Created by csq on 2017/12/26.
//

#include "sort.h"


void CSort::sort(int *a, int n, ESortType type) {
    switch (type) {
        case ekSortType_Bubble:
            sortBubble(a, n);
            break;
        case ekSortType_Bubble_BiDirect:
            sortBubbleBiDirect(a, n);
            break;
        case ekSortType_Insert:
            sortInsert(a, n);
            break;
        case ekSortType_Insert_Dichotomy:
            sortInsertDichotomy(a, n);
            break;
        case ekSortType_Select:
            sortSelect(a, n);
            break;
        case ekSortType_Exchange:
            sortExchange(a, n);
            break;
        case ekSortType_Quick:
            sortInsert(a, n);
            break;
        case ekSortType_Merge:
            sortQuick(a, n);
            break;
        case ekSortType_MinHeap:
            sortMinHeap(a, n);
            break;
        case ekSortType_Shell:
            sortShell(a, n);
            break;
        case ekSortType_Radix:
            sortRadix(a, n);
            break;
        default:
            break;
    }
}

void CSort::sortBubble(int *a, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

}

void CSort::sortBubbleBiDirect(int *a, int n) {
    int low = 0;
    int high = n - 1;
    while (high > low) {
        for (int i = low; i < high; i++) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
        high--;
        for (int i = high; i > low; i--) {
            if (a[i - 1] > a[i])
                swap(a[i - 1], a[i]);
        }
        low++;
    }
}

void CSort::sortInsert(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int val = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > val) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = val;
    }
}
void CSort::sortInsertDichotomy(int *a, int n) {

}

void CSort::sortSelect(int *a, int n) {
    int minIdx;
    for (int i = 0; i < n - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}
void CSort::sortExchange(int *a, int n) {

}

void CSort::sortQuick(int *a, int n) {

}

void CSort::sortMinHeap(int *a, int n) {

}

void CSort::sortShell(int *a, int n) {

}

void CSort::sortRadix(int *a, int n) {

}


void CSort::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}