//
// Created by csq on 2017/12/26.
//

#include "sort.h"

void CSort::sort(int *a, int n, ESortType type) {
    switch (type) {
        case ekSortType_Bubble:
            sortBubble(a, n);
            break;
        case ekSortType_Insert:
            sortInsert(a, n);
            break;
        case ekSortType_Select:
            sortSelect(a, n);
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


void CSort::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}